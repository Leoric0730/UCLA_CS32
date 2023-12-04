//
//  Rabbit.hpp
//  CS32_SmallBerg_Project1
//
//  Created by HaoYu Luo on 2023/1/18.
//

#ifndef Rabbit_hpp
#define Rabbit_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>

#include "globals.h"
class Arena;
class Rabbit
{
  public:
    Rabbit(Arena* ap, int r, int c);
    int  row() const;
    int  col() const;
    bool isDead() const;
      // Mutators
    void move();

  private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_health;
    int    m_idleTurnsRemaining;
};


#endif /* Rabbit_hpp */
