//
//  main.cpp
//  CS32_SB_HW3P3
//
//  Created by HaoYu Luo on 2023/2/14.
//

#include <iostream>
using namespace std;


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    if (sr < 0  ||  sr >= nRows  ||  sc < 0  || sc >= nCols  ||
            er < 0  ||  er >= nRows  ||  ec < 0  || ec >= nCols  ||
            maze[sr][sc] != '.'  ||  maze[er][ec] != '.')
           return false;
    if (sr == er && sc == ec) {return true;}
    maze[sr][sc] = 'o';
    if (maze[sr+1][sc] == '.' && pathExists(maze, nRows, nCols, sr+1, sc, er, ec)) {return true;}
    if (maze[sr-1][sc] == '.' && pathExists(maze, nRows, nCols, sr-1, sc, er, ec)) {return true;}
    if (maze[sr][sc+1] == '.' && pathExists(maze, nRows, nCols, sr, sc+1, er, ec)) {return true;}
    if (maze[sr][sc-1] == '.' && pathExists(maze, nRows, nCols, sr, sc-1, er, ec)) {return true;}
    return false;
}


