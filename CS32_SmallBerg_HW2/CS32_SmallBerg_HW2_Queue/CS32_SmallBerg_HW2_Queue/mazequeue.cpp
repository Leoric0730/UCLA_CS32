

#include <iostream>
#include <queue>
#include <string>
using namespace std;

const char WALL = 'X';
const char OPEN = '.';
const char SEEN = 'o';

class Coord
        {
          public:
            Coord(int r, int c) : m_row(r), m_col(c) {}
            int r() const { return m_row; }
            int c() const { return m_col; }
          private:
            int m_row;
            int m_col;
        };

void explore(string maze[], queue<Coord>& toDo, int r, int c){
    if (maze[r][c] == OPEN){
        toDo.push(Coord(r,c));
        maze[r][c] = SEEN;
    }
}

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    if (sr < 0||sr > nRows-1||sc < 0|| sc > nCols-1||er < 0||er > nRows-1||ec < 0|| ec > nCols-1||maze[sr][sc] != OPEN||maze[er][ec] != OPEN)
    {return false;}
    queue<Coord>toDo;
    explore(maze,toDo,sr,sc);
    while (!toDo.empty()){
        Coord curr = toDo.front();
        toDo.pop();
        const int cr = curr.r();
        const int cc = curr.c();
        if (cr == er && cc == ec) {return true;}
        explore(maze, toDo, cr-1, cc); //north
        explore(maze, toDo, cr+1, cc); //south
        explore(maze, toDo, cr, cc-1); //west
        explore(maze, toDo, cr, cc+1); //east
    }
    return false;
}


int main() {
    
    string maze[10] = {
                    "XXXXXXXXXX",
                    "X..X...X.X",
                    "X.XXXX.X.X",
                    "X.X.X..X.X",
                    "X...X.XX.X",
                    "XXX......X",
                    "X.X.XXXX.X",
                    "X.XXX....X",
                    "X...X..X.X",
                    "XXXXXXXXXX"
                };
            
                if (pathExists(maze, 10,10, 5,3, 8,8))
                    cout << "Solvable!" << endl;
                else
                    cout << "Out of luck!" << endl;
    
    
    return 0;
}
