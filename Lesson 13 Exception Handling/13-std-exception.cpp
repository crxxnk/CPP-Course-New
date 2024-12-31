/*
! The C++ standard library exception class hierarchy
? C++ provides a class hierarchy of exception classes
  * std::exception is the base class
  * all subclasses implement the what() virtual function
  * we can create our own user-defined exception subclasses
virtual const char* what() const noexcept;

* noexcept guarantees that the method will not throw an exception
class IllegalBalanceException : public std::exception
{
public:
  IllegalBalanceException() noexcept = default;
  ~IllegalBalanceException() = default;
  virtual const char* what() const noexcept {
    return "Illegal balance exception";
  }
};

Account::Account(std::string name, double balance): name(name), balance(balance) {
  if(balance < 0.0)
    throw IllegalBalanceException();
}

try {
  std::unique_ptr<Account> account = std::make_unique<Checking_Account>("Alex", -100.0);
  std::cout << "Used Alex' account" << std::endl;
}
catch(const IllegalBalanceException &e) {
  std::cerr << e.what() << std::endl; // displays "Illegal balance exception"
}
*/