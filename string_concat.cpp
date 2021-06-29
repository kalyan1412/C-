

#include <iostream>

using namespace std;


void concat (char *ptr1, char *ptr2) {
    while (*ptr1) {
        ptr1++;
    }
    while (*ptr2) {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
}
int main() {
    char str1[10] = "kalyan";
    char str2[10] = "babu";
    concat (str1, str2);
    cout << str1 << endl;
    return 0;
}
