#include <iostream>
using namespace std;

int main() {
    struct MonsterStruct {
        string name;
        string head;
        string eyes;
        string ears;
        string nose;
        string mouth;
    };
    
    MonsterStruct monster;
    
    cout << "Describe the monster." << endl;
    cout << "Name: " << endl;
    cin >> monster.name;
    cout << "Head: " << endl;
    cin >> monster.head;
    cout << "Eyes: " << endl;
    cin >> monster.eyes;
    cout << "Ears: " << endl;
    cin >> monster.ears;
    cout << "Nose: " << endl;
    cin >> monster.nose;
    cout << "Mouth: " << endl;
    cin >> monster.mouth;
    
    cout << "Name: " << monster.name << endl << "Head: " << monster.head << endl << "Eyes: " << monster.eyes << endl << "Ears: " << monster.ears << endl << "Nose: " << monster.nose << endl << "Mouth: " << monster.mouth;
}