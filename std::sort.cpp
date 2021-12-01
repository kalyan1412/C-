
#include <iostream>
#include <algorithm>

void show (int *arr, int size) {
  for (int i =0; i < size; i++) {
    std::cout << *(arr+i) << ",";
  }
  std::cout << "\n";
}

int main() {
  int arr [5];
  for (int i = 0; i < 5; i++) {
    std::cin >> arr[i];
  }
  show (arr, 5);
  std::sort (arr, arr+5);
  show (arr, 5);
  return 0;
}
