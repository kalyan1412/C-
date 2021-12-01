
// list is a sequence container, that allows non-contiguous memory location.
// As compared to vector list is a slow traversal, but once a element is found.. insertion and deletion are so quick.
// We can say list it is nothing but double linked list.

#include <iostream>
#include <list>
#include <iterator>

void display (std::list <int> &l) {
    for (auto i : l) {
        std::cout << i << ",";
    }
    std::cout << "\n";
}

int main() {
    std::list <int> l1;
    std::list <int> l2;
    std::cout << "Initial size of the list = " << l1.size() << std::endl;
    for (int i = 1; i <= 5; i++) {
        l1.push_back (i);
        l2.push_front (i);
    }
    display (l1); // 1 2 3 4 5
    display (l2); // 5 4 3 2 1
    std::cout << "size of after inserting the elements = " << l1.size() << std::endl;
    if (l1.empty()) {
        std::cout << "list l1 is empty" << std::endl;
    }
    else {
        std::cout << "list l1 is not empty" << std::endl;
    }
    std::cout << "front element = " << l1.front() << std::endl; // 1
    std::cout << "back element = " << l1.back() << std::endl; // 5
    l2.pop_back(); // 1 is removed from the list
    l2.pop_front(); // 5 is removed from the list
    display (l2); // 4 3 2
    // assign
    // it assigns new values to a list.
    l2.clear();
    l2.assign (5, 10);
    display (l2); // 10 10 10 10 10
    l2.clear();
    auto it = l1.end();
    it--;
    l2.assign (l1.begin(), it);
    display (l2); // 1 2 3 4
    // insert
    l2.clear();
    l2.assign (3, 2);
    display (l2); // 2 2 2
    it = l2.begin();
    advance (it,2); // -> it = l2.begin() +2;
    it = l2.insert (it, 5);
    display (l2); // 2 2 5 2
    l2.insert (it, 2, 3);
    display (l2); // 2 2 3 3 5 2
    // erase 
    // used to remove a single element or range of elements from the list
    it = l2.begin();
    advance (it, 2);
    l2.erase (it);
    display (l2); // 2 2 3 5 2 
    it = l2.begin();
    advance (it, 1);
    auto it2 = l2.end();
    it2--;
    l2.erase (it, it2);
    display (l2); // 2 2 
    it = l2.begin();
    advance(it, 1);
    l2.insert (it, 3);
    display (l2); // 2 3 2 
    l2.remove (2);
    display (l2); // 3
    return 0;
}
