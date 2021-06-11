// string stream, assciates a string object which we can read from cin.
// Basic methods.
// 1) clear().
// 2) str ()
// operator << , write to stream obj
// operator >> , read from stream object.


#include<iostream>
#include<sstream>

using namespace std;

int main() {
    string str = "12345";
    stringstream s;
    s << "kalyan";
    std::cout << s.str() << std::endl;
    s.str(str);
    int x;
    s >> x;
    std::cout << x << std::endl;
    return 0;
}
