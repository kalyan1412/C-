//timed_mutex

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int x = 0; // global variable

std::timed_mutex m;

void fun (int id) {
	if (m.try_lock_for(std::chrono::seconds(1))) {
		x++;
		std::cout << "Thread " << id << " entered" << std::endl; 
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	else {
		std::cout << "Thread" << id << " didn't entered" << std::endl;
	}
}
int main() {
	std::thread t1 (fun, 1);
	std::thread t2 (fun, 2);
	t1.join();
	t2.join();
	std::cout << x << std::endl;
	return 0;
}
