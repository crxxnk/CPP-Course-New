#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Finds the power of a number
double power(double num, float power) {
  double temp = num;
  for (int i = 1; i < power; i++) {
    num *= temp;
  }
  return num;
}

double calc_cost(double base_cost, double tax_rate = 0.06 ) { // default argument
  return base_cost += (base_cost * tax_rate);
}

int main() {
  int random_number {};
  size_t count {10};
  int min = 1;
  int max = 6;

  srand(time(nullptr)); // Sets the seed for a random number generator

  for (int i = 1; i <= count; i++) {
    random_number = rand() % max + min; // Generates a random number between the range
    cout << random_number << " ";
  }

  cout << calc_cost(15);

  return 0;
}