
#include <iostream>
#include <vector>
#include <iterator>

void display (std::vector <int> &vec) {
    for (auto i : vec) {
        std::cout << i << ",";
    }
    std::cout << "\n";
}
int main() {
    std::vector <int> v1;
    std::cout << "Initial size of vector is = " << v1.size() << std::endl;
    for (int i = 1; i <= 5; i++) {
        v1.push_back(i);
    }
    display (v1);
    std::cout << "The size of vector after inserting the elements = " << v1.size() << std::endl;
    if (v1.empty()) {
        std::cout << "Vector is empty" << std::endl;
    }
    else {
        std::cout << "Vector is not empty" << std::endl;
    }
    v1.resize(4);
    v1.shrink_to_fit();
    display(v1);
    std::cout << "Front element = " << v1.front() << std::endl;
    std::cout << "last element = " << v1.back() << std::endl;
    v1.pop_back();
    display (v1);
    v1.clear(); // it will clear all the elements in the vector
    if (v1.empty()) {
        std::cout << "Vector is empty" << std::endl;
    }
    else {
        std::cout << "Vector is not empty" << std::endl;
    }
    // assign 
    // It assigns new values to the vector by replacing old one's
    v1.assign (5, 10);
    display (v1); // 5 5 5 5 5
    int arr[4] = {1,2,3,4};
    v1.clear();
    v1.assign (arr, arr+3);
    display (v1); // 1 2 3 
    v1.clear();
    for (int i = 1; i <= 5; i++) {
        v1.push_back (i*2);
    }
    display (v1); // 2 4 6 8 10
    v1.assign (v1.begin(), v1.begin()+3);
    display (v1); // 2 4 6 
    // insert
    // which inserts new elements before the element at the specified location.
    auto it = v1.begin() +1;
    it = v1.insert (it, 2, 3);
    display (v1); // 2 3 4 6
    std::vector <int> v2;
    v2.insert (v2.begin(), v1.begin(), v1.begin() + 4);
    display (v2); // 2 3 4
    // erase
    // it is used to remove the elements specified at given location or range.
    v2.clear();
    for (int i = 1; i <= 5; i++) {
        v2.push_back(i);
    }
    display (v2); // 1 2 3 4 5
    it = v2.begin() + 2;
    v2.erase (it);
    display (v2); // 1 2 4 5
    it = v2.begin() + 1; 
    auto it2 = v2.end();
    it2--;
    v2.erase (it, it2);
    display (v2); // 1 5
    return 0;
}
