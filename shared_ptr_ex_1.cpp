

#include <iostream>
#include <memory>

using namespace std;

int main() {
    shared_ptr<int> p1 = make_shared<int> (10);
    {
    shared_ptr <int> p2 (p1);
    cout << *p2 << endl;
    cout << "p2 use_count=" << p2.use_count() << endl;
    }
    cout << p1.use_count() << endl;
    cout << p1 << "," << *p1 << endl;
    return 0;
}
