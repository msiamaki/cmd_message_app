#include "users.h"


User::User(int userId, const char *userName, const char *pass) : id(userId) {
    strncpy(username, userName, 100);
    strncpy(password, pass, 100);
}

User::~User() {
    // User destructor
}

int User::getId() const {
    return id;
}

const char *User::getUsername() const {
    return username;
}

bool User::authenticate(const char *enteredUsername, const char *enteredPassword) const {
    return strcmp(username, enteredUsername) == 0 && strcmp(password, enteredPassword) == 0;
}


User users[] = {
    User(0, "Bagher", "12345"),
    User(1, "Ali", "password")
};

const int userCount = sizeof(users) / sizeof(users[0]);
