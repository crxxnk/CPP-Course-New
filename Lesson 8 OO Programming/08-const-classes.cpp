#include <iostream>

using namespace std;

/*
! Using const with classes
? Pass arguments to class member methods as const
? We can also create const objects
? What happens if we call member functions on const objects?
? const-correctness

! Creating a const object
* villain is a const object so its attributes cannot change
  const Player villain {"Villain", 100, 55};
? What happens if we call member functions on const objects?
  villain.setName("Nice guy"); //! ERROR
  std::cout << villain.getName() << std::endl; //! ERROR

* Example
  void displayPlayerName(const Player &p) {
    cout << "Player Name: " << p.getName() << endl;
  }

  displayPlayerName(villain); //! ERROR

  ! SOLUTION

  class Player
  {
  private:
    ...
  public:
    std::string getName() const;
  };
*/

//* Example:

class Player
{
private:
  string name;
  int health;
  int xp;
public:
  string getName() const;
  void setName(string name);
  Player();
  Player(string name);
  Player(string name, int health, int xp);
};

Player::Player(): name("None"), health(0), xp(0) {}

string Player::getName() const {
  return name;  
}

void Player::setName(string name) {
  this->name = name;
}

int main()
{

  return 0;
}