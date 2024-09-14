#pragma once

class Account
{
  double amount;
public:
  void deposit(const double amount);
  void withdraw(const double amount);
  Account();
  ~Account();
};