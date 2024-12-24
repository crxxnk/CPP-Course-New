#include <iostream>

class I_Printable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() = default;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Account : public I_Printable
{
  std::string name;
  double balance;
public:
  Account(std::string name, double balance): name(name), balance(balance) {}
  virtual void withdraw(double amount) { std::cout << "In Account::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Account display"; }
  virtual ~Account() {}
};

class Checking : public Account
{
public:
  Checking(std::string name, double balance): Account(name, balance) {}
  void withdraw(double amount) { std::cout << "In Checking::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Checking display"; }
  ~Checking() {}
};

class Savings : public Account
{
public:
  Savings(std::string name, double balance): Account(name, balance) {}
  void withdraw(double amount) { std::cout << "In Savings::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Savings display"; }
  ~Savings() {}
};

class Trust : public Account
{
public:
  Trust(std::string name, double balance): Account(name, balance) {}
  void withdraw(double amount) { std::cout << "In Trust::withdraw" << std::endl; }
  void print(std::ostream &os) const override { os << "Trust display"; }
  ~Trust() {}
};