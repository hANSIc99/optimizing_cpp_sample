#ifndef CARRIER_H
#define CARRIER_H

#include "MyType.h"

template <class T>
class MyObject{
public:
    
    MyObject(const T& mytype):
        m_mytype(mytype){
    }

    MyObject(T&& mytype):
        m_mytype(std::move(mytype)){
    }

    T m_mytype;
};

#endif
