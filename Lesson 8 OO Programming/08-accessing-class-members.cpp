#include <iostream>
#include <vector>

using namespace std;

class Player 
{
public: // We need to make everything public so we can access it
  string name;
  int health;
  int xp;

  void talk(string textToSay) {cout << name << " says " << textToSay << endl;} // There are many ways to implement methods, we will see the other ways later
  bool isDead();
};

class Account
{
public: // We need to make everything public so we can access it
  string name;
  float balance;

  bool deposit(double amount) {balance += amount; cout << "In deposit" << endl;}
  bool withdraw(double amount) {balance -= amount; cout << "In withdraw" << endl;}
};

/*
? Accessing class members
* We can access:
  * class attributes
  * class methods

! Some class members will not be accessible
? We need an object to access instance variables

? If we have an object(dot operator)
* Using the dot operator
Account alex_account;

alex_account.balance;
alex_account.deposit(1000);

? If we have a pointer to an object(member of pointer operator/arrow operator)
* Dereference the pointer and use the dot operator
Account *alex_account = new Account();

(*alex_account).balance;
(*alex_account).deposit(1000);

* Or use the member of pointer operator(arrow operator)
Account *alex_account = new Account();

alex_account->balance;
alex_account->deposit(1000);
*/

int main() {
  Player hero;
  hero.name = "Alex";
  hero.health = 100;
  hero.xp = 12;
  hero.talk("Hey there!");

  Player *enemy = new Player;
  enemy->name = "Goblin";
  enemy->health = 62;
  enemy->xp = 27;
  enemy->talk("I will destroy you!");
  delete enemy;

  Account alex_account;
  alex_account.name = "Alex's account";
  alex_account.balance = 7000;

  alex_account.deposit(1000);
  alex_account.withdraw(200);

  return 0;
}