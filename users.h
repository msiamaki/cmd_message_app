#ifndef USER_H
#define USER_H

#include <cstring>

class User {
private:
    int id;
    char username[100];
    char password[100];

public:
    User(int userId, const char *userName, const char *pass);
    ~User();

    int getId() const;
    const char *getUsername() const;
    bool authenticate(const char *enteredUsername, const char *enteredPassword) const;
};


extern User users[];
extern const int userCount;

#endif
