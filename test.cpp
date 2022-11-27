#include <string>
#include <iostream>

#include "Message.h"

using namespace std;

bool test_serialize();
bool test_deserialize();

int main(int argc, char** argv) {
    if (!test_serialize()) cout << "FAILED: test_serialize()" << endl;
    if (!test_deserialize()) cout << "FAILED: test_deserialize()" << endl;
    return EXIT_SUCCESS;
}

bool test_serialize() {
    Message msg = { 1, string("mydata"), milliseconds(1000), milliseconds(1000) };
    string msg_json = msg.serialize();
    return msg_json == string("{\"data\":\"mydata\",\"dequeue_time\":1000,\"enqueue_time\":1000,\"priority\":1}");
}

bool test_deserialize() {
    Message msg = { 1, string("mydata"), milliseconds(1000), milliseconds(1000) };
    string msg_json = msg.serialize();
    Message msg_parsed = msg.deserialize(msg_json);
    return msg.enqueue_time == msg_parsed.enqueue_time &&
           msg.dequeue_time == msg_parsed.dequeue_time &&
           msg.data == msg_parsed.data &&
           msg.priority == msg_parsed.priority;
}
