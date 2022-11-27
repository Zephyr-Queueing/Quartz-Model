#include <iostream>
#include <string>
#include <chrono>

using std::string;
using std::chrono::milliseconds;

typedef struct Message {
    int priority;
    string data;
    milliseconds enqueue_time;
    milliseconds dequeue_time;

    Message();
    Message(int p, const string &d, const milliseconds &en, const milliseconds &de)
        : priority(p), data(d), enqueue_time(en), dequeue_time(de) {};

    string serialize();
    static Message deserialize(const string &msg);
} Message;
