/*
! Class-level exceptions
? Exceptions can also be thrown from within a class:
? Method
  * These work the same way as they do for functions as we've seen
? Constructor
  * Constructors may fail
  * Constructors do not return any value
  * Throw an exception in the constructor if you cannot initialize an object
? Destructor
  ! Do NOT throw exceptions from your destructor
Account::Account(std::string name, double balance): name(name), balance(balance) {
  if(balance < 0.0)
    throw IllegalBalanceException();
}

try {
  std::unique_ptr<Account> account = std::make_unique<Checking_Account>("Alex", -10.0);
}
catch(const IllegalBalanceException &e) {
  std::cerr << "Couldn't create account" << std::endl;
}
*/