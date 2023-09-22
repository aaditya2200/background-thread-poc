#ifndef BACKGROUND_THREAD_POC_BGTHREAD_H
#define BACKGROUND_THREAD_POC_BGTHREAD_H
#include <thread>

std::thread create_background_thread(void *func());

#endif //BACKGROUND_THREAD_POC_BGTHREAD_H
