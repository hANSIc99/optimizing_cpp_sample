#ifndef CARRIER_H
#define CARRIER_H

#include "MyType.h"

class Carrier{
public:
    
    Carrier(const MyType& mytype):
        m_mytype(mytype){
    }

private:
    MyType m_mytype;


};

#endif
