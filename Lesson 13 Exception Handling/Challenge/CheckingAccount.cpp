#include "CheckingAccount.h"

std::ostream &operator<<(std::ostream &os, Checking_Account &account)
{
  os << "[Checking Account: " << account.name << ": " << account.balance << "]";
  return os;
}

bool Checking_Account::withdraw(double amount) {
  return Account::withdraw(amount + 1.5);
}