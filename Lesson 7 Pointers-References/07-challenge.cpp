#include <iostream>

using namespace std;

int* apply_all(int array1[], int size1, int array2[], int size2);
void print(int array[], int size);

int main() {
  const size_t array1_size {5};
  const size_t array2_size {3};

  int array1[] {1,2,3,4,5};
  int array2[] {10,20,30};

  cout << "Array 1: " ;
  print(array1,array1_size);

  cout << "Array 2: ";
  print(array2,array2_size);

  int *results = apply_all(array1,array1_size,array2,array2_size);
  constexpr size_t results_size {array1_size * array2_size};

  cout << "Result: ";
  print(results,results_size);

  return 0;
}

int* apply_all(int array1[], int size1, int array2[], int size2) {
  int pos {0};
  int* new_ar = new int[size1 * size2];
  for (size_t i = 0; i < size2; i++) {
    for (size_t j = 0; j < size1; j++) {
      new_ar[pos] = array1[j] * array2[i];
      pos++;
    }
  }
  return new_ar;
  delete[] new_ar;
}

void print(int array[], int size) {
  int* new_ar = new int[size];
  new_ar = array;
  for (int i = 0; i < size; i++)
    cout << new_ar[i] << " ";
  cout << endl;
}