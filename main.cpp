#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "MyType.h"
#include "MyObject.h"

#define SLEEP_TIME 10

void case_1(){

    /* Not optimized; invokes copy constructor */
    MyType<double> type_1({1.2, 3.4, 5.6});
    MyObject<MyType<double> > object_1(type_1); 
    object_1.m_mytype.print();

}
void case_2(){
    /* Optimized: Invokes move constructor */
    MyObject<MyType<double> >  object_2(MyType<double>({2.4, 5.6, 7.8, 8.0}));
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

#if 0
void case_3(){
    int cnt = 0;
    std::vector<double> container;

    while(cnt < 30){
        cnt++;
        double nmbr = (double)(std::rand() + 1); 
        nmbr /= 333.3333; 
        container.push_back(nmbr);
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }
    while(container.size() > 0){
        container.pop_back();
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }
}
#endif

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "Program takes exactly one argument." << std::endl;
        std::cout << "Enter a number between 1 and 5" << std::endl;
        exit(-1);
    }
    std::cout << "Application started..." << std::endl;
    std::cout << "Process Id: " << ::getpid() << std::endl; 

    switch(*argv[1]){
        case '1':
            case_1();
           break;
        case '2':
            case_2();
            break;
        case '3':
            case_3();
            break;
        default:
            std::cout << "Illegal option, enter a number from 1 - 5" << std::endl;
    }

}
