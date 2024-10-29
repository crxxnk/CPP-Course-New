#include <iostream>

/*
! EXAMPLES ARE IN Account FOLDER !

! Inheritance
? What is it and why is it used?
* Provides a method for creating new classes from existing classes
* The new class contains the data and behaviors of the existing class
* Allow for reuse of the existing classes
* Allows us to focus on the common attributes among a set of classes
* Allow new classes to modify behaviors of existing classes to make it unique
  * Without actually modifying the original class
? Related classes
* Player, Enemy, Level Boss, Hero, Super Player, etc.
* Account, Savings Account, Checking Account, Trust Account, etc.
* Shape, Line, Oval, Circle, Square, etc.
* Person, Employee, Student, Faculty, Staff, Administrator, etc.

Account
  balance, deposit, withdraw,...

Savings Account
  balance, deposit, withdraw, interest rate,...
Checking Account
  balance, deposit, withdraw, minimum balance, per check fee,...
Trust Account
  balance, deposit, withdraw, interest rate,...

//* Syntax(more in the next videos):

class Account {
  balance, deposit, withdraw,...
};

class SavingsAccount : public Account {
  interest rate, specialized withdraw,...
};

class CheckingAccount : public Account {
  minimum balance, per check fee, specialized withdraw,...
};

class TrustAccount : public Account {
  interest rate, specialized withdraw,...
};

! Terminology and Notation

! Terminology
? Inheritance
  * Process of creating new classes from existing classes
  * Reuse mechanism
? Single Inheritance
  * A new class is created from another 'single' class
? Multiple Inheritance
  * A new class is created from two (or more) other classes

? Base class(parent class, super class)
  * The class being extended or inherited from
? Derived class(child class, sub class)
  * The class being created from the Base class
  * Will inherit attributes and operations from Base class

? "Is-A" relationship
  * Public inheritance
  * Derived classes are sub-types of their Base classes
  * Can use a derived class object wherever we use a base class object
? Generalization
  * Combining similar classes into a single, more general class based on common attributes
? Specialization
  * Creating new classes from existing classes proving more specialized attributes or operations
? Inheritance or Class Hierarchies
  * Organization of our inheritance relationships

! Public Inheritance vs. Composition

* Both allow reuse of existing classes

? Public Inheritance
  * "is-a" relationship
    * Employee 'is-a' Person
    * Checking Account 'is-a' Account
    * Cirlce 'is-a' Shape

? Composition
  * "has-a" relationship
    * Person "has-a" Account
    * Player "has-a" Special Attack
    * Circle "has-a" Location

* Composition example:

struct Account
{
int accountNum;
double balance;
};

class Person
{
private:
  std::string name; // has-a name
  Account account; // has-a account
public:
  double getBalance() const { return account.balance; }
  Person() { account.balance = 0; }
};

! Deriving classes from existing classes

class Base {
  Base class members...
};

class Derived : access-specifier Base {
  Derived class members...
};

! Access Specifier can be: public, private or protected. Private is default.

? public:
  * Most common
  * Establishes 'is-a' relationship between Derived and Base classes

? private and protected:
  * Establishes "derived class has a base class" relationship
  * "Is implemented in terms of" relationship
  * Different from composition

* Example:
class Account
{
  Account class members...
};

class SavingsAccount : public Account { //! SavingsAccount 'is-a' Account
  SavingsAccount class members...
};

* Object creation examples:

Account account;
Account pAccount = new Account();

account.deposit(1000.00);
pAccount->withdraw(200.00);

delete pAccount;

SavingsAccount savAccount;
SavingsAccount pSavAccount = new SavingsAccount();

savAccount.deposit(1000.00);
pSavAccount.withdraw(200.00);

delete pSavAccount;

! EXAMPLES ARE IN Account FOLDER !
*/