// Brian Stone
// 10/25/16
// This program creates a menu with 10 different items for the user to choose from.
// The user may continue choosing items until they say they are done.
// If an item runs out, the user may not obtain any more of that item.
// When the user says that they are done, the program outputs the user's choices and the total cost.

#include <iostream>
using namespace std;

int main() {
    int inventory[10] = {6, 3, 3, 6, 3, 6, 3, 3, 2, 6};
    int purchases[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float price[10] = {1, 2, 2, 1, 2, 1, 2, 2, 3, 1};
    float totalCost = 0;
    int input = -1;
    
    cout << "Welcome to the Color Bar! Here is our menu:" << endl;
    cout << "1. Red ($1)" << endl;
    cout << "2. Orange ($2)" << endl;
    cout << "3. Yellow ($2)" << endl;
    cout << "4. Green ($1)" << endl;
    cout << "5. Cyan ($2)" << endl;
    cout << "6. Blue ($1)" << endl;
    cout << "7. Violet ($2)" << endl;
    cout << "8. Magenta ($2)" << endl;
    cout << "9. White ($3)" << endl;
    cout << "10. Black ($1)" << endl;
    
    while(input != 0) {
        cout << "Enter the number of the color you'd like to order (0 if you are finished ordering): ";
        cin >> input;
        
        if (input >= 1 && input <= 10) {
            if (inventory[input - 1] - purchases[input - 1] > 0) {
                ++ purchases[input - 1];
                totalCost = totalCost + price[input - 1];
                cout << "Price: $" << price[input - 1] << endl;
                cout << "Amount left: " << inventory[input - 1] - purchases[input - 1] << endl;
            }
            else {
                cout << "Sorry, we've run out of that color!" << endl;
            }
        }
    }
    
    cout << "Red: " << purchases[0] << endl;
    cout << "Orange: " << purchases[1] << endl;
    cout << "Yellow: " << purchases[2] << endl;
    cout << "Green: " << purchases[3] << endl;
    cout << "Cyan: " << purchases[4] << endl;
    cout << "Blue: " << purchases[5] << endl;
    cout << "Violet: " << purchases[6] << endl;
    cout << "Magenta: " << purchases[7] << endl;
    cout << "White: " << purchases[8] << endl;
    cout << "Black: " << purchases[9] << endl;
    
    cout << "Total cost: $" << totalCost << endl;
}