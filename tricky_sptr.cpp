#include <iostream>
#include <memory>
#include <vector>

using namespace std;

vector <shared_ptr <int>> buf;

int get_slot (int index) {
    shared_ptr <int> x = buf [index];
    if (!x) {
        x = make_shared<int> ();
        buf [index] = x;
        index++;
    }
    return index;
}

void get (int index, shared_ptr <int> &Sptr) {
    index --;
    shared_ptr <int> y = buf[index];
    shared_ptr <int> &temp = buf [index];
    Sptr =  buf [index];
    cout << buf[index].use_count() << endl;
    temp = NULL;
    cout << "temp = " << temp.use_count() << endl;
    cout << "TEMP NULL = " << buf[index].use_count() << endl;
    cout << "count = " << Sptr.use_count() << endl; 
    
    cout << Sptr.use_count() << endl;
    //return temp;
}

void get_buffer (int x, shared_ptr <int> &Sptr) {
  cout << "before = " << buf[0].use_count() << endl;
  get(x, Sptr);
  cout << "after = " << buf[0].use_count() << endl;
}

int main() {
    int index = 0;
    buf.reserve (10);
    index = get_slot (index);
    shared_ptr <int> y;
    cout << y.use_count() << endl;
    get_buffer(index, y);
    cout << y.use_count() << endl;
    return 0;
}
