#include <iostream>

/*
! Copy constructor
? When objects are copied, C++ must create a new object from an existing object
? When is a copy of an object made?
  * passing object value as a parameter
  * returning an object from a function by value
  * constructing one object based on another of the same class
? C++ must have a way of accomplishing this so it provides a compiler-defined copy constructor if you don't

? If you don't provide your own way of copying objects by value, then the compiler provides a default way of copying objects
? Copies the values of each data member to the new object
  * default memberwise copy
? Perfectly fine in many cases
? Beware if you have a pointer data member
  * Pointer will be copied
  * Not what it is pointing to
  * Shallow vs. Deep copy - more in the next lesson

! Best practices
? Provide a copy constructor when your class has raw pointer members
? Provide the copy constructor with a const reference parameter
? Use STL classes as they already provide copy constructors
? Avoid using raw pointer data members if possible
*/

class Player
{
private:
  std::string name;
  int health;
  int xp;
public:
  Player(std::string name = "None", int health = 0, int xp = 0): name(name), health(health), xp(xp){}
  //? Declaring copy constructor
  Player(const Player &source);
  Player createSuperEnemy();
  std::string getName() { return name; }
  int getHealth() { return health; }
  int getXp() { return xp; }
  ~Player()
  {
    std::cout << "Player destructor called for " << name << std::endl;
  }
};

Player::Player(const Player &source): name(source.name), health(source.health), xp(source.xp){
  // code or initialization list to copy the object
  std::cout << "Copy constructor made for " << source.name << std::endl;
}

// Returning an object from a function
Player Player::createSuperEnemy()
{
  Player superEnemy {"Super Enemy", 1000, 1000};
  return superEnemy; // A copy of the element is returned
}

void displayPlayer(Player p) { //! p is a copy of hero, destructor for p will be called
  std::cout << "Name: " << p.getName() << std::endl;
  std::cout << "Health: " << p.getHealth() << std::endl;
  std::cout << "Experience: " << p.getXp() << std::endl;
}

int main()
{
  Player hero{"Hero", 100, 20};
  Player anotherHero{hero}; // Makes a copy of hero
  Player enemy;

  displayPlayer(enemy);

  enemy = enemy.createSuperEnemy();

  return 0;
}