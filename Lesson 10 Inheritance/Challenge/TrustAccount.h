#include "SavingsAccount.h"

class Trust_Account : public Savings_Account
{
  friend std::ostream &operator<<(std::ostream &os, Trust_Account &account);
  static constexpr int maxWithrawals = 3;
  static constexpr float maxWithdrawalPercentage = 0.2;
  int withdrawals = 0;
public:
  Trust_Account(std::string name, double balance, double int_rate): Savings_Account(name, balance, int_rate){}
  bool deposit(double amount);
  bool withdraw(double amount);
};