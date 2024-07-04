#include <iostream>
#include <vector>

using namespace std;

//* Vectors is an object oriented container in the C++ Standard Template Library.
//* It is an array that its size can change during runtime.
//* Its syntax is similar to arrays.
//* It can provide bounds checking.
//* Can use lots of functions like sort, reverse, find and more.
//* First element is at index 0, last element is at index -1.
//* All the elements are automatically initialized to 0 unless specified otherwise.
int main() {
  //! Declaring a vector:
  vector <char> characters1; //? Contains no elements.
  vector <int> testScores1; //? Contains no elements.

  //* Another way of declaring a vector:
  vector <char> characters2 (5); //? Contains 5 characters but still no initialization.
  vector <int> testScores2 (10); //? Contains 10 integers but still no initialization.

  //* Initializing a vector:
  vector <char> characters3 {'a', 'b', 'c'};
  vector <int> testScores3 {100, 95, 92};

  //! Creates a double vector with size 365 and assigns 80.0 to all of them.
  vector <double> temp (365, 80.0);

  //? Accessing vectors:
  //* The syntax to access vectors is the same as arrays.
  cout << "Characters: " << characters3[0] << endl;

  //or

  //* Using the at() function to access an element:
  cout << "Test scores: " << testScores3.at(0) << endl;

  //! Using the at() function is better because we can also change the contents of the vector elements this way:
  //? Replaces the specific numbers in the given index with the numbers absorbed by the input.
  cout << "What should the first and second score be? ";
  cin >> testScores3.at(0);
  cin >> testScores3.at(1);
  cout << "The first score is " << testScores3.at(0) << " and the second score is " << testScores3.at(1) << endl;

  //! The vector has a method called push_back() that adds a new element to the end of the vector.
  //! All vector elements must be of the same type!
  testScores3.push_back(90);
  testScores3.push_back(87);
  cout << "Added " << testScores3.at(3) << " and " << testScores3.at(4) << endl;

  int scoreToAdd;
  cout << "Add a score to the vector: ";
  cin >> scoreToAdd;
  testScores3.push_back(scoreToAdd);
  cout << "Added " << scoreToAdd << " to the vector." << endl;
  cout << testScores3.at(5) << endl;

  //! The method size() checks how many elements are in a vector:
  cout << "There are " << testScores3.size() << " elements in the vector";

  //! 2D Vector(vector of vectors):
  vector <vector<int>> movieRatings {
    //? Horizontally are the reviewers and vertically are the movies:
    {1, 2, 3, 4}, //* First reviewer. He rated the first movie with 1, the second movie with 2, the third movie with 3 and the fourth movie with 4
    {2, 5, 3, 4}, //* Second reviewer. He rated the first movie with 2, the second movie with 5, the third movie with 3 and the fourth movie with 4.
    {4, 1, 2, 3} //* Third reviewer. He rated the first movie with 4, the second movie with 1, the third movie with 2 and the fourth movie with 3.
  };

  cout << "Here is the first reviewer rating:" << endl;
  /*
  cout << movieRatings[2][0] << endl;
  cout << movieRatings[2][1] << endl;
  cout << movieRatings[2][2] << endl;
  cout << movieRatings[2][3] << endl;

  or*/

  cout << movieRatings.at(2).at(0) << endl;
  cout << movieRatings.at(2).at(1) << endl;
  cout << movieRatings.at(2).at(2) << endl;
  cout << movieRatings.at(2).at(3) << endl;

  return 0;
}