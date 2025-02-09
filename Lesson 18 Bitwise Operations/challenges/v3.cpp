#include <iostream>

void swap(int &a, int &b) { // 1010, 0011 (10, 3) for instance
  a ^= b; // a = 1001
  b = a ^ b; // b = 1010 which is a
  a ^= b; // a = 0011 successfully swapped
}

int main() {
  int a = 10;
  int b = 3;
  std::cout << a << " " << b << std::endl;
  swap(a, b);
  std::cout << a << " " << b << std::endl;

  return 0;
}