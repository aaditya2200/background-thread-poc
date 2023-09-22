//
// Created by Aaditya Rangarajan on 9/22/23.
//
#include "bgthread.h"
#include <thread>
#include <condition_variable>
#include <iostream>
#include <queue>

std::condition_variable cv;
std::mutex mutex;
bool ready = false;
std::queue<int> messages;
int gElements = 0;

void *perform_checkpoint() {
    std::unique_lock<std::mutex> lock(mutex);
    // do some checkpoint
    while (!ready) {
        cv.wait(lock);
    }
std::cout << "\n" << messages.front();
    // perform the actual checkpoint logic
	std::cout << "Performing checkpoint\n";
    for (int i = 0; i < gElements; ++i) {
        std :: cout << messages.front() << " ";
	messages.pop();
    }
    return nullptr;
}

int main() {
    std::thread checkpoint_thread = create_background_thread(&perform_checkpoint);
    int count = 0;
    while (count < 100) {
        count++;
        messages.push(count);
        std :: cout << "\nMain thread incrementing counter\n";
        if (count == 50) {
		gElements=count;
            std::lock_guard<std::mutex> lock(mutex);
            ready = true;
            cv.notify_one();
        }
    }
	std :: cout  << "\nElements left in queue " << messages.size();
    return 0;
}

