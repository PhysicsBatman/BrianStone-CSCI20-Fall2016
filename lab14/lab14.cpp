#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;
    cout << "Enter numbers separated by spaces and terminated with a negative number." << endl;
    cin >> num;
    while (num >= 0) {
        sum = sum + num;
        cin >> num;         // num is the conditional variable, not sum
    }
    cout << "Sum was " << sum << endl;
    return 0;
}