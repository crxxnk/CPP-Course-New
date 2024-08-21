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
*/

//* Example:

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

/*
! Overloading Constructors
? Classes can have as many constructors as necessary
? Each must have a unique signature
? Default constructor is no longer compiled-generated once another constructor is declared
*/

//* Example:
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

/*
! Constructor Initialization Lists
? So far, all data member values have been set in the constructor body

? Constructor initialization lists
  * are more efficient
  * initialization list immediately follows the parameter list
  * initializes the data members as the object is created!
  * order of initialization is the order of declaration in the class
*/

//* Example:

class Dog
{
private:
  int age;
  std::string name;
public:
  Dog();
  Dog(std::string name, int age);
  ~Dog();
};

// Initializes name to None and age to 0 (they are initialized before the body is executed)
Dog::Dog(): name {"None"}, age{0} {
  
}
// When an object is created, it initializes the function parameters to the class members, useful for name conflict
Dog::Dog(std::string name, int age): name{name}, age{age} {
  std::cout << "A dog was just born!" << std::endl;
}

Dog::~Dog() {
  std::cout << "A dog just died!" << std::endl;
}

/*
! Delegating Constructors
? Often the code for constructors is very similar
? Duplicated code can lead to errors
? C++ allows delegating constructors
  * code for one constructor can call another in the initialization list
  * avoids duplicating code
*/

//* Example:

class Animal
{
private:
  std::string name;
  int age;
  float weight;
public:
  Animal();
  Animal(std::string name);
  Animal(std::string name, int age, float weight);
};

/* Before:
Animal::Animal(): name{"None"}, age{0}, weight{0.0f} {

}

Animal::Animal(std::string name): name{name}, age{0}, weight{0.0f} {

}

Animal::Animal(std::string name, int age, float weight): name{name}, age{age}, weight{weight} {

}
*/

//! We don't need to duplicate the initialization list, instead we do this:

Animal::Animal(std::string name, int age, float weight): name{name}, age{age}, weight{weight} {

}

Animal::Animal(): Animal {"None", 0, 0.0f} {

}

Animal::Animal(std::string name): Animal{name, 0, 0.0f} {

}

/*
! Default Construct Parameters
? Can often simplify our code and reduce the number of overloaded constructors
? Same rules apply as we learned with non-member functions
*/

class Enemies
{
private:
  std::string name;
  int health;
  int xp;
public:
  // Constructor with default parameter values
  Enemies(std::string name = "None", int health = 0, int xp = 0);
  void displayEnemy()
  {
    std::cout << name << ", " << health << ", " << xp << std::endl;
  }
};

Enemies::Enemies(std::string name, int health, int xp): name(name), health(health), xp(xp){}

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

  Dog Rush("Rush", 1);
  Dog* Lilly = new Dog("Lilly", 15);
  delete Lilly;

  Animal* bird = new Animal("Bird", 4, 0.7);
  delete bird;

  Enemies empty; // "None", 0, 0
  Enemies goblin {"Goblin"}; // "Goblin", 0, 0
  Enemies gorlockTheDestroyer {"Gorlock", 60, 7000}; // "Gorlock", 60, 7000
  Enemies batman {"Batman", 100}; // "Batman", 100, 0

  gorlockTheDestroyer.displayEnemy();

  return 0;
}