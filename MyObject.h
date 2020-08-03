#ifndef CARRIER_H
#define CARRIER_H

#include <vector>
#include "MyType.h"

template <class T>
class MyObject{
public:
    

    /* Default constructor */

    MyObject(const T& mytype):
        m_mytype(mytype){

        //std::cout << "MyObject::MyObject(const T& mytype) constructor called" << \
        //    std::endl;

    };

    /* Contructor with move */

    MyObject(T&& mytype):
        m_mytype(std::move(mytype)){

        //std::cout << "MyObject::MyObject(T&& mytype) constructor with move called" << \
        //    std::endl;

    };

    /* Copy constructor */
    MyObject(const MyObject& other):
        m_mytype(other.m_mytype){

        //std::cout << "MyObject::MyObject(T&& mytype) copy constructor called" << \
        //    std::endl;

    };


    /* Move contructor */
    MyObject(MyObject&& other):
        m_mytype(std::move(other.m_mytype)){

        //std::cout << "MyObject::MyObject(T&& mytype) move constructor called" << \
        //    std::endl;

    }


    T m_mytype;
};

#endif
