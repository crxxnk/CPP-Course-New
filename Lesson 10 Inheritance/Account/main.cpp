#include <iostream>
#include "Account.cpp"
#include "SavingsAccount.cpp"

using namespace std;

int main() {
  Account account;
  account.deposit(2000.00);
  account.withdraw(500.00);

  cout << endl;

  Account *pAcc = nullptr;
  pAcc = new Account();
  pAcc->deposit(3000.00);
  pAcc->withdraw(1000.00);
  delete pAcc;

  SavingsAccount savAccount;
  savAccount.deposit(2000.00);
  savAccount.withdraw(500.00);

  cout << endl;

  SavingsAccount *pSavAcc = nullptr;
  pSavAcc = new SavingsAccount();
  pSavAcc->deposit(3000.00);
  pSavAcc->withdraw(1000.00);
  delete pAcc;

  return 0;
}