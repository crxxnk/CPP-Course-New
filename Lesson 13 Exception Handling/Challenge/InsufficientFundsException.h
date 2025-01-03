#include <iostream>

struct InsufficientFundsException : public std::exception
{
  const char* what() const noexcept override { return "Insufficient funds"; }
};