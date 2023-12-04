//
//  History.cpp
//  CS32_SmallBerg_Project1
//
//  Created by HaoYu Luo on 2023/1/18.
//

#include "History.h"
#include <iostream>
#include <cstdlib>
using namespace std;

History::History(int nRows, int nCols){
    m_row = nRows;
    m_col = nCols;
    for (int i=0; i<nRows;i++)
        for (int j=0; j <nCols; j++)
        {historyGrid[i][j] = '.';}
}

bool History::record(int r, int c) {
    if (r < 1 || r > m_row || c < 1 || c > m_col)
    return false;
    
    else {
        char& gridChar = historyGrid[r-1][c-1];
        switch(gridChar){
            case '.': gridChar = 'A'; break;
            case 'A': gridChar = 'B'; break;
            case 'Z': break;
            default: gridChar++; break;
        }
    }
    return true;
}

void History::display() const {
    clearScreen();
    for (int i=0; i< m_row; i++) {
        for (int j=0; j< m_col; j++)
        {cout <<historyGrid[i][j];}
        cout<<endl;
    }
}

