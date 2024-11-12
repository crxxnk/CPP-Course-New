#include "Account.h"

class Checking_Account : public Account
{
  friend std::ostream &operator<<(std::ostream &os, Checking_Account &account);
  static constexpr float withdrawalFee = 1.50;
public:
  Checking_Account(std::string name, double balance): Account(name, balance){}
  bool withdraw(double amount);
};