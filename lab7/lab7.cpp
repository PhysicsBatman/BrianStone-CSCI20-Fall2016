#include <iostream>
using namespace std;

void Chorus() {
    cout << "Old MacDonald had a farm" << endl << "E-I-E-I-O" << endl;
}

void Verse(string animal, string sound) {
    cout << "And on his farm he had a " << animal << endl << "E-I-E-I-O" << endl;
    cout << "With a " << sound << " " << sound << " here" << endl << "And a " << sound << " " << sound << " there" << endl;
    cout << "Here a " << sound << ", there a " << sound << endl << "Everywhere a " << sound << " " << sound << endl;
}

int main() {
    Chorus();
    Verse("cow", "moo");
    Chorus();
    cout << endl;
    Chorus();
    Verse("duck", "quack");
    Chorus();
    cout << endl;
    Chorus();
    Verse("dog", "bark");
    Chorus();
}