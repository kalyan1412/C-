// weak pointer

#include <iostream>
#include <memory>

int main() {
    std::shared_ptr <int> s1 = std::make_shared<int>(10);
    std::cout << *s1 << std::endl;
    std::weak_ptr <int> w1(s1);
    if (w1.expired()) {
        std::cout << "it's expired" << std::endl;
    } else {
        std::cout << "not yet expired" << std::endl;
    }
    std::cout << "shared_ptr ref count=" << s1.use_count() << std::endl; // 1
    std::cout << "weak ptr ref count after assigning shared ptr = " << w1.use_count() << std::endl; // 1
    if (std::shared_ptr <int> s2 = w1.lock()) {
        std::cout << *s2 << std::endl;
        std::cout << "shared_ptr s2 use_count = " << s2.use_count() << std::endl;
    }
    std::cout << "shared_ptr ref count after if = " << s1.use_count() << std::endl; //1
    s1.reset();
    if (w1.expired()) {
        std::cout << "it's expired" << std::endl;
    } else {
        std::cout << "not yet expired" << std::endl;
    }
    return 0;
}
