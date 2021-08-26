//try_lock

#include <iostream>
#include <thread>
#include <mutex>

int x = 0; // global variable

std::mutex m;

void fun () {
	for (int i =0; i < 200000; i++) {
		m.try_lock();
		x++;
		m.unlock();
	}
}

int main() {
	std::thread t1 (fun);
	std::thread t2 (fun);
	t1.join();
	t2.join();
	std::cout << x << std::endl;
	return 0;
}
