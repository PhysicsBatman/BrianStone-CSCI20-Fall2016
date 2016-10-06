#include <iostream>
using namespace std;

int main() {
    char outdoors;
    cout << "Do you like the outdoors? (Y or N)" << endl;
    cin >> outdoors;
    if (outdoors == 'Y' || outdoors == 'y') {
        outdoors = 't';
    }
    else if (outdoors == 'N' || outdoors == 'n') {
        outdoors = 'f';
    }
    switch(outdoors) {
        case 't':
            char running;
            cout << "Do you like to run? (Y or N)" << endl;
            cin >> running;
            if (running == 'Y' || running == 'y') {
                running = 't';
            }
            else if (running == 'N' || running == 'n') {
                running = 'f';
            }
            switch(running) {
                case 't':
                    cout << "You are a horse!" << endl;
                    break;
                case 'f':
                    cout << "You are a turtle!" << endl;
                    break;
                default:
                    cout << "You are a rock!" << endl;
                    break;
            }
            break;
        case 'f':
            char cheese;
            cout << "Do you like cheese? (Y or N)" << endl;
            cin >> cheese;
            if (cheese == 'Y' || cheese == 'y') {
                cheese = 't';
            }
            else if (cheese == 'N' || cheese == 'n') {
                cheese = 'f';
            }
            switch(cheese) {
                case 't':
                    cout << "You are a mouse!" << endl;
                    break;
                case 'f':
                    char swimming;
                    cout << "Do you like to swim? (Y or N)" << endl;
                    cin >> swimming;
                    if (swimming == 'Y' || swimming == 'y') {
                        swimming = 't';
                    }
                    else if (swimming == 'N' || swimming == 'n') {
                        swimming = 'f';
                    }
                    switch(swimming) {
                        case 't':
                            cout << "You are a fish!" << endl;
                            break;
                        case 'f':
                            cout << "You are a cat!" << endl;
                            break;
                        default:
                            cout << "You are a rock!" << endl;
                            break;
                    }
                    break;
                default:
                    cout << "You are a rock!" << endl;
                    break;
            }
            break;
        default:
            cout << "You are a rock!" << endl;
            break;
    }
}