//
//  CardSet.hpp
//  CS32_Smallberg_Project2
//
//  Created by HaoYu Luo on 2023/1/24.
//

#ifndef CardSet_hpp
#define CardSet_hpp

#include "Set.h"
#include <stdio.h>

class CardSet
    {
      public:
        CardSet();          // Create an empty card set.

        bool add(ItemType cardNumber);
          // Add a card number to the CardSet.  Return true if and only if the
          // card number was actually added.

        int size() const;  // Return the number of card numbers in the CardSet.

        void print() const;
          // Write to cout every card number in the CardSet exactly once, one
          // per line.  Write no other text.

      private:
        Set m_cards;
    };

#endif /* CardSet_hpp */
