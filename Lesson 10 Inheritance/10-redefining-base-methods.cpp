#include <iostream>

/*
! Using and redefining Base class methods
? Derived class can directly invoke Base class methods
? Derived class can override or redefine Base class methods
* Very powerful in the context of polymorphism(next section)

class Account
{
public:
  void deposit(double amount) { balance += amount; }
};

class SavingsAccount : public Account
{
public:
  void deposit(double amount) { Redefine Base class method
    amount += some_interest;
    Account::deposit(amount); Invoke call Base class method
  }
};

! Static binding of method calls
? Binding of which method to use is done at compile time
  * Default binding for C++ is static
  * Derived class objects will use Derived::deposit
  * But, we can explicitly invoke Base::deposit from Derived::deposit
  * OK, but limited - much more powerful approach is dynamic binding which we will see in the next section
* Example:

Base b;
b.deposit(1000.0); // Base::deposit

Derived d;
d.deposit(1000.0); // Derived::deposit

Base *ptr = new Derived;
ptr->deposit(1000.0); // Base::deposit ????
*/

class Account
{
  friend std::ostream &operator<<(std::ostream &os, const Account &account) { os << "Account balance: " << account.balance; return os; }
protected:
  double balance;
public:
  Account(): Account(0.0){}
  Account(double balance): balance(balance){}
  void deposit(double amount) { balance += amount; }
  void withdraw(double amount) { if(balance - amount >= 0) balance-=amount; else std::cout << "Insufficient funds" << std::endl; }
};

class SavingsAccount : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) { os << "Savings account balance: " << account.balance << " Interest rate: " << account.int_rate; return os;}
protected:
  double int_rate;
public:
  SavingsAccount(): SavingsAccount(0.0, 0.0) { }
  SavingsAccount(double balance, double int_rate): Account(balance), int_rate(int_rate) { }
  void deposit(double amount) { amount += (amount * int_rate/100); Account::deposit(amount); }
  // Withdraw is inherited
};

int main()
{
  using namespace std;

  cout << "======= Account Class =======\n" << endl;

  Account a1(1000.0);
  cout << a1 << endl;

  a1.deposit(500.0);
  cout << a1 << endl;

  a1.withdraw(1000);
  cout << a1 << endl;

  a1.withdraw(5000.0);
  cout << a1 << endl;

  cout << "\n======= Savings Account Class =======\n" << endl;

  SavingsAccount s1(1000, 5.0);
  cout << s1 << endl;

  s1.deposit(1000);
  cout << s1 << endl;
  
  s1.withdraw(2000);
  cout << s1 << endl;

  s1.withdraw(1000);
  cout << s1 << endl;

  return 0;
}