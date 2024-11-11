#include <iostream>
#include <vector>
#include "SavingsAccount.cpp"
#include "Account_Util.cpp"
#include "Account.cpp"

int main()
{
  using namespace std;

  cout.precision(2);
  cout << fixed;

  // Accounts

  vector<Account> accounts;
  accounts.push_back(Account {});
  accounts.push_back(Account {"Alex"});
  accounts.push_back(Account {"Rita", 2000});
  accounts.push_back(Account {"Nick", 5000});

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  // Savings

  vector<Savings_Account> sav_accounts;
  sav_accounts.push_back(Savings_Account {});
  sav_accounts.push_back(Savings_Account {"Superman"});
  sav_accounts.push_back(Savings_Account {"Batman", 2000});
  sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0});

  display(sav_accounts);
  deposit(sav_accounts, 1000);
  deposit(sav_accounts, 2000);

  return 0;
}