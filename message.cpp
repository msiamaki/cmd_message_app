#include "message.h"

using namespace std;


BaseMessage::BaseMessage(int senderId) : senderId(senderId) {
    auto now = chrono::system_clock::now();
    sentDate = chrono::system_clock::to_time_t(now);
}

int BaseMessage::getSenderId() const { return senderId; }
int BaseMessage::getDate() const { return sentDate; }

void BaseMessage::printDate() const {
    cout << ctime(&this->sentDate);
}


SimpleMessage::SimpleMessage(int senderId, const char *msg) : BaseMessage(senderId) {
    strncpy(message, msg, 200);
}

SimpleMessage::~SimpleMessage() {

}

void SimpleMessage::display() const {
    printDate();
    cout << " | Sender ID: " << senderId << " | Message: " << message << endl;
}


PostMessage::PostMessage(int senderId, const char *msg, const char *imgPath)
    : SimpleMessage(senderId, msg) {
    strncpy(imagePath, imgPath, 200);
}

PostMessage::~PostMessage() {
    // The PostMessage destructor
}

void PostMessage::display() const {
    SimpleMessage::display();
    cout << " | Image Path: " << imagePath << endl;
}


VoteMessage::VoteMessage(int senderId, const char *voteTitle, const char optionsArray[][200], int count)
    : BaseMessage(senderId), optionCount(count) {
    strncpy(title, voteTitle, 200);
    for (int i = 0; i < count; i++) {
        strncpy(options[i], optionsArray[i], 200);
    }
}

VoteMessage::~VoteMessage() {
    // The destructor
}

void VoteMessage::display() const {
    printDate();
    cout << " | Sender ID: " << senderId << " | Vote Title: " << title << endl;
    for (int i = 0; i < optionCount; i++) {
        cout << "   Option " << i + 1 << ": " << options[i] << endl;
    }
}


Messenger::Messenger() : messageCount(0) {}

Messenger::~Messenger() {
    for (int i = 0; i < messageCount; i++) {
        delete messages[i];
    }
}

void Messenger::addMessage(BaseMessage *message) {
    if (messageCount < 100) {
        messages[messageCount++] = message;
    } else {
        cout << "Message limit reached!" << endl;
    }
}

void Messenger::displayChat() const {
    for (int i = 0; i < messageCount; i++) {
        messages[i]->display();
    }
}
