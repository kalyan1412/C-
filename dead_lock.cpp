
// Dead lock

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex m1,m2;

int x = 0;

void fun1 (int id) {
	m1.lock();
	std::this_thread::sleep_for (std::chrono::seconds(2));
	m2.lock();
	x++;
	m1.unlock();
	m2.unlock();
}


void fun2 (int id) {
	m2.lock();
	m1.lock();
	x++;
	m2.unlock();
	m1.unlock();
}

int main() {
	std::thread t1 (fun1, 1);
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::thread t2 (fun2, 2);
	t1.join();
	t2.join();
	std::cout << x << std::endl;
	return 0;
}
