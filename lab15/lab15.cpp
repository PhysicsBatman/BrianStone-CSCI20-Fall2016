// Brian Stone
// 10/25/16
// This program creates a menu with 10 different items for the user to choose from.
// The user may continue choosing items until they say they are done.
// The program then outputs the user's choices.

#include <iostream>
using namespace std;

int main() {
    int menu[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int input = -1;
    
    cout << "Welcome to the Color Bar! Here is our menu:" << endl;
    cout << "1. Red" << endl;
    cout << "2. Orange" << endl;
    cout << "3. Yellow" << endl;
    cout << "4. Green" << endl;
    cout << "5. Cyan" << endl;
    cout << "6. Blue" << endl;
    cout << "7. Violet" << endl;
    cout << "8. Magenta" << endl;
    cout << "9. White" << endl;
    cout << "10. Black" << endl;
    
    while(input != 0) {
        cout << "Enter the number of the color you'd like to order (0 if you are finished ordering): ";
        cin >> input;
        
        if (input >= 1 && input <= 10) {
            ++ menu[input - 1];
        }
    }
    
    cout << "Red: " << menu[0] << endl;
    cout << "Orange: " << menu[1] << endl;
    cout << "Yellow: " << menu[2] << endl;
    cout << "Green: " << menu[3] << endl;
    cout << "Cyan: " << menu[4] << endl;
    cout << "Blue: " << menu[5] << endl;
    cout << "Violet: " << menu[6] << endl;
    cout << "Magenta: " << menu[7] << endl;
    cout << "White: " << menu[8] << endl;
    cout << "Black: " << menu[9] << endl;
}