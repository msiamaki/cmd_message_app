#ifndef MESSAGES_H
#define MESSAGES_H

#include <iostream>
#include <cstring>
#include <chrono>

class BaseMessage {
protected:
    time_t sentDate;
    int senderId;

public:
    BaseMessage(int senderId);
    virtual ~BaseMessage() = default;

    virtual void display() const = 0;
    int getSenderId() const;
    int getDate() const;
    void printDate() const;
};

class SimpleMessage : public BaseMessage {
private:
    char message[200];

public:
    SimpleMessage(int senderId, const char *msg);
    ~SimpleMessage();

    void display() const override;
};

class PostMessage : public SimpleMessage {
private:
    char imagePath[200];

public:
    PostMessage(int senderId, const char *msg, const char *imgPath);
    ~PostMessage();

    void display() const override;
};

class VoteMessage : public BaseMessage {
private:
    char title[200];
    char options[10][200];
    int optionCount;

public:
    VoteMessage(int senderId, const char *voteTitle, const char optionsArray[][200], int count);
    ~VoteMessage();

    void display() const override;
};

class Messenger {
private:
    BaseMessage *messages[100];
    int messageCount;

public:
    Messenger();
    ~Messenger();

    void addMessage(BaseMessage *message);
    void displayChat() const;
};

#endif
