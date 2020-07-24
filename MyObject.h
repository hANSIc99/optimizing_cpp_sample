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

    /* Copy assignment */
    MyObject& operator=(const MyObject& other){
        if(this != &other){
            m_mytype = other.m_mytype;
        }
        return *this;
    };

    /* Move contructor */
    MyObject(MyObject&& other):
        m_mytype(std::move(other.m_mytype)){
    }

    /* Move assignment */

    MyObject& operator=(MyObject&& other){
        if(this != &other){
            m_mytype(std::move(other.m_mytype));
        }
        return *this;
    }

    T m_mytype;
};

#endif
