#include <iostream>

using namespace std;

/*
! Friends of a Class
? Friend
  * A function or class that has access to private class member
  * And that function of or class is NOT a member of the class it is accessing
? Function
  * Can be regular non-member functions
  * Can be member methods of another class
? Class
  * Another class can have access to private class members

? Friendship must be granted NOT taken
  * Declared explicitly in the class that is granting friendship
  * Declared in the function prototype with the keyword friend
? Friendship is not symmetric
  * Must be explicitly granted
    * if A is a friend of B
    * B is NOT a friend of A
? Friendship is not transitive
  * Must be explicitly granted
    * if A is a friend of B AND
    * B is a friend of C
    * then A is not a friend of C
*/

//* Example:

class Player
{
  friend void displayPlayer(Player &p); // Has access to everything in the class
  friend class random;
  string name;
  int health;
  int xp;
};

class random
{
public:
  void displayPlayer(Player &p){
    cout << "Player's name: " << p.name << endl;
    cout << "Player's Health: " << p.health << endl;
    cout << "Player's XP: " << p.xp << endl;
  }
};

void displayPlayer(Player &p){
  cout << "Player's Name: " << p.name << endl;
  cout << "Player's Health: " << p.health << endl;
  cout << "Player's XP: " << p.xp << endl;
}

int main()
{

  return 0;
}