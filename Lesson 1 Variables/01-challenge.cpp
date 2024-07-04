#include <iostream>

using namespace std;

int main() {
  //==================================== Practice Project ==============================================================================
  const int smallRoomCost = 25;
  const int largeRoomCost = 35;
  const double salesTaxRate = 0.06;
  int smallRooms;
  int largeRooms;
  //int cost = smallRooms * smallRoomCost + largeRooms * largeRoomCost;
  //int totalEstimate = cost+= salesTaxRate;

  cout << "Hello, welcome to Alex' Carpet Cleaning Service" << endl;
  cout << "\nHow many small rooms would you like to be cleaned? ";
  cin >> smallRooms;
  cout << "How many large rooms would you like to be cleaned? ";
  cin >> largeRooms;

  cout << "\nEstimate for Carpet Cleaning Service" << endl;
  cout << "Number of small rooms: " << smallRooms << endl;
  cout << "Number of large rooms: " << largeRooms << endl;
  cout << "Price per small room: $" << smallRoomCost << endl;
  cout << "Price per large room: $" << largeRoomCost << endl;
  cout << "Cost: $" << smallRooms * smallRoomCost + largeRooms * largeRoomCost << endl;
  cout << "Tax: $" << (smallRooms * smallRoomCost + largeRooms * largeRoomCost) * salesTaxRate << endl;
  cout << "================================================================================================================================================" << endl;
  cout << "Total Estimate: $" << (smallRooms * smallRoomCost + largeRooms * largeRoomCost) + (smallRooms * smallRoomCost + largeRooms * largeRoomCost) * salesTaxRate << endl;
  cout << "The estimate is valid for 30 days." << endl;

  return 0;
}