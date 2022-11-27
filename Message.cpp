#include <string>
#include <chrono>
#include "ext/json.hpp"

#include "Message.h"

using nlohmann::json;
using std::string;
using std::chrono::milliseconds;

string Message::serialize() {
    json j;
    j["priority"] = priority;
    j["data"] = data;
    j["enqueueTime"] = enqueueTime.count();
    j["dequeueTime"] = dequeueTime.count();
    return j.dump();
}

Message Message::deserialize(const string &str) {
    Message m = {};
    json j = json::parse(str);
    m.priority = j["priority"];
    m.data = j["data"];
    m.enqueueTime = milliseconds(j["enqueueTime"]);
    m.dequeueTime = milliseconds(j["dequeueTime"]);
    return m;
}
