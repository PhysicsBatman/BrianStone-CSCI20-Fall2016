// Brian Stone
// September 8, 2016
// Program #1: Variables

#include <iostream>
using namespace std;

int main() {
    string name;    // Create input variables
    int grade1;
    int grade2;
    int grade3;
    int grade4;
    int grade5;
    
    cout << "Name: ";   // Input data
    getline(cin, name);
    cout << "Grade 1: ";
    cin >> grade1;
    cout << "Grade 2: ";
    cin >> grade2;
    cout << "Grade 3: ";
    cin >> grade3;
    cout << "Grade 4: ";
    cin >> grade4;
    cout << "Grade 5: ";
    cin >> grade5;
    
    int gradeAvg = (grade1 + grade2 + grade3 + grade4 + grade5) / 5;    // Calculate average, minimum and maximum
    int gradeMin = gradeAvg / 2;
    int gradeMax = gradeMin + 50;
    
    cout << "Name: " << name << endl;   // Output all data and calculations
    cout << "Grades: " << grade1 << ", " << grade2 << ", " << grade3 << ", " << grade4 << ", " << grade5 << endl;
    cout << "Average grade: " << gradeAvg << endl;
    cout << "Maximum grade: " << gradeMax << endl;
    cout << "Minimum grade: " << gradeMin << endl;
}