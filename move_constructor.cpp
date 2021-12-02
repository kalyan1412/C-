#include <iostream>
#include <cstring>

class Sample {
    private:
        char *str;
        int len;
    public:
        Sample (const char *ptr = nullptr) {
            len = strlen(ptr);
            str = new char [len+1];
            strcpy (str, ptr);
        }
        void display() {
            std::cout << "name = " << str << std::endl;
        }
        Sample (const Sample &obj) { // copy constructor
            std::cout << "copy" << std::endl;
            len = obj.len;
            str = new char [len+1];
            strcpy (str, obj.str);
        }
        void change (const char *ptr = nullptr) {
            delete str;
            len = strlen (ptr);
            str = new char [len+1];
            strcpy (str, ptr);
        }
        Sample (Sample &&obj) {
            std::cout << "move" << std::endl;
            len = obj.len;
            str = new char [len+1];
            strcpy (str, obj.str);
            obj.str = nullptr;
        }
        ~Sample () {
            delete str;
        }
};

Sample create ()
{
    Sample s ("oracle");
    return s;
}
int main() {
    Sample s1 ("kalyan");
    s1.display();
    Sample s2 = s1;
    s2.display();
    s2.change("kass");
    s2.display();
    s1.display();
    Sample s3 (std::move(create()));
    s3.display();
    return 0;
}
