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
        std::cout << "MyType::MyType() contructor called." << std::endl;

    }

    /* Destructor */
    ~MyType(){
        delete m_data;
    }

    /* Copy constructor */
    MyType(const MyType& other){

        if(other.m_data){
            m_data = new std::vector<T>(*other.m_data);
        } else {
            m_data = NULL;
        }
        std::cout << "MyType::MyType(const MyType&) copy constructor called" << \
            std::endl;
    }

    /* Move constructor */

    MyType(MyType&& other){

        m_data = other.m_data;
        other.m_data = NULL;
        std::cout << "MyType::MyType(MyType&& other) move constructor called" << \
            std::endl;

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

        std::cout << "MyType::MyType& operator=(const MyType& other) copy \
            assignmend called" << std::endl;
    }

    /* Move assignment */

    MyType& operator=(MyType&& other){
        if(this != &other){
            delete m_data;
            m_data = other.m_data;
            other.m_data = NULL;
        }
        return *this;

        std::cout << "MyType::MyType& operator=(MyType&& other) move assignment \
            called" << std::endl;
    }



    void print(){
        std::cout << "MyType::m_data contains " << m_data->size() << \
            " elements" << std::endl; 
    }
private:
    std::vector<T> *m_data;

};


#endif
