
// recusrive mutex

#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex m;

int x = 0;


void fun (int loop_count) {

	if (loop_count <= 0) {
		return;
	}
	else {
		m.lock();
		x++;
		std::cout << "loop_count = " << loop_count << " x = " << x << std::endl;
		loop_count--;
		fun (loop_count);
		m.unlock();
	}
}
int main() {
	std::thread t1 (fun, 10);
	t1.join();
	return 0;
}
