

#include <iostream>


class Sample {
    private:
    int x, y;
    public:
    Sample () { }
    Sample (int a, int b) : x(a), y (b) { }
    void display() {
        std::cout << x << "," << y << std::endl;
    }
    friend Sample operator+ (Sample const &obj1, int);
};


Sample operator+ (Sample const &obj1, int a) {
        Sample temp;
        temp.x = obj1.x + a;
        temp.y = obj1.y ;
        return temp;
}
int main() {
    Sample s1 (11, 22);
    Sample s3 = s1 + 12;
    s3.display();
    return 0;
}
