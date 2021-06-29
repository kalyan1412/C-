

#include <iostream>

using namespace std;


// kalyan
// kalyan

int com (char *ptr1, char *ptr2) {
   while (*ptr1 == *ptr2) {
       if (*ptr1 == '\0' && *ptr2 == '\0') {
           return 0;
       }
       ptr1++;
       ptr2++;
   }
   return 1;
}
int main() {
    char str1[10] = "kalyan";
    char str2[10] = "kalya";
    if (com (str1, str2) == 0) {
        cout << "strings are equal\n";
    }
    else {
        cout << "Strings are not equal\n";
    }
    return 0;
}
