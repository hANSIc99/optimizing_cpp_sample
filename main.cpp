#include <iostream>
#include "MyType.h"
#include "Carrier.h"


int main(int argc, char* argv[]){
    std::cout << "Hello World" << std::endl;

    Carrier carrier_instance(MyType("opencource.com")); 
}
