
// Deque -> Double ended queue
// Deque are Sequence containers with the feature of expansion and contraction on the both ends.
// Similar to vectors, but these are more efficient in case of insertion and deletion.
// A queue is a data structure allows insertion only at end and deletion at front.
// the functions of deque are similar to vector with addition of push and pop operations at front and back.


#include <iostream>
#include <deque>
#include <iterator>
#include <vector>

void display (std::deque<int> &de) {
    for (std::deque <int> :: iterator k = de.begin(); k != de.end(); k++) {
        std::cout << *k << ",";
    }
    std::cout << "\n";
}

int main() {
    std::deque <int> d;
    std::cout << "The size of deque without insertion of elements = " << d.size() << std::endl; // 0
    d.push_back (10);
    d.push_front (15);
    d.push_back (30);
    d.push_front (5);
    display (d); // 5 15 10 30
    std::cout << "size is = " << d.size() << std::endl;
    std::cout << "front element = " << d.front() << std::endl;
    std::cout << "back element = " << d.back() << std::endl;
    std::cout << "element at posistion 2 = " << d.at(2) <<std::endl; // 10
    d.pop_front();
    d.pop_back();
    display (d); // 15 10
    if (d.empty()) {
        std::cout << "deque is empty" << std::endl;
    }
    else {
        std::cout << "deque is not empty" << std::endl;
    }
    d.clear();
    if (d.empty()) {
        std::cout << "deque is empty" << std::endl;
    }
    else {
        std::cout << "deque is not empty" << std::endl;
    }
    // assign
    d.assign (5, 6);
    display (d); // 6 6 6 6 6
    d.assign (d.begin(), d.end() -1);
    display (d); // 6 6 6 6
    // insert
    d.clear();
    d.push_back (5);
    d.push_front (2);
    d.push_back (9);
    d.push_front (0);
    display (d); // 0 2 5 9
    auto it = d.begin();
    advance (it, 2);
    d.insert (it, 4);
    display (d); // 0 2 4 5 9
    d.insert (it, 2, 3);
    display (d); // 0 2 3 3 4 5 9
    std::vector <int> vec = {1,1};
    it = d.begin() +1;
    d.insert (it, vec.begin(), vec.end());
    display (d); // 0 1 1 2 3 3 4 5 9
    // erase
    it = d.begin() + 3;
    d.erase (it);
    display (d); // 0 1 1 3 3 4 5 9
    it = d.begin() + 1;
    auto it2 = d.end();
    it2--;
    it2--;
    d.erase (it, it2);
    display (d); // 0 5 9
    return 0;
}
