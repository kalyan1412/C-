// new, delete , -> , * operator

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
    void *operator new (size_t size) {
        std::cout << "new" << std::endl;
        void *p;
        p = malloc(size);
        return p;
    }
    void operator delete(void *p) {
        std::cout << "delete" << std::endl;
        free (p);
    }
    Sample* operator->() {
        std::cout << "->" << std::endl;
        return this;
    }
    Sample& operator*() {
        std::cout << "*" << std::endl;
        return *this;
    }
};

int main() {
    Sample *s = new Sample (10, 12);
    Sample s1(1, 2);
    s1->display();
    (*s1).display();
    delete s;
    return 0;
}
