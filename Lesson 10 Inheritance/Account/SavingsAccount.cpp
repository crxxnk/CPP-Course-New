#include <iostream>
#include "SavingsAccount.h"

void SavingsAccount::deposit(const double amount) {
  std::cout << "Savings Account deposit called with " << amount << std::endl;
}

void SavingsAccount::withdraw(const double amount) {
  std::cout << "Savings Account withdraw called with " << amount << std::endl;
}

SavingsAccount::SavingsAccount(){

}

SavingsAccount::~SavingsAccount(){
  
}