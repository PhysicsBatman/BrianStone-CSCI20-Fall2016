#include <iostream>
using namespace std;

double ToKilo(double pounds) {  // Converts pounds into kilograms
    return pounds / 2.20462;
}

double ToPounds(double kilos) { // Converts kilograms into pounds
    return kilos * 2.20462;
}

int main() {
    double kilos;
    cout << "Input an amount of kilograms:" << endl;
    cin >> kilos;                                                                       // Assigns input to kilograms variable
    cout << kilos << " kilograms is equal to " << ToPounds(kilos) << " pounds" << endl; // Describes equivalence
    
    double pounds;
    cout << "Input an amount in pounds:" << endl;
    cin >> pounds;                                                                      // Assigns input to pounds variable
    cout << " pounds is equal to " << ToKilo(pounds) << " kilograms" << endl;           // Describes equivalence
}