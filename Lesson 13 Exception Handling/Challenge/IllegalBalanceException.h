#include <iostream>

struct IllegalBalanceException : public std::exception
{
  const char* what() const noexcept override { return "Illegal Balance"; }
};