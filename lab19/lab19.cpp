#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inFS;
    ofstream outFS;
    string fileName;
    int i;
    int j;
    int input[3][4];
    int arrayTotal = 0;
    int max = 0;
    int maxdigits = 0;
    int rowTotal;
    int columnTotal;
    
    cout << "Please enter the name of your input file (including its extension): ";
    while(!inFS.is_open()) {
        cin >> fileName;
        
        inFS.open(fileName);
        if (!inFS.is_open()) {
            cout << endl << "That is not a valid file name. Please enter a different name: ";
        }
    }
    
    cout << "Please enter the name of your output file (including its extension): ";
    while(!outFS.is_open()) {
        cin >> fileName;
        
        outFS.open(fileName);
        if (!outFS.is_open()) {
            cout << endl << "That is not a valid file name. Please enter a different name: ";
        }
    }
    
    for (i = 0; i < 3; ++ i) {
        for (j = 0; j < 4; ++ j) {
            inFS >> input[i][j];
            arrayTotal += input[i][j];
            if (input[i][j] > max) {
                max = input[i][j];
            }
        }
    }
    
    while (max > 0) {
        ++ maxdigits;
        max /= 10;
    }
    
    outFS << left;
    
    for (i = 0; i < 3; ++ i) {
        rowTotal = 0;
        for (j = 0; j < 4; ++ j) {
            outFS << setw(maxdigits + 1) << input[i][j];
            rowTotal += input[i][j];
        }
        outFS << rowTotal << endl;
    }
    
    for (j = 0; j < 4; ++ j) {
        columnTotal = 0;
        for (i = 0; i < 3; ++ i) {
            columnTotal += input[i][j];
        }
        outFS << setw(maxdigits + 1) << columnTotal;
    }
    
    outFS << "Average: " << arrayTotal / 12.0;
}