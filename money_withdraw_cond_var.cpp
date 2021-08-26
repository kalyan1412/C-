
// Money withdraw problem

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
int balance = 0;

bool check_balance () {
	if (balance > 0) {
		return true;
	}
	else {
		return false;
	}
}

void add_money (int amount) {
	std::lock_guard<std::mutex> lg (m);
	balance += amount;
	cv.notify_all();
}

void with_draw(int amount) {
	std::unique_lock<std::mutex> lock (m);
	cv.wait(lock, check_balance);
	if (balance > amount) {
		balance -= amount;
		std::cout << "money withdrawn = " << amount << std::endl;
		std::cout << "remaining balance = " << balance << std::endl; 
	}
	else {
		std::cout << "Insuffient balance = " << balance << std::endl;
	}
}

int main() {
	std::thread t1 (with_draw, 400);
	std::this_thread::sleep_for (std::chrono::seconds(2));
	std::thread t2 (add_money, 500);
	t1.join();
	t2.join();
	return 0;
}
