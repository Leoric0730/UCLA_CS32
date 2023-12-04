//
//  newSet.cpp
//  CS32_Smallberg_Project2
//
//  Created by HaoYu Luo on 2023/1/24.
//

#include "newSet.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Set::swap(Set& other){
    ItemType* temp = m_data;  //Swap pointer
    m_data = other.m_data;
    other.m_data = temp;
    
    int tempSize = m_size;  //Swap size
    m_size = other.m_size;
    other.m_size = tempSize;

    int tempCapacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tempCapacity;
}

Set::Set(int num):m_size(0),m_capacity(num) {
    if (num < 0) {
        cout <<"capacity must be valid"<<endl;
        exit(1);
    }
        m_data = new ItemType[m_capacity];
    }

Set::Set(const Set& other):m_size(other.m_size),m_capacity(other.m_capacity){
    m_data = new ItemType[m_capacity];
    for (int i=0; i<m_size; i++){
        m_data[i] = other.m_data[i];
    }
}

Set& Set::operator=(const Set& rhs){
    if (this != &rhs) {
        Set temp(rhs);
        swap(temp);
    }
    return *this; }
 
Set::~Set(){
    delete [] m_data;
}

bool Set::empty() const {
    if (m_size == 0) return true;
    return false;
}

int Set::size() const{
    return m_size;
}

bool Set::contains(const ItemType& value) const{
    for(int i=0; i<m_size; i++){
        if(m_data[i] == value) return true;
    }
    return false;
}

bool Set::insert(const ItemType& value){
    if(m_size < DEFAULT_MAX_ITEMS && !contains(value)){
        m_data[m_size] = value;
        m_size++;
        return true;
    }
    return false;
}

bool Set::erase(const ItemType& value){
    for (int i=0;i<m_size; i++){
        if(m_data[i] == value){
           m_data[i] = m_data[m_size-1];
            m_size--;
            return true;
        };
    }
    return false;
}



bool Set::get(int i, ItemType& value) const {
    if (i>=0 && i<m_size){
        for (int j=0; j<m_size; j++){
            int k = check(m_data[j]);
            if (k==i)
            {value = m_data[j];
                return true;}
                }
    }
    return false;
}

