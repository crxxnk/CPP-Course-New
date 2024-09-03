//Act like this file is player.cpp
#include <iostream>
#include "include/player.h"

using namespace std;

/*
! Static Class Members
? Class data members can be declared as static
  * A single data member that belongs to the class, not the objects
  * Useful to store class-wide information

? Class functions can be declared as static
  * Independent of any objects
  * Can be called using the class name
*/

//* Example:
//! Class is in player.h

int Player::players = 0;

int Player::getPlayers(){
  return players;
}

Player::Player(string name, int health, int xp){
  this->name = name;
  this->health = health;
  this->xp = xp;
  players++;
}

Player::~Player(){
  players--;
}

void displayActivePlayers(){
  cout << "Number of active players: " << Player::getPlayers() << endl;
}

int main()
{
  Player cock("cock", 1, 1);
  displayActivePlayers();

  return 0;
}