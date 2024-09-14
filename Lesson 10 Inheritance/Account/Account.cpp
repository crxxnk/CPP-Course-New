#include <iostream>
#include "Account.h"

void Account::deposit(const double amount) {
  std::cout << "Account deposit called with " << amount << std::endl;
}

void Account::withdraw(const double amount) {
  std::cout << "Account withdraw called with " << amount << std::endl;
}

Account::Account(){

}

Account::~Account(){
  
}