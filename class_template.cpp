

// class template

#include <iostream>

template <class T>
class Sample {
    private:
    T x;
    public:
    Sample (T y = 0 ) : x (y) { }
    void set (T y);
    T get () { return x; }
};

template <class T>
void Sample <T> :: set (T y) {
    x = y;
}


int main() {
    Sample <int> *s = new Sample <int> (10);
    s->set (10);
    std::cout << s->get() << std::endl;
    return 0;
}
    
