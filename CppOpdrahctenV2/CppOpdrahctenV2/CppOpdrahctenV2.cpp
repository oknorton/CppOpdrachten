#include <iostream>
#include <thread>
#include "semaphore.h"

// Semaforen voor synchronisatie
semaphore resourceSemaphore(1);  // Er is één resource beschikbaar
semaphore printSemaphore(1);     // Er is één printresource beschikbaar

void ThreadFunction(int threadId) {
    resourceSemaphore.Wait();

    // Kritieke sectie
    std::cout << "Thread " << threadId << ": Start" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << threadId << ": Einde" << std::endl;

    resourceSemaphore.Signal();

    printSemaphore.Wait();

    std::cout << "Thread " << threadId << ": Print" << std::endl;

    printSemaphore.Signal();
}

int main() {
    std::thread t1(ThreadFunction, 1);
    std::thread t2(ThreadFunction, 2);
    std::thread t3(ThreadFunction, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
