#include <iostream>
#include <chrono>

using namespace std;


class BaseMessage {
protected:
    time_t sentDate;
    int senderId;

public:
    BaseMessage(int senderId) : senderId(senderId) {
        auto now =  chrono::system_clock::now();
        sentDate = chrono::system_clock::to_time_t(now);
    }

    virtual void display() const = 0;
    int getSenderId() const { return senderId; }
    int getDate() const { return sentDate; }

    void printDate() const {
        cout << ctime(&this->sentDate);
    }
};
