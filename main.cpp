#include <iostream>
#include "MyType.h"
#include "MyObject.h"


int main(int argc, char* argv[]){
    std::cout << "Hello World" << std::endl;

    /* The correct type in  constructor is automatically choosen */
#if 0
    /* Not optimized */
    MyType   type_1("1. opensource.com");
    MyObject object_1(type_1); 
    object_1.printInnerData();
#endif

    /* Also not optimized */
    MyObject object_2(MyType("2. opensource.com"));
    object_2.printInnerData();

}
