

// uninary prefix operator

#include <iostream>


class Sample {
    private:
    int x, y;
    public:
    Sample () { }
    Sample (int a) : x(a) { }
    void display() {
        std::cout << x << std::endl;
    }
    Sample operator++() {
        this->x++;
        return *this;
    }
};

int main() {
    Sample s1 (11);
    ++s1;
    s1.display();
    return 0;
}
