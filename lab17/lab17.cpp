// Brian Stone
// 10/27/16
// This program creates usernames for a website based on the name that the user enters.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char firstName[11];
    cout << "Please enter your first name (10 characters max): ";
    bool valid = false;
    while (!valid) {
        cin >> firstName;
        if (strlen(firstName) <= 10) {
            valid = true;
        }
        else {
            cout << "That name is too long. Please enter a shorter name: ";
        }
    }
    
    char lastName[21];
    cout << "Please enter your last name (20 characters max): ";
    valid = false;
    while (!valid) {
        cin >> lastName;
        if (strlen(lastName) <= 20) {
            valid = true;
        }
        else {
            cout << "That name is too long. Please enter a shorter name: ";
        }
    }
    
    if (strcmp(firstName, lastName) == 0) {
        cout << endl << "WARNING: First and last name are the same!" << endl;
    }
    
    for (int i = 0; i < strlen(firstName); ++ i) {
        firstName[i] = tolower(firstName[i]);
    }
    for (int i = 0; i < strlen(lastName); ++ i) {
        lastName[i] = tolower(lastName[i]);
    }
    
    char userName1[23] = "";
    strncpy(userName1, firstName, 2);
    strcat(userName1, lastName);
    
    char userName2[31] = "";
    strcpy(userName2, firstName);
    strcat(userName2, lastName);
    
    char userName3[22] = "";
    strncpy(userName3, firstName, 1);
    strcat(userName3, lastName);
    
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