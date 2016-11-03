// Brian Stone
// 11/1/16
// This program creates usernames for a website based on the name that the user enters.

#include <iostream>
using namespace std;

int main() {
    string firstName;
    cout << "Please enter your first name (10 characters max): ";
    bool valid = false;
    while (!valid) {
        cin >> firstName;
        if (firstName.length() <= 10) {
            valid = true;
        }
        else {
            cout << "That name is too long. Please enter a shorter name: ";
        }
    }
    
    string lastName;
    cout << "Please enter your last name (20 characters max): ";
    valid = false;
    while (!valid) {
        cin >> lastName;
        if (lastName.length() <= 20) {
            valid = true;
        }
        else {
            cout << "That name is too long. Please enter a shorter name: ";
        }
    }
    
    if (firstName == lastName) {
        cout << endl << "WARNING: First and last name are the same!" << endl;
    }
    
    for (int i = 0; i < firstName.length(); ++ i) {
        firstName[i] = tolower(firstName[i]);
    }
    for (int i = 0; i < lastName.length(); ++ i) {
        lastName[i] = tolower(lastName[i]);
    }
    
    string userName1 = firstName.substr(0, 2) + lastName;
    
    string userName2 = firstName + lastName;
    
    string userName3 = firstName[0] + lastName;
    
    cout << endl
         << "Your choices of username are:" << endl
         << "1. " << userName1 << endl
         << "2. " << userName2 << endl
         << "3. " << userName3 << endl
         << "Please enter the number of your desired username: ";
    int input = 0;
    while (input < 1 || input > 3) {
        cin >> input;
    }
    switch(input) {
        case 1:
            cout << "Welcome, " << userName1 << "!";
            break;
        case 2:
            cout << "Welcome, " << userName2 << "!";
            break;
        case 3:
            cout << "Welcome, " << userName3 << "!";
            break;
    }
}