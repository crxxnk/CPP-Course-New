#include <iostream>
/*
! this pointer
? this is a reserved keyword
? Contains the address of the object - so it's a pointer to the object
? Can only be used in class scope
? All member access is done via the this pointer
? Can be used by the programmer
  * To access data member and methods
  * To determine if two objects are the same (more in the next section)
  * Can be dereferenced(*this) to yield the current object
*/

//* Examples:

class Account
{
private:
  double balance;
  std::string name;
public:
  void setBalance(double balance);
  void compareBalance(const Account &other);
};

void Account::compareBalance(const Account &other){
  if (this == &other)
    std::cout << "The same objects" << std::endl;
  if (this != &other)
    std::cout << "Different objects" << std::endl;
}

void Account::setBalance(double balance){
  this->balance = balance;
}

int main()
{
  Account alex;
  Account rita;
  rita.setBalance(2000.00);
  alex.setBalance(1000.00);
  alex.compareBalance(rita);

  return 0;
}