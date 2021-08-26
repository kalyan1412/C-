
// print even and odd using condition variables

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
int x = 0;

bool is_even() {
	if (x %2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool is_odd() {
	if (x% 2 != 0) {
		return true;
	}
	else {
		return false;
	}
}
void even () {
	std::unique_lock<std::mutex> lock(m);
	while (x < 10) {
		cv.wait (lock, is_even);
		std::cout << x << " is even" << std::endl;
		x++;
		cv.notify_all();
	}
}

void odd () {
	std::unique_lock<std::mutex> lock(m);
	while (x < 10) {
		cv.wait (lock, is_odd);
		std::cout << x <<  " is odd" << std::endl;
		x++;
		cv.notify_all();
	}
}

int main() {
	std::thread t2 (odd);
	std::this_thread::sleep_for (std::chrono::seconds(2));
	std::thread t1 (even);
	t1.join();
	t2.join();
	return 0;
}
