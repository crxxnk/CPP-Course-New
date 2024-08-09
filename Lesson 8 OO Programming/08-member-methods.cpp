#include <iostream>
#include <include/dog.h>

using namespace std;

/*
! Implementing Member Methods
? Very similar to how we implemented functions
? Member methods have access to member attributes
  * So you don't need to pass them as arguments!
? Can be implemented inside the class declaration
  * Implicitly inline
? Can be implemented outside the class declaration
  * Need to use Class_name::method_name
? Can seperate specification from implementation
  * .h file for the class declaration
  * .cpp file for the class implementation
*/

//* Inside the class declaration:

class Account {
private:
  double balance;
public:
  void setBalance(double bal) {
    balance = bal;
  }
  double getBalance() {
    return balance;
  }
};

//* Outside the class declaration:

class Player {
private:
  int health;
public:
//! We can easily define the function by right clicking and pressing Create Declaration / Definition
  void setHealth(int h);
  int getHealth();
};

void Player::setHealth(int h) { // We write the type of the functiom, the class that we get the function from, ::functionName
  health = h;
}

int Player::getHealth() {
  return health;
}

int main() {

  return 0;
}