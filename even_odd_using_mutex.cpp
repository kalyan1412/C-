
// print even and odd using mutex's

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex m;
int x = 0;

void even () {
	while (x < 10) {
		m.lock();
		if (x%2 == 0) {
			std::cout << x << "is even" << std::endl;
			x++;
		}
		m.unlock();
	}
}

void odd () {
	while (x < 10) {
		m.lock();
		if (x%2 != 0) {
			std::cout << x << "is odd" << std::endl;
			x++;
		}
		m.unlock();
	}
}

int main() {
	std::thread t1 (even);
	std::thread t2 (odd);
	t1.join();
	t2.join();
	return 0;
}
