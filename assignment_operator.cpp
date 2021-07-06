#include <iostream>

using namespace std;


class Sample {
        private:
                int x, *ptr;
        public:
                Sample (int a = 0, int b = 0) {
                        x = a;
                        ptr = new int(b);
                }
                void display () {
                        cout << x << "," << *ptr << endl;
                }
                Sample& operator=(Sample &obj) {
                        if (this != &obj) {
                                delete (this->ptr);
                                this->x = obj.x;
                                this->ptr = new int (*(obj.ptr));
                        }
                        return *this;
                }
                ~Sample () {
                        if (ptr) {
                        cout << "ptr=" << ptr << endl;
                        delete ptr;
                        }
                }
};

int main() {
        Sample s1 (10, 20);
        s1.display();
        Sample s2;
        s2 = s1;
        s2.display();
        return 0;
}
