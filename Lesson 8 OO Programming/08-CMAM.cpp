#include <iostream>

using namespace std;

/*
! Class Member Access Modifiers(CMAM)
? public, private and protected
* public
  * accessible everywhere

* private
  * accessible only by members or friends of the class

* protected
  * used with inheritance - we'll talk about it later

* Examples:

class Class_Name
{
public:
  declaration(s);
};

class Class_Name
{
private:
  declaration(s);
};

class Class_Name
{
protected:
  declaration(s);
};
*/

class Player
{
private:
  string name;
  int health;
  int xp;
public:
  void talk(string textToSay) {cout << name << " says " << textToSay << endl;}
  bool isDead();
};

class Account
{
private:
  string name;
  double balance;
public:
  bool deposit(double amount);
  bool withdraw(double amount);
};

int main() {
  Player hero;
  // hero.name = "Alex"; //! ERROR
  // hero.health = 100; //! ERROR
  hero.talk("Ready to Battle!"); // OK

  Player *enemy = new Player;
  //enemy->xp = 100; //! ERROR
  enemy->talk("I will hunt you down!");

  delete enemy;

  Account alex_account;
  //alex_account.balance = 1000000; //! ERROR
  alex_account.deposit(1000); // OK
  alex_account.withdraw(500); // OK
  //alex_account.name = "Alex"; //! ERROR

  Account *mary_account = new Account;
  //mary_account->balance = 500000; //! ERROR
  mary_account->deposit(2000); // OK

  delete mary_account;

  return 0;
}