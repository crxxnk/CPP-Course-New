#pragma once
#include <string>

class Player
{
private:
  static int players;
  std::string name;
  int health;
  int xp;
public: 
  static int getPlayers();
  Player(std::string name, int health, int xp);
  ~Player();
};
