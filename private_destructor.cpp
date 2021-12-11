
// private destructor

#include <iostream>

class Sample {
    private:
    ~Sample () {
        std::cout << "destructor" << std::endl;
    }
    public:
    Sample () {
        std::cout << "Constructor called" << std::endl;
    }
    friend void destruct (Sample *s);
};

void destruct (Sample *s) {
    delete s;
}


int main() {
    Sample *s = new Sample();
    destruct (s);
    return 0;
}
