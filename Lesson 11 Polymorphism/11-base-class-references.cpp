#include <iostream>

/*
! Using Base class references
? We can also use Base class references with dynamic polymorphism
* Useful when we pass objects to functions that expect a Base class reference

Account a;
Account& ref = a;
ref.withdraw(1000); // Account::withdraw

Trust t;
Account& ref1 = t;
ref1.withdraw(1000); // Trust::withdraw

* Another example:

void do_withdraw(Account& account, double amount) {
  account.withdraw(amount);
}

Account a;
do_withdraw(a, 1000); // Account::withdraw

Trust t;
do_withdraw(t, 1000); // Trust::withdraw
*/

class Account
{
public:
  virtual void withdraw(double amount) { std::cout << "In Account::withdraw" << std::endl; }
  virtual ~Account() { std::cout << "Destructor for Account" << std::endl; }
};

class Savings : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Savings::withdraw" << std::endl; }
  ~Savings() { std::cout << "Destructor for Savings" << std::endl; }
};

class Checking : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Checking::withdraw" << std::endl; }
  ~Checking() { std::cout << "Destructor for Checking" << std::endl; }
};

class Trust : public Account
{
public:
  void withdraw(double amount) { std::cout << "In Trust::withdraw" << std::endl; }
  ~Trust() { std::cout << "Destructor for Trust" << std::endl; }
};

void do_withdraw(Account& account, double amount) {
  account.withdraw(amount);
}

int main()
{
  Account a;
  Account& ref = a;
  ref.withdraw(1000);

  Trust t;
  Account& ref1 = t;
  ref1.withdraw(1000);

  Account a1;
  Savings a2;
  Checking a3;
  Trust a4;

  do_withdraw(a1, 1000);
  do_withdraw(a2, 2000);
  do_withdraw(a3, 3000);
  do_withdraw(a4, 4000);

  return 0;
}