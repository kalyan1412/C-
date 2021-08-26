// why we need thread

#include <iostream>
#include <thread>
#include <mutex>

void calculate_even(long int i, long int j) {
	long int x = 0;
	for (;i < j; i++) {
		if (i%2==0) {
			x += i;
		}
	}
	std::cout << "even_count=" << x << std::endl;
}

void calculate_odd(int i, int j) {
	long int x = 0;
	for (;i < j; i++) {
		if (i%2 != 0) {
			x += i;
		}
	}
	std::cout << "odd_count=" << x << std::endl;
}

int main() {
	long int lower = 0, upper = 1999999;
	std::thread t1(calculate_even, lower, upper);
	std::thread t2(calculate_odd, lower, upper);
	t1.join();
	t2.join();
	return 0;
}
