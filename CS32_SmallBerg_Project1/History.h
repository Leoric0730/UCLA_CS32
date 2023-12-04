//
//  History.hpp
//  CS32_SmallBerg_Project1
//
//  Created by HaoYu Luo on 2023/1/18.
//

#ifndef History_hpp
#define History_hpp
#include "globals.h"

class History
    {
      public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
    private:
        int m_row;
        int m_col;
        char historyGrid[MAXROWS][MAXCOLS];
    };
#endif /* History_hpp */
