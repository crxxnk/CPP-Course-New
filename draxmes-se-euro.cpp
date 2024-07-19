#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  char selection {};
  double euro {}, draxmes {}, value{};
  cout << fixed << setprecision(2);

  cout << "D. Convert Draxmes to Euros." << endl;
  cout << "E. Convert Euros to Draxmes." << endl;
  cout << "Q. Quit" << endl;
  
  do {
    cout << "Please select your action: ";
    cin >> selection;
    if (selection == 'D' || selection == 'd') {
      cout << "Enter the amount of Draxmes you want to convert to Euros: ";
      cin >> draxmes;
      cout << draxmes / 340.75 << endl;
    } else if (selection == 'E' || selection == 'e') {
      cout << "Enter the amount of Euros you want to convert to Draxmes: ";
      cin >> euro;
      cout << euro * 340.75 << endl;
    }
  } while (selection != 'Q' && selection != 'q');

  return 0;
}