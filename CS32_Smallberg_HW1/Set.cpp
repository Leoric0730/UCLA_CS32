//
//  Set.cpp
//  CS32_Smallberg_Project2
//
//  Created by HaoYu Luo on 2023/1/24.
//

#include "Set.h"
using namespace std;

Set::Set():m_size(0){}

bool Set::empty() const {
    if (m_size == 0) return true;
    return false;
}

int Set::size() const{
    return m_size;
}

bool Set::contains(const ItemType& value) const{
    for(int i=0; i<m_size; i++){
        if(m_list[i] == value) return true;
    }
    return false;
}

bool Set::insert(const ItemType& value){
    if(m_size < DEFAULT_MAX_ITEMS && !contains(value)){
        m_list[m_size] = value;
        m_size++;
        return true;
    }
    return false;
}

bool Set::erase(const ItemType& value){
    for (int i=0;i<m_size; i++){
        if(m_list[i] == value){
           m_list[i] = m_list[m_size-1];
            m_size--;
            return true;
        };
    }
    return false;
}



bool Set::get(int i, ItemType& value) const {
    if (i>=0 && i<m_size){
        for (int j=0; j<m_size; j++){
            int k = check(m_list[j]);
            if (k==i)
            {value = m_list[j];
                return true;}
                }
    }
    return false;
}

void Set::swap(Set& other){
    Set temp(*this);
    *this = other;
    other = temp;
}

void Set::dump() const{
    
}
