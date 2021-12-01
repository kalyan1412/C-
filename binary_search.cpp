
#include <iostream>
#include <algorithm>

void show (int *arr, int size) {
  for (int i =0; i < size; i++) {
    std::cout << *(arr+i) << ",";
  }
  std::cout << "\n";
}

int search (int *arr, int low, int high, int element) {
  int mid = (low + high) / 2;
  while (low <= high) {
      if (arr[mid] > element) {
          high = mid -1;
      }
      else if (arr[mid] < element) {
          low = mid + 1;
      }
      else {
          return mid;
      }
    mid = (low + high) / 2;
  }
  return -1;
  
}
int main() {
  int arr [5];
  for (int i = 0; i < 5; i++) {
    std::cin >> arr[i];
  }
  show (arr, 5);
  std::sort (arr, arr+5);
  show (arr, 5);
  int element;
  std::cout << "Enter the element to serach :";
  std::cin >> element;
  int x = search (arr, 0, 4, element);
  if (x == -1) {
    std::cout << "Element is not found" << std::endl;
  }
  else {
    std::cout << "Element is found at " << x+1 << "posistion" << std::endl;
  }
  return 0;
}
