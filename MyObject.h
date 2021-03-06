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

    };

    /* Contructor with move */

    MyObject(T&& mytype):
        m_mytype(std::move(mytype)){

    };

    /* Copy constructor */
    MyObject(const MyObject& other):
        m_mytype(other.m_mytype){

    };


    /* Move contructor */
    MyObject(MyObject&& other):
        m_mytype(std::move(other.m_mytype)){

    }


    T m_mytype;
};

#endif
