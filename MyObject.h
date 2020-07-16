#ifndef CARRIER_H
#define CARRIER_H

#include "MyType.h"

class MyObject{
public:
    
    MyObject(const MyType& mytype):
        m_mytype(mytype){
    }

    MyObject(MyType&& mytype):
        m_mytype(std::move(mytype)){
    }

    void printInnerData(){
        m_mytype.print();
    }

private:
    MyType m_mytype;

};

#endif
