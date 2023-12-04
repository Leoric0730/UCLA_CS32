//
//  newSet.hpp
//  CS32_Smallberg_Project2
//
//  Created by HaoYu Luo on 2023/1/24.
//

#ifndef newSet_hpp
#define newSet_hpp

#include <stdio.h>

#include <string>
using ItemType = std::string;

const int DEFAULT_MAX_ITEMS = 160;

class Set
{
  public:
    Set(int capacity =DEFAULT_MAX_ITEMS);         // Create an empty set (i.e., one whose size() is 0).

    bool empty() const;  // Return true if the set is empty, otherwise false.

    int size() const;    // Return the number of items in the set.

    bool insert(const ItemType& value);
      // Insert value into the set if it is not already present.  Return
      // true if the value is actually inserted.  Leave the set unchanged
      // and return false if value is not inserted (perhaps because it
      // was already in the set or because the set has a fixed capacity and
      // is full).

    bool erase(const ItemType& value);
      // Remove the value from the set if it is present.  Return true if the
      // value was removed; otherwise, leave the set unchanged and
      // return false.
     
    bool contains(const ItemType& value) const;
      // Return true if the value is in the set, otherwise false.
     
    bool get(int i, ItemType& value) const;
      // If 0 <= i < size(), copy into value the item in the set that is
      // strictly greater than exactly i items in the set and return true.
      // Otherwise, leave value unchanged and return false.

    void swap(Set& other);
      // Exchange the contents of this set with the other one.
     
    ~Set();
    Set(const Set& other);
    Set& operator=(const Set& rhs);
    
    void dump() const;
private:
    int check (const ItemType& x) const{
        int num = 0;
        for (int i=0; i<m_size; i++){
            if (x>m_data[i]){num++;}
        }
        
        return num;
    }
    ItemType* m_data;
    int m_size;
    int m_capacity;
};

#endif /* newSet_hpp */
