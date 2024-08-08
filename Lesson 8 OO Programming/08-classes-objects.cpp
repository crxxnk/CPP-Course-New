#include <iostream>
#include <vector>

using namespace std;

/*
! Classes and Objects
? Classes
  * blueprint from which objects are created
  * a user-defined data-type
  * has attributes (data)
  * has methods (functions)
  * can hide data and methods
  * provides a public interface

? Examples classes
  * Account
  * Employee
  * Image
  * Vector
  * String

? Objects
  * created from a class
  * represents a specific instance of a class
  * can create many, many objects
  * each has its own identity
  * each can use the defined class methods

? Example Account Objects
  * Frank's account is an instance of an Account
  * Jim's account is an instance of an Account
  * Each has its own balance, can make deposits, withdrawals, etc.

* Examples:
! We can think of an int like a class, high_score and low_score are instances of class int
! Instances of a class are called objects
int high_score;
int low_score;

! Account is a user-defined type
Account alex_account; alex_account is an object
Account frank_account; frank_account is an object

std::vector<int> scores;
std::string name;

? Declaring a Class
class Class_Name
{
  declaration(s);
};
*/

class Player 
{
  // attributes
  string name;
  int health;
  int xp;

  // methods
  void talk(string textToSay);
  bool isDead();
};

class Account
{
  // attributes
  string name {"Account"}; // We can initialize the variables inside the class (not useful)
  float balance {0.0};

  // methods
  bool withdraw(double amount);
  bool deposit(double amount);
};

int main() {
  // Creating objects of a class
  Player hero;
  Player alex;

  Player *enemy = new Player; // Dynamically allocates memory for the enemy
  delete enemy;

  Account alex_account;
  Account frank_account;

  Account *jessica_account = new Account; // Dynamically allocates memory for the jessica account
  delete jessica_account;

  //* We can also make arrays and vectors with object elements
  Account accounts[] {alex_account, frank_account};

  vector<Player> players {alex};
  players.push_back(hero); // Adds hero to the vector

  return 0;
}