#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "What is your name?" << endl;
    getline(cin, name);
    
    char marriage;
    cout << "Are you married? (Y or N)" << endl;
    cin >> marriage;
    
    double wages;
    double interest;
    double unemployment;
    cout << "How much have you earned in wages?" << endl;
    cin >> wages;
    cout << "How much have you earned in interest?" << endl;
    cin >> interest;
    cout << "How much have you earned through unemployment?" << endl;
    cin >> unemployment;
    
    double adjGrossIncome;
    if (marriage == 'Y') {
        adjGrossIncome = wages + interest + unemployment - 20000;
    }
    else {
        adjGrossIncome = wages + interest + unemployment - 10000;
    }
    
    double tax;
    if (adjGrossIncome <= 0) {
        tax = 0;
    }
    else {
        if (marriage == 'Y') {
            if (adjGrossIncome <= 17850) {
                tax = adjGrossIncome * 0.1;
            }
            else if (adjGrossIncome <= 72500) {
                tax = 1785 + ((adjGrossIncome - 17850) * 0.15);
            }
            else {
                tax = 9982.5 + ((adjGrossIncome - 72500) * 0.28);
            }
        }
        else {
            if (adjGrossIncome <= 8925) {
                tax = adjGrossIncome * 0.1;
            }
            else if (adjGrossIncome <= 36250) {
                tax = 892.5 + ((adjGrossIncome - 8925) * 0.15);
            }
            else if (adjGrossIncome <= 87850) {
                tax = 4991.25 + ((adjGrossIncome - 36250) * 0.25);
            }
            else {
                tax = 17891.25 + ((adjGrossIncome - 87850) * 0.28);
            }
        }
    }
    
    double amtWithheld;
    cout << "What amount are you withholding?" << endl;
    cin >> amtWithheld;
    
    double amtOwed = tax - amtWithheld;
    
    cout << "Name: " << name << endl;
    cout << "Total Gross Adjusted Income: $" << adjGrossIncome << endl;
    if (amtOwed >= 0) {
        cout << "Total tax owed: $" << amtOwed << endl;
    }
    else {
        cout << name << " is entitled to a REFUND of $" << amtOwed * -1 << endl;
    }
}