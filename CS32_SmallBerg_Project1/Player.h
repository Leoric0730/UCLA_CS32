//
//  Player.hpp
//  CS32_SmallBerg_Project1
//
//  Created by HaoYu Luo on 2023/1/18.
//

#ifndef Player_hpp
#define Player_hpp


#include <string>


class Arena;
class Player
{
  public:
    Player(Arena* ap, int r, int c);
    int  row() const;
    int  col() const;
    bool isDead() const;
      // Mutators
    std::string dropPoisonedCarrot();
    std::string move(int dir);
    void   setDead();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};


#endif /* Player_hpp */
