cmake_minimum_required(VERSION 3.26)
project(background_thread_poc)

set(CMAKE_CXX_STANDARD 17)

add_library(background_thread_poc bgthread.cpp
        poc.cpp)
