#include "CheckingAccount.cpp"
#include "TrustAccount.cpp"
#include "Account.cpp"
#include "SavingsAccount.cpp"

int main()
{
  Checking_Account check("Alex", 500);
  std::cout << check.withdraw(500-1.5) << std::endl;
  std::cout << check << std::endl;

  Trust_Account trust("Alex", 10000, 0);
  std::cout << trust.deposit(4000) << std::endl;
  std::cout << trust << std::endl;

  std::cout << trust.withdraw(1000) << std::endl;
  std::cout << trust << std::endl;

  std::cout << trust.withdraw(1000) << std::endl;
  std::cout << trust << std::endl;

  std::cout << trust.withdraw(1000) << std::endl;
  std::cout << trust << std::endl;

  std::cout << trust.withdraw(1000) << std::endl;
  std::cout << trust << std::endl;
}