
// overloading + operator

#include <iostream>


class Sample {
    private:
    int x, y;
    public:
    Sample (int a, int b) : x(a), y (b) { }
    void display() {
        std::cout << x << "," << y << std::endl;
    }
    Sample operator+ (const Sample &obj) {
        this->x = this->x + obj.x;
        this->y = this->y + obj.y;
        return *this;
    }
};

int main() {
    Sample s1 (11, 22), s2 (10, 20);
    Sample s3 = s1 + s2;
    s3.display();
    return 0;
}
