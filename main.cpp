#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cmath>
#include "MyType.h"
#include "MyObject.h"

#define SLEEP_TIME 10

void case_1(std::vector<double> &container){

    /* Not optimized; invokes copy constructor */
    MyType<double> type_1(container);
    MyObject<MyType<double> > object_1(type_1); 
    object_1.m_mytype.print();

}
void case_2(std::vector<double> &container){
    /* Optimized: Invokes move constructor */
    MyObject<MyType<double> >  object_2(container);
    object_2.m_mytype.print();
}

void case_3(){

    /* Optimized: Invokes move constructor */
    MyType<double> type_1({1.2, 3.4, 5.6});
    MyObject<MyType<double> >  object_2(std::move(type_1));
    object_2.m_mytype.print();
    /* Dangerous: std::move destroys the object */
    type_1.print();
}
void case_4(std::vector<double> &container){
    
    int i;
    std::vector<MyObject<MyType<double> > > my_objects;

    for(i=0; i < 1000 ; i++){
        /* Not optimized; invokes copy constructor */
        MyType<double> type_1(container);
        MyObject<MyType<double> > object_1(type_1);
        my_objects.push_back(object_1); 
    }

}

void case_5(std::vector<double> &container){
    
    int i;
    std::vector<MyObject<MyType<double> > > my_objects;

    for(i=0; i < 1000; i++){

        /* Optimized: Invokes move constructor */

        MyType<double> type_1(container);
        MyObject<MyType<double> > object_1(std::move(type_1));
        my_objects.push_back(std::move(object_1)); 
    }

}


int main(int argc, char* argv[]){

    int i;
    std::vector<double> container;

    std::cout << "Application started..." << std::endl;
    std::cout << "Process Id: " << ::getpid() << std::endl; 

    for(i=0; i < 0x7FFF; i++){

        double nmbr = (double)(std::rand() + 1) / (double)(1/3); 
        container.push_back(nmbr);
    }

    auto start = std::chrono::high_resolution_clock::now();

#ifdef OPT1
    std::cout << "Compiled with OPT1" << std::endl;
    case_1(container);
#elif OPT2
    std::cout << "Compiled with OPT2" << std::endl;
    case_2(container);
#elif OPT3
    std::cout << "Compiled with OPT3" << std::endl;
    case_3();
#elif OPT4
    std::cout << "Compiled with OPT4" << std::endl;
    int cnt = 0;
    std::chrono::duration<double, std::milli> sum(0);
    while(true){
        auto start = std::chrono::high_resolution_clock::now();
        case_4(container);
        cnt++;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        sum += duration;
        std::cout << "Average time: " << std::round(sum.count() / cnt)  << "ms - Last execution took: " << \
            duration.count() << "um" << std::endl;
    }
#elif OPT5
    std::cout << "Compiled with OPT5" << std::endl;
    int cnt = 0;
    std::chrono::duration<double, std::milli> sum(0);
    while(true){
        auto start = std::chrono::high_resolution_clock::now();
        case_5(container);
        cnt++;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        sum += duration;
        std::cout << "Average time: " << std::round(sum.count() / cnt)  << "ms - Last execution took: " << \
            duration.count() << "um" << std::endl;

    }
#else
    std::cout << "Run 'make' with option argument OPT{n}, n={1,2,3} < " << std::endl;
    std::cout << "E.g. 'make CFLAGS=-DOPT2" << std::endl;
#endif

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Execution took " << duration.count() << " us" << std::endl;
}
