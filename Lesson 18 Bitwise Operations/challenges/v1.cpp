#include <iostream>

int toggleBit(int n, int k) {
  return n ^ (1 << k); // 0101 0010
}

int main() {
  int n = 5;
  int k = 1;
  int result = toggleBit(n, k);
  std::cout << "Result after toggling the " << k << "-th bit: " << result << std::endl;

  return 0;
}