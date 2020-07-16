#ifndef MYTYPE_H
#define MYTYPE_H

#include <cstdio>
#include <cstring>
#include <stdio.h>

class MyType
{
public:

    /* Default Contructor */
    MyType() = default;

    /* User defined Constructor */
    MyType(const char* name){

        m_dataSize   = strlen(name);
        m_data       = new char[m_dataSize];

        std::memcpy(m_data, name, m_dataSize);

        printf("MyType::MyType() contructor called, m_data: %p\n", m_data);
    }

    /* Copy Constructor */
    MyType(const MyType& other){

        m_dataSize   = other.m_dataSize;
        m_data       = new char[m_dataSize];

        std::memcpy(m_data, other.m_data, m_dataSize);

        printf("MyType::MyType(const MyType&) copy constructor called,\
                m_data: %p\n", m_data);
    }

    /* Move Constructor */
    MyType(MyType&& other) noexcept {

        m_dataSize   = other.m_dataSize;
        m_data       = other.m_data;

        other.m_dataSize = 0;
        other.m_data     = nullptr;

        printf("MyType::MyType(MyType&& other) move constructor called\n");
    }


    ~MyType(){
        delete m_data;
        printf("MyType::~MyType destructor called, m_data: %p\n", m_data);
     }

    void print(){
        printf("%s\n", m_data);
    }

private:
    char* m_data;
    std::size_t m_dataSize;
};

#endif
