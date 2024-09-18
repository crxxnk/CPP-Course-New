#pragma once

class Account
{
public:
  double balance;
  std::string name;
  void deposit(const double amount);
  void withdraw(const double amount);
  Account();
  ~Account();
};