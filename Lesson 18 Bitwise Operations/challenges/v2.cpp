#include <iostream>

int setBits(int n) {
  int count = 0;
  for(int i = 0; i < 32; i++) {
    if(n & 1 == 1)
      count++;
    n>>=1; // n = n>>1
  }
  return count;
}

int main() {
  std::cout << setBits(255) << std::endl;

  return 0;
}