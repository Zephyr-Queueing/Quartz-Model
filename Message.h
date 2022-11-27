#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct Message {
    int priority;
    string data;
    milliseconds enqueue_time;
    milliseconds dequeue_time;

    Message();

    string serialize();
    static Message deserialize(const string &msg);
} Message;
