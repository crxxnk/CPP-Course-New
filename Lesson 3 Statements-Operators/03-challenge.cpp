#include <iostream>

using namespace std;

int main() {
  // Dollar = 100 cents
  // Quarter = 25 cents
  // Dime = 10 cents
  // Nickel = 5 cents
  // Penny = 1 cents

  const int dollar_value = 100;
  const int quarter_value = 25;
  const int dime_value = 10;
  const int nickel_value = 5;

  int balance, dollars, quarters, dimes, nickels, pennies, cents;

  cout << "Enter the amount of money in cents: ";
  cin >> cents;

  dollars = cents / dollar_value;
  balance = cents - (dollars * dollar_value);

  quarters = balance / quarter_value;
  balance -= quarters * quarter_value;

  dimes = balance / dime_value;
  balance -= dimes * dime_value;

  nickels = balance / nickel_value;
  balance -= nickels * nickel_value;

  pennies = balance;

  cout << "Dollars: " << dollars << endl;
  cout << "Quarters: " << quarters << endl;
  cout << "Dimes: " << dimes << endl;
  cout << "Nickels: " << nickels << endl;
  cout << "Pennies: " << pennies << endl;

  return 0;
}