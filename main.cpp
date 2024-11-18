#include <iostream>
#include "authentication.h"
#include "message.h"

using namespace std;


int main() {
    Messenger chat;

    int loggedInUserId = login();
    bool running = true;

    while (running) {
        cout << "\nMenu:\n"
             << "1. Send Simple Message\n"
             << "2. Send Post Message\n"
             << "3. Send Vote Message\n"
             << "4. Display Chat\n"
             << "5. Exit\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;

        switch (option) {
        case 1: {
            char msg[200];
            cout << "Enter your message: ";
            cin.ignore();
            cin.getline(msg, 200);
            SimpleMessage *message = new SimpleMessage(loggedInUserId, msg);
            chat.addMessage(message);
            break;
        }
        case 2: {
            char msg[200], imgPath[200];
            cout << "Enter your message: ";
            cin.ignore();
            cin.getline(msg, 200);
            cout << "Enter image path: ";
            cin.getline(imgPath, 200);
            PostMessage *post = new PostMessage(loggedInUserId, msg, imgPath);
            chat.addMessage(post);
            break;
        }
        case 3: {
            char title[200], options[10][200];
            int optionCount;
            cout << "Enter vote title: ";
            cin.ignore();
            cin.getline(title, 200);
            cout << "How many options (max 10): ";
            cin >> optionCount;
            cin.ignore();
            for (int i = 0; i < optionCount; ++i) {
                cout << "Enter option " << i + 1 << ": ";
                cin.getline(options[i], 200);
            }
            VoteMessage *vote = new VoteMessage(loggedInUserId, title, options, optionCount);
            chat.addMessage(vote);
            break;
        }
        case 4:
            cout << "\nChat Messages:\n";
            chat.displayChat();
            break;
        case 5:
            running = false;
            break;
        default:
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}
