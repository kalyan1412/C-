

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

struct reader_writer{
    mutex reader;
    mutex writer;
    int readers = 0;
};

reader_writer k1;

int x = 0;

void reader_lock (struct reader_writer &k) {
    k.reader.lock();
    k.readers++;
    
    if (k.readers == 1) {
        k.writer.lock();
    }
    
    k.reader.unlock();
}

void reader_unlock (struct reader_writer &k) {
    k.reader.lock();
    k.readers--;
    
    if (k.readers == 0) {
        k.writer.unlock();
    }
    
    k.reader.unlock();
}


void writer_lock (struct reader_writer &k) {
    k.writer.lock();
}

void writer_unlock(struct reader_writer &k) {
    k.writer.unlock();
}

void fun1 () {
    reader_lock (k1);
    std::this_thread :: sleep_for (std::chrono::seconds (2));
    reader_unlock (k1);
}

void fun2 () {
    reader_lock (k1);
    reader_unlock (k1);
}

void fun3() {
    writer_lock(k1);   
    x++;
    std::this_thread :: sleep_for (std::chrono::seconds (2));
    writer_unlock(k1);
}
 
int main() {
    thread t3 (fun3);
    thread t1 (fun1);
    thread t2 (fun2);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
    return 0;
}
