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
std::queue<int, std::vector<int> > messages;
int gElements = 0;

void *perform_checkpoint() {
    std::unique_lock<std::mutex> lock(mutex);
    // do some checkpoint
    while (!ready) {
        cv.wait(lock);
    }
    // perform the actual checkpoint logic
    for (int i = 0; i < gElements; ++i) {
        std :: cout << messages.front() << " ";
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
		gElements=50;
            std::lock_guard<std::mutex> lock(mutex);
            ready = true;
            cv.notify_one();
        }
    }
    return 0;
}

