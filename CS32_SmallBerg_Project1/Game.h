//
//  Game.hpp
//  CS32_SmallBerg_Project1
//
//  Created by HaoYu Luo on 2023/1/18.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stdio.h>
class Arena;
class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    std::string takePlayerTurn();
};

#endif /* Game_hpp */
