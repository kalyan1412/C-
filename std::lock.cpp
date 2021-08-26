
// std::lock is used to recover Dead lock

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex m1,m2,m3,m4;

int x = 0;

void fun1 (int id) {
	std::lock(m1,m2);
	std::this_thread::sleep_for (std::chrono::seconds(2));
	std::lock(m3,m4);
	x++;
	m1.unlock();
	m2.unlock();
	m3.unlock();
	m4.unlock();
}


void fun2 (int id) {
	std::this_thread::sleep_for (std::chrono::seconds(1));
	std::lock(m3,m4,m1,m2);
	x++;
	m3.unlock();
	m4.unlock();
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
