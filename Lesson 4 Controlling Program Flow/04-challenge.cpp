#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  char selection {};
  int num_addition {};
  vector<int> numbers{};

  do {
    cout << "P - Print numbers" << endl;
    cout << "A - Add number" << endl;
    cout << "M - Display the mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl << endl;
    cout << "Enter your choice: ";
    cin >> selection;
    cout << endl;

    if (selection == 'P' || selection == 'p') {
      if (numbers.empty())
          cout << "[] - The list is empty" << endl << endl;
        else {
          cout << "Printing numbers..." << endl << endl;
          cout << "[ ";
          for (int num: numbers) 
            cout << num << " ";
          cout << "]" << endl << endl;
        }
    } else if (selection == 'A' || selection == 'a') {
      cout << "Enter a number to add to the list: ";
      cin >> num_addition;
      cout << endl;
      numbers.push_back(num_addition);
      cout << num_addition << " added." << endl << endl;
    } else if (selection == 'M' || selection == 'm') {
      if (numbers.empty())
        cout << "Unable to calculate the mean - no data" << endl << endl;
      else {
        cout << fixed << setprecision(2);
        double sum {};
        for (int num: numbers) 
          sum += num;
        double mean = sum / numbers.size();
        cout << "The mean of the numbers is " << mean << endl << endl;
      }
    } else if (selection == 'S' || selection == 's') {
      if (numbers.empty()) {
        cout << "Unable to determine the smallest number - list is empty" << endl << endl;
      } else {
        int smallest = numbers[0];
        for (int num: numbers) {
          if (num < smallest)
            smallest = num;
        }
        cout << "The smallest number is " << smallest << endl << endl;
      }
    } else if (selection == 'L' || selection == 'l'){
      if (numbers.empty()) {
        cout << "Unable to determine the largest number - list is empty" << endl << endl;
      } else {
        int largest = numbers[0];
        for (int num: numbers) {
          if (num > largest)
            largest = num;
        }
        cout << "The largest number is " << largest << endl << endl;
      }
    } else if (selection == 'Q' || selection == 'q') {
      cout << "Goodbye!";
    } else {
      cout << "Invalid selection. Please try again." << endl << endl;
    }
  } while (selection != 'Q' && selection != 'q');

  return 0;
}