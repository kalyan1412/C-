// binary semaphore

#include <iostream>
#include <thread>
#include <chrono>

int s = 1, x = 0;

void stop () {
	s = s-1;
	while (s < 0) ;
}

void wake_up() {
	s = s+1;
}

void fun (int id) {
	std::cout << "Thread id : " << id << " entered" << std::endl;
	stop();
	x++;
	std::this_thread::sleep_for (std::chrono::seconds(2));
	wake_up();
	std::cout << "Thread id : " << id << " exited" << std::endl;
}

int main() {
	std::thread t1 (fun, 1);
	std::thread t2 (fun, 2);
	t1.join();
	t2.join();
	std::cout << "x=" << x << std::endl;
    return 0;
}
