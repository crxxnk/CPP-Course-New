#include <memory>
#include "CheckingAccount.cpp"
#include "TrustAccount.cpp"
#include "Account.cpp"
#include "SavingsAccount.cpp"

int main()
{
  std::unique_ptr<Account> alex;
  std::unique_ptr<Account> rita;
  try {
    rita = std::make_unique<Savings_Account>("Rita", -2000.0);
    std::cout << *rita << std::endl;
  } catch(const IllegalBalanceException &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    alex = std::make_unique<Savings_Account>("Alex", 1000.0);
    std::cout << *alex << std::endl;
    alex->withdraw(500.0);
    std::cout << *alex << std::endl;
    alex->withdraw(1000.0);
    std::cout << *alex << std::endl;

    rita = std::make_unique<Savings_Account>("Rita", -2000.0);
    std::cout << *rita << std::endl;
  } catch(const IllegalBalanceException &e) {
    std::cerr << e.what() << std::endl;
  } catch(const InsufficientFundsException &e) {
    std::cerr << e.what() << std::endl;
  }

}