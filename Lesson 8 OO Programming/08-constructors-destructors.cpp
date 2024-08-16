#include <iostream>

/*
! Constructors
? Special member method
? Invoked(called) during object creation
? Useful for initialization
? Same name as the class
? No return type is specified
? Can be overloaded

class Player
{
private:
  std::string name;
  int health;
  int xp;
public:
  ! Overloaded Constructors(functions with the same name but different arguments)
  Player();
  Player(std::string name);
  Player(std::string name, int health, int xp);
};

! Destructors
? Special member method
? Same name as the class proceeded with a tidle (~)
? Invoked(called) automatically when an object is destroyed
? No return type and no parameters
? Only 1 destructor is allowed per class - cannot be overloaded!
? Useful to release memory and other resources


class Player
{
private:
  std::string name;
  int health;
  int xp;
public:
  Player();
  Player(std::string name);
  Player(std::string name, int health, int xp);
  ! Destructor
  ~Player();
};

{
  Player slayer;
  Player alex {"Alex", 100, 7};
  Player hero {"Hero"};
  Player villain {"Villain"};
  ! 4 destructors called when they go out of scope
}
  
Player *enemy = new Player("Enemy", 1000, 0);
delete enemy; //! destructor called

! Default Constructor
? Does not expect any arguments
  * Also called the no args constructor
? If you write no constructors at all for a class
  * C++ will generate a Default Constructor that does nothing
? Called when you instantiate a new object with no arguments
! We are only getting the default constructor as long as we don't provide any other constructor!

Player alex;
Player *enemy = new Player;

! Overloading Constructors
? Classes can have as many constructors as necessary
? Each must have a unique signature
? Default constructor is no longer compiled-generated once another constructor is declared
*/

class Account
{
private:
  std::string name;
  double balance;
public:
  Account();
  Account(std::string _name);
  Account(std::string _name, double _balance);
};

Account::Account() {
  name = "None";
  balance = 0;
}

Account::Account(std::string _name) {
  name = _name;
}

Account::Account(std::string _name, double _balance) {
  name = _name;
  balance = _balance;
}

//* Examples:

class Player
{
private:
  std::string name;
  int health;
  int xp;
public:
  void setName(std::string n) {
    name = n;
  }
  // Overloaded Constructors
  Player() {
    std::cout << "No args constructor called" << std::endl;
  }
  Player(std::string name) {
    std::cout << "String arg constructor called" << std::endl;
  }
  Player(std::string name, int health, int xp) {
    std::cout << "Three args constructor called" << std::endl;
  }
  ~Player() {
    std::cout << "Destructor called for " << name << std::endl;
  }
};

int main() {
  {
  Player slayer;
  slayer.setName("Slayer");
  } // destructor called when out of scope  

  {
  Player alex;
  alex.setName("Alex");
  Player hero("Hero");
  hero.setName("Hero");
  Player villain("Villain", 100, 12);
  villain.setName("Villain");
  } // destructor called when out of scope

  Player *enemy = new Player;
  enemy->setName("Enemy");

  Player *levelBoss = new Player("Level Boss", 1000, 300);
  levelBoss->setName("Level Boss");

  delete enemy;
  delete levelBoss;

  return 0;
}