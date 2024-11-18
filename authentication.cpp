#include "authentication.h"

using namespace std;

int login() {
    char username[100], password[100];
    cout << "Login:" << endl;
    while (true) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (int i = 0; i < userCount; ++i) {
            if (users[i].authenticate(username, password)) {
                cout << "Login successful! Welcome, " << users[i].getUsername() << "!" << endl;
                return users[i].getId();
            }
        }
        cout << "Invalid username or password. Please try again." << endl;
    }
}
