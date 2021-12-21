#include <iostream>

class Product {
    public:
    virtual ~Product () { }
    virtual std::string operation () = 0;
};

class ConcreteProduct1 : public Product {
    public:
    std::string operation () {
        return "ConcreteProduct1";
    }
};

class ConcreteProduct2 : public Product {
    public:
    std::string operation () {
        return "ConcreteProduct2";
    }
};

class Creator{
    public:
    virtual ~Creator() { }
    virtual Product* factorymethod() = 0;
    void SomeOperation () {
        Product *p = this->factorymethod();
        std::cout << p->operation() << std::endl;
    }
};

class CreatorConcreteProduct1 : public Creator{
    public:
    Product* factorymethod() {
        return new ConcreteProduct1();
    }
};

class CreatorConcreteProduct2 : public Creator{
    public:
    Product* factorymethod() {
        return new ConcreteProduct2();
    }
};
void create_client (Creator *c) {
    c->SomeOperation();
}

int main() {
    Creator *x = new CreatorConcreteProduct1();
    create_client (x);
    Creator  *y = new CreatorConcreteProduct2();
    create_client (y);
    delete x;
    delete y;
    return 0;
}
