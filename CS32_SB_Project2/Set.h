//
//  Set.hpp
//  CS32_SB_Project2
//
//  Created by HaoYu Luo on 2023/1/31.
//

#ifndef Set_h
#define Set_h

#include <stdio.h>
#include <string>
#include <iostream>
using ItemType = std::string;

class Set
{
  public:
    Set();
    ~Set();
    Set(const Set& other);
    Set& operator=(const Set& rhs);
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
    void dump() const;
    
 private:
    int m_size;
    struct Node {
        ItemType m_value;
        Node* m_next;
        Node* m_prev;
    };
    Node* m_head;
    void doErase (Node* p);
    Node* find(const ItemType& val) const; //return the pointer to the node that contains that value
                                     // return m_head if not find
    void createEmpty();
    void addToTail(const ItemType& val);
    int  numOfGreater(const ItemType& val) const;
};

void unite(const Set& s1, const Set& s2, Set& result);
void butNot(const Set& s1, const Set& s2, Set& result);

//inline
inline
int Set::size() const {
    return m_size;
}

inline
bool Set::empty() const {
    return m_size == 0;
}

inline
bool Set::contains(const ItemType& value) const {
    return find(value) != m_head;
}

#endif /* Set_hpp */
