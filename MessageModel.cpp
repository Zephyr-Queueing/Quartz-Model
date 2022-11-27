#include <iostream>

struct Message {
    int priority;
    std::string data;
    uint32_t enqueue_time;
    uint32_t dequeue_time;
};
