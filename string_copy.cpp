

#include <iostream>

using namespace std;


void copy (char *ptr1, char *ptr2) {
    while (*ptr2) {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
}
int main() {
    char str1[10] = "kalyaN";
    char str2[10];
    copy (str2, str1);
    cout << str2 << endl;
    return 0;
}
