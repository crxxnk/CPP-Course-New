#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector <int> vector1;
  vector <int> vector2;

  vector1.push_back(10);
  vector1.push_back(20);

  cout << "The numbers of the first vector are " << vector1.at(0) << " and " << vector1.at(1) << endl;
  cout << "The amount of elements in the first vector are " << vector1.size() << endl;

  vector2.push_back(100);
  vector2.push_back(200);

  cout << "The numbers of the second vector are " << vector2.at(0) << " and " << vector2.at(1) << endl;
  cout << "The amount of elements in the second vector are " << vector2.size() << endl;

  vector <vector<int>> vector_2;

  vector_2.push_back(vector1);
  vector_2.push_back(vector2);

  cout << "The numbers of the 2d vector are:" << endl;
  cout << vector_2.at(0).at(0) << endl;
  cout << vector_2.at(0).at(1) << endl;
  cout << vector_2.at(1).at(0) << endl;
  cout << vector_2.at(1).at(1) << endl;

  vector_2.at(0).at(0) = 1000;

  cout << "The numbers of the 2d vector are:" << endl;
  cout << vector_2.at(0).at(0) << endl;
  cout << vector_2.at(0).at(1) << endl;
  cout << vector_2.at(1).at(0) << endl;
  cout << vector_2.at(1).at(1) << endl;

  return 0;
}