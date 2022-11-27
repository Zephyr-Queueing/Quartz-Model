#include <iostream>
#include <string>
#include <chrono>
#include "../ext/json.hpp"

#include "Message.h"

using nlohmann::json;
using std::string;
using std::chrono::milliseconds;

Message::Message() {}

string Message::serialize() {
    json j;
    j["priority"] = priority;
    j["data"] = data;
    j["enqueue_time"] = enqueue_time.count();
    j["dequeue_time"] = dequeue_time.count();
    return j.dump();
}

Message Message::deserialize(const string &str) {
    Message m = {};
    json j = json::parse(str);
    m.priority = j["priority"];
    m.data = j["data"];
    m.enqueue_time = milliseconds(j["enqueue_time"]);
    m.dequeue_time = milliseconds(j["dequeue_time"]);
    return m;
}
