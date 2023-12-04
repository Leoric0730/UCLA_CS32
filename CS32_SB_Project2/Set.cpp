//
//  Set.cpp
//  CS32_SB_Project2
//
//  Created by HaoYu Luo on 2023/1/31.
//

#include "Set.h"
using namespace std;

void Set::createEmpty(){
    m_size = 0;
    m_head = new Node;
    m_head -> m_next = m_head;
    m_head -> m_prev = m_head;
}

Set::Set(){
    createEmpty();
}

void Set::addToTail(const ItemType& val){
    Node* p = new Node;
    p -> m_value = val;
    
    p -> m_next = m_head;
    p -> m_prev = m_head -> m_prev;
    m_head -> m_prev -> m_next = p;
    m_head -> m_prev = p;

    m_size++;
}
void Set::doErase(Node*p) {
    p->m_prev->m_next = p->m_next;
    p->m_next->m_prev = p->m_prev;
    delete p;
    m_size--;
}

void Set::swap(Set& other){
    Node* temp;            //swap the headers would simply swap two sets
    temp = other.m_head;
    other.m_head = m_head;
    m_head = temp;
    
    int a = other.m_size;  // swap the size of 2 sets
    other.m_size = m_size;
    m_size = a;
}

Set::~Set(){
    while (m_head -> m_next != m_head){
        Node* p = m_head -> m_next;
        doErase(p);
    }
    delete m_head;
}

Set::Set(const Set& other){
    createEmpty();
    for (Node* q = other.m_head -> m_next; q!= other.m_head; q = q->m_next) {
        addToTail(q->m_value);
    }
}

Set& Set::operator=(const Set& rhs) {
    if (this != &rhs){
    Set temp(rhs);
    swap(temp);
}
    return *this;
}

Set::Node* Set::find(const ItemType& val) const{
    for (Node* p = m_head -> m_next; p!= m_head; p = p->m_next){
        if (p->m_value == val){return p;}
    }
    return m_head;
}

bool Set::insert(const ItemType& value){
    if (contains(value)){return false;}
    addToTail(value);
    return true;
}

bool Set::erase(const ItemType& value){
    if (find(value)!= m_head) {doErase(find(value)); return true;}
    return false;
}

int  Set::numOfGreater(const ItemType& val) const{
    int num = 0;
    for (Node* p = m_head->m_next; p!=m_head; p=p->m_next){  //Iterate through the linked-list to find
        if(val > p->m_value){num++;}                         //how many number is the input value greater
    }                                                        //than.
    return num;
}

bool Set::get(int pos, ItemType& value) const{             //Iterate through every node of the linked-list to
    if (pos<0 || pos >= m_size)                            //see if the output of numOfGreater of any m_value
    return false;                                          // is the same as pos, assign that m_value to
                                                           // value.
    for (Node* p = m_head->m_next; p!=m_head; p=p->m_next){
        if(numOfGreater(p->m_value)==pos) {value = p->m_value; return true;}
        }
    return false;
}

void unite(const Set& s1, const Set& s2, Set& result){
    const Set* sp = &s2;
    if (&result == &s1){          // check Aliasing cases: if result is s1
        if (&s1 == &s2)           // and s1 and s2 are the same, result already is what we desired
            return;
    }
    else if (&result == &s2) {    // if result is the same as s2, change sp, the set that we'll add
        if (&s1 == &s2) {return;}  // do nothing if result is the same as s2 and s1 is the same as s2
        sp = &s1;                          // to the result, to s1
    }
    else                          // cases where result is an arbitary Set other than s1 and s2.
        result = s1;
    for (int i=0; i<sp->size();i++){
        ItemType v;
        sp->get(i,v);
        result.insert(v);
    }
}



void butNot(const Set& s1, const Set& s2, Set& result){
    Set s2copy(s2);             //I didn't see the necessity to check alliasing, since result will be changed
    result = s1;                //into s1 anyway and elements of it will be subtracted base on s2.
    for (int i=0; i< s2copy.size(); i++){
        ItemType v;
        s2copy.get(i,v);
        result.erase(v);
    }
}

void Set::dump() const{
    for (Node* p = m_head -> m_next; p!=m_head; p = p->m_next){
        cout << p->m_value <<" ";
    }
    cout << endl;
}
