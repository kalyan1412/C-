#include<iostream>
#include<cstring>

using namespace std;

class Student {
    private:
        char *str;
        int id;
        int len;
    public:
        Student (const char *x, int y) {
            len = strlen (x);
            str = new char[len+1];
            strcpy (str, x);
            id = y;
        }
        void change (const char *x);
        Student (const Student &obj) {
            cout << "Copy constructor" << endl;
            len = strlen (obj.str);
            str = new char[len+1];
            strcpy (str, obj.str);
            id = obj.id;
        }
        ~Student () {
            delete []str;
        }
        void display() {
            cout << "Student name=" << str << endl;
            cout << "Student id=" << id << endl;
        }
};
void Student ::change (const char *x) {
    delete []str;
    len = strlen (x);
    str = new char[len+1];
    strcpy (str, x);
}

int main() {
    Student s1 ("kalyan", 123);
    Student s2 = s1;
    s1.display();
    s2.display();
    s1.change ("kass");
    s1.display();
    s2.display();
    return 0;
}
