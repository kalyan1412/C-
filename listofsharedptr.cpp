
// how to create a list of shared pointers

#include <iostream>
#include <memory>
#include <list>

class Sample {
    private:
    int x;
    public:
    Sample (int x = 0) : x (x) {
    }
    int get() {
        return x;
    }
    ~Sample () { }
};

int main() {
    std::list <std::shared_ptr <Sample >> k;
     for (int i = 1; i <= 5; i++) {
        k.push_back(std::make_shared<Sample> (i));
    }
   
    for (const auto & i : k) {
        std::cout << (*i).get() << std::endl;
    }
    return 0;
}
