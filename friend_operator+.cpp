

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
    friend Sample operator+ (Sample const &obj1, Sample  const &obj);
};


Sample operator+ (Sample const &obj1, Sample const &obj) {
        Sample temp;
        temp.x = obj1.x + obj.x;
        temp.y = obj1.y + obj.y;
        return temp;
}
int main() {
    Sample s1 (11, 22), s2 (10, 20);
    Sample s3 = s1 + s2;
    s3.display();
    return 0;
}
