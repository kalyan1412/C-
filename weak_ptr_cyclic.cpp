// how to avoid cyclic dependency
/*
        Mother  (D , S)
        /   \
       /     \
    Daug(M)   Son(M)
*/



#include <iostream>
#include <memory>

class Son;
class Daughter;

class Mother {
    private:
    std::weak_ptr <Son> s1;
    std::weak_ptr <Daughter> d1;
    public:
    Mother() {
        std::cout << "mother Constructor called" << std::endl;
    }
    void set_son (std::shared_ptr <Son> &s) {
        s1 = s;
    }
    void set_daughter (std::shared_ptr <Daughter> &d) {
        d1 = d;
    }
    ~Mother() {
        std::cout << "Mother destructor called" << std::endl;
    }
};

class Son {
    private:
    std::shared_ptr <Mother> m;
    public:
    Son(std::shared_ptr <Mother> &x) {
        m = x;
    }
    ~Son() {
        std::cout << "Son destructor called" << std::endl;
    }
};

class Daughter {
    private:
    std::shared_ptr <Mother> m;
    public:
    Daughter (std::shared_ptr <Mother> &x) {
        m = x;
    }
    ~Daughter() {
        std::cout << "Daughter destructor called" << std::endl;
    }
};

int main() {
    std::shared_ptr <Mother> m = std::make_shared<Mother>();
    std::shared_ptr <Son> s = std::make_shared<Son> (m);
    std::shared_ptr <Daughter> d = std::make_shared<Daughter> (m);
    std::cout << "Mother ref count = " << m.use_count() << std::endl;
    m->set_son(s);
    m->set_daughter(d);
    return 0;
}
