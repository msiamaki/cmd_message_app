#include <iostream>
#include <cstring>
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


class SimpleMessage : public BaseMessage {
private:
    char message[200];

public:
    SimpleMessage(int senderId, const char *msg) : BaseMessage(senderId) {
        strncpy(message, msg, 200);
    }

    ~SimpleMessage() {
        delete message;
    }

    void display() const override {
        printDate();
        cout << " | Sender ID: " << senderId << " | Message: " << message << endl;
    }
};


class PostMessage : public SimpleMessage {
private:
    char imagePath[200];

public:
    PostMessage(int senderId, const char *msg, const char *imgPath)
        : SimpleMessage(senderId, msg) {
        strncpy(imagePath, imgPath, 200);
    }

    ~PostMessage() {
        delete imagePath;
    }

    void display() const override {
        SimpleMessage::display();
        cout << " | Image Path: " << imagePath << endl;
    }
};


class VoteMessage : public BaseMessage {
private:
    char title[200];
    char options[10][200];
    int optionCount;

public:
    VoteMessage(int senderId, const char *voteTitle, const char optionsArray[][200], int count)
        : BaseMessage(senderId), optionCount(count) {
        strncpy(title, voteTitle, 200);
        for (int i = 0; i < count; i++) {
            strncpy(options[i], optionsArray[i], 200);
        }
    }

    ~VoteMessage() {
        delete title, options;
    }

    void display() const override {
        printDate();
        cout << " | Sender ID: " << senderId << " | Vote Title: " << title << endl;
        for (int i = 0; i < optionCount; i++) {
            cout << "   Option " << i + 1 << ": " << options[i] << endl;
        }
    }
};


class Messenger {
private:
    BaseMessage *messages[100];
    int messageCount;

public:
    Messenger() : messageCount(0) {}

    ~Messenger() {
        delete messages;
    }

    void addMessage(BaseMessage *message) {
        if (messageCount < 100) {
            messages[messageCount++] = message;
        } else {
            cout << "Message limit reached!" << endl;
        }
    }

    void displayChat() const {
        for (int i = 0; i < messageCount; i++) {
            messages[i]->display();
        }
    }
};
