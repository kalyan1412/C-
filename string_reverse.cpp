

#include <iostream>

using namespace std;

char* reverse (char *ptr) {
    char *p1 = ptr, *p2 = ptr;
    int count = 0;
    while (*p2) {
        count++;
        p2++;
    }
    p2 = p1;
    for (int i = 0; i < count -1 ; i++) {
        p2++;
    }
    while (p1 < p2) {
        *p1 = *p1 ^ *p2;
        *p2 = *p1 ^ *p2;
        *p1 = *p1 ^ *p2;
        p1++;
        p2--;
    }
    return ptr;
    
}


int main() {
    char str[] = "kalyan";
    cout << "Reverse of a string=" << reverse (str) << endl;
    return 0;
}

