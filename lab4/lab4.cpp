#include <iostream>
using namespace std;

int main()
{
    int cents;
    
    cout << "Welcome to CoinStar! To begin, deposit coins in the labeled slot." << endl;
    
    cin >> cents;
    
    cout << "You inserted " << cents << " cents." << endl;
    
    int quarters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = ((cents % 25) % 10) % 5;
    
    cout << "Quarters: " << quarters << endl << "Dimes: " << dimes << endl << "Nickels: " << nickels << endl << "Pennies: " << pennies << endl;
    
    int cash = cents * 0.891;
    int fee = cents - cash;
    
    cout << "Transaction fee: " << fee << " cents" << endl << "You receive: " << cash << " cents" << endl << "Have a nice day!";
}