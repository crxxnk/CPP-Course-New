#include <iostream>

/*
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
*/

class Account
{
private:
  std::string name;
  int accountNumber;
  double balance;
public:
  Account(std::string name, int accountNumber, double balance) : name(name), accountNumber(accountNumber), balance(balance) {}
  void deposit(double amount) { balance += amount; }
  void withdraw();
};

void Account::withdraw() {
  double amount;
  do{
    std::cin >> amount;
  }while(amount > this->balance || !isdigit(amount));
  std::cout << "Withdrawal completed successfully" << std::endl;
  balance -= amount;
}

int main()
{
  Account account("John Doe", 123456789, 1000.0);
  account.withdraw();

  return 0;
}