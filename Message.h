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

    static string serialize();
    static Message deserialize(const string &msg);
} Message;
