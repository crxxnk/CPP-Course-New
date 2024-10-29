#include <iostream>

double add(int a, int b)
{
  return a + b;
}

int main()
{
  void* voidPtr = new int;
  int* intPtr = static_cast<int*>(voidPtr);
  *intPtr = 42;

  std::cout << "Value from allocated memory: " << *intPtr << std::endl;
  std::cout << voidPtr << std::endl;

  const char* txt = "your daddy sucks my cock";

  std::cout << "Text: " << txt << std::endl;

  delete intPtr;

  return 0;
}