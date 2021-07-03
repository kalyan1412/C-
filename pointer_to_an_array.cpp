
// pointer to an array 

#include <iostream>

using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    int (*ptr) [5] = &arr;  // pointer to an array
    cout << "p=" << p << "," <<  "ptr=" << ptr << endl;
    cout << sizeof(p) << "," << sizeof (ptr) << endl;
    cout << "*p=" << *p << "," << "*ptr=" << *(*ptr) << endl;
    p++;
    ptr++;
    cout << "p=" << p << "," <<  "ptr=" << ptr << endl;
    return 0;
}
