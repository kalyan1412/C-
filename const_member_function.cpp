#include<iostream>

using namespace std;

class Sample {
    private:
    int x;
    public:
    Sample () : x(0) { }
    void set_x(int);
    int get_x() const ;
};

void Sample :: set_x(int x) {
    this->x = x;
}

int Sample :: get_x() const {
    return x;
}

int main() {
    Sample s1;
    s1.set_x(10);
    cout << s1.get_x() << endl;

    //const Sample s2;
    //s2.set_x(100);
    //cout << s2.get_x() << endl;
    return 0;
}
