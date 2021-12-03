
// function template

#include <iostream>

template <class T, int z = 6>
T fun (T x, T y) {
    std::cout << "function template" << std::endl;
    return x + y + z;
}

/*
template <>
int fun <int> (int x, int y) {
    std::cout << "normal function" << std::endl;
    return x+y;
}
*/

int main() {
    std::cout << fun <int> (12, 13) << std::endl;
    std::cout << fun <double> (12.3, 13.6) << std::endl;
    return 0;
}
