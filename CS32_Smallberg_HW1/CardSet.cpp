//
//  CardSet.cpp
//  CS32_Smallberg_Project2
//
//  Created by HaoYu Luo on 2023/1/24.
//

#include "CardSet.h"
#include "iostream"
using namespace std;

CardSet::CardSet(){}

bool CardSet::add(ItemType cardNumber) {
    if (m_cards.insert(cardNumber) == true) {return true;}
return false;
}

int CardSet::size() const {
    return m_cards.size();
}

void CardSet::print() const{
    for (int i=0 ; i<m_cards.size(); i++){
        ItemType x;
        m_cards.get(i,x);
        cout << x << endl;
    }
    
}
