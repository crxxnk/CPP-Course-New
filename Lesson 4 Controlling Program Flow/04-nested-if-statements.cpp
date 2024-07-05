#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  //! Nested if statements are if statements inside if statements:
  //* For example

  int score_alex = 95;
  int score_bob = 89;

  if (score_alex != score_bob) {
    if (score_alex > score_bob) {
      cout << "Alex wins!" << endl;
    } else {
      cout << "Bob wins!" << endl;
    }
  } else {
    cout << "Looks like we have a tie!" << endl;
  }

  //* Second example

  int score;
  char letter_grade;

  cout << "Enter your score on the exam: ";
  cin >> score;

  if (score >= 0 && score <= 100) {
    if (score >= 90) {
      letter_grade = 'A';
    } else if (score >= 80) {
      letter_grade = 'B';
    } else if (score >= 70) {
      letter_grade = 'C';
    } else if (score >= 60) {
      letter_grade = 'D';
    } else {
      letter_grade = 'F';
    }
    cout << "Your grade is: " << letter_grade << endl;

    if (letter_grade == 'F') {
      cout << "Sorry, you must repeat the class." << endl;
    } else {
      cout << "Congratulations, you passed the class!" << endl;
    }
  } else {
    cout << "Invalid score. Please enter a number between 0 and 100." << endl;
  }

  //* Third example

  int length, width, height;
  const double base_cost = 2.50;
  const int tier1_threshold = 100; // Least cubic inches for 10% charge
  const int tier2_threshold = 500; // Least cubic inches for 25% charge
  const int max_dimension_length = 10;
  const double tier1_surcharge = 0.10; // 10% extra
  const double tier2_surcharge = 0.25; // 25% extra
  int package_volume;

  cout << "Welcome to the package cost calculator!" << endl;
  cout << "Please enter the length, width, and height of the package: ";
  cin >> length >> width >> height;

  if (length > max_dimension_length || width > max_dimension_length || height > max_dimension_length) {
    cout << "Sorry, package rejected - dimension exceeded" << endl;
  } else {
    double package_cost;
    package_volume = length * width * height;
    package_cost = base_cost;

    if (package_volume > tier2_threshold) {
      package_cost += package_cost * tier2_surcharge;
      cout << "Adding tier 2 surcharge..." << endl;
    } else if (package_volume > tier1_threshold) {
      package_cost += package_cost * tier1_surcharge;
      cout << "Adding tier 1 surcharge..." << endl;
    }

    cout << fixed << setprecision(2); // Format output to two decimal places, need to include iomanip
    cout << "The volume of your package is: " << package_volume << " cubic inches" << endl;
    cout << "The cost of shipping your package is: $" << package_cost << endl;
  }

  return 0;
}