# Execution Instructions
## Build this program with the following command
```shell
g++ bgthread.h
g++ bgthread.cpp
g++ poc.cpp -lpthread
```

This program basically creates a background thread, and detaches it.
Whenever we reach the count of 50, we tell the thread it can do it's work.
This can be used in our context as a dedicated checkpointing thread.