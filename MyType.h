#ifndef MYTYPE_H
#define MYTYPE_H

#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

template <class T>
class MyType
{
public:

    typedef T type;
    T dummy;

    /* Default constructor */
    MyType() = default;

    /* User constructor */
    MyType(const std::vector<double> data){

        m_data = new std::vector<T>(data);

#ifdef PRINT
        std::cout << "MyType::MyType() contructor called." << std::endl;
#endif

    }

    /* Destructor */
    ~MyType(){
        delete m_data;

#ifdef PRINT
        std::cout << "MyType::~MyType() destructor called." << std::endl;
#endif
    }

    /* Copy constructor */
    MyType(const MyType& other){

        if(other.m_data){
            m_data = new std::vector<T>(*other.m_data);
        } else {
            m_data = NULL;
        }

#ifdef PRINT
        std::cout << "MyType::MyType(const MyType&) copy constructor called" << \
            std::endl;
#endif
    }

    /* Move constructor */

    MyType(MyType&& other){

        m_data = other.m_data;
        other.m_data = NULL;

#ifdef PRINT
        std::cout << "MyType::MyType(MyType&& other) move constructor called" << \
            std::endl;
#endif
    }

    /* Copy assignment */

    MyType& operator=(const MyType& other){

        if(this != &other){
            delete m_data;
            if(other.m_data){
                m_data = new std::vector<T>(*other.m_data);
            } else {
                m_data = NULL;
            }
        }
        return *this;

#ifdef PRINT
        std::cout << "MyType::MyType& operator=(const MyType& other) copy \
            assignmend called" << std::endl;
#endif
    }

    /* Move assignment */

    MyType& operator=(MyType&& other){
        if(this != &other){
            delete m_data;
            m_data = other.m_data;
            other.m_data = NULL;
        }
        return *this;

#ifdef PRINT
        std::cout << "MyType::MyType& operator=(MyType&& other) move assignment \
            called" << std::endl;
#endif
    }



    void print(){
        std::cout << "MyType::m_data contains " << m_data->size() << \
            " elements" << std::endl; 
    }
private:
    std::vector<T> *m_data;

};


#endif
