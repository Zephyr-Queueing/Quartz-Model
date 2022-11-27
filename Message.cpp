#include <iostream>
#include <string>
#include <chrono>
#include "Message.h"

using namespace std;
using namespace std::chrono;

Message::Message() {}

string Message::serialize() {
    return string("");
}

Message Message::deserialize(const string &str) {
    Message msg = {};
    return msg;
}