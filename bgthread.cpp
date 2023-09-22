#include "bgthread.h"
#include <iostream>
#include <thread>

std::thread create_background_thread(void *function()) {
    std::thread bg_thread(function);
    bg_thread.detach();
    return bg_thread;
}
