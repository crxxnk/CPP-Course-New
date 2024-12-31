#include <iostream>

/*
! Stack unwinding
? If an exception is thrown but not caught in the current scope, C++ tries to find a handler for the exception by unwinding the stack
* Function in which the exception was not caught terminates and is removed from the call stack
* If a try block was used, then catch blocks are checked for a match
* If no try block was used or the catch handler doesn't match, stack unwinding occurs again
* If the stack is unwound back to main and no catch handler handles the exception, the program terminates
*/

void func_c() {
  std::cout << "Starting func_c" << std::endl;
  throw 100;
  std::cout << "Ending func_c" << std::endl; // Doesn't execute because there is no handler
}

void func_b() {
  std::cout << "Starting func_b" << std::endl;
  try{
  func_c();
  } catch(int &ex) {
    std::cout << "Caught error in func_b" << std::endl;
  }
  std::cout << "Ending func_b" << std::endl;
}

void func_a() {
  std::cout << "Starting func_a" << std::endl;
  func_b();
  std::cout << "Ending func_a" << std::endl;
}

int main()
{
  std::cout << "Starting main" << std::endl;
  try {
  func_a();
  }
  catch(int &e) {
    std::cout << "Caught error in main" << std::endl;
  }
  std::cout << "Ending main" << std::endl; // Does execute and the program finishes normally because there is a handler above

  return 0;
}