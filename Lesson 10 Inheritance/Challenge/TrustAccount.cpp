#include "TrustAccount.h"

std::ostream &operator<<(std::ostream &os, Trust_Account &account)
{
  os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.withdrawals << ", " << account.int_rate << "%]";
  return os;
}

bool Trust_Account::deposit(double amount) {
  if(amount >= 5000.00)
    return Savings_Account::deposit(amount + 50.00);
  else
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
  if(withdrawals >= maxWithrawals || amount > balance * maxWithdrawalPercentage)
    return false;
  else {
    withdrawals++;
    return Account::withdraw(amount);
  }
}