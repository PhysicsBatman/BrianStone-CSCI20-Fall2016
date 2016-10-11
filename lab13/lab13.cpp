#include <iostream>
using namespace std;

int main() {
    int minElapsed = 0;
    while(minElapsed <= 119) {
        cout << "Current time: " << 1 + (minElapsed / 60) << ":" << minElapsed % 60 << endl;
        minElapsed ++;
    }
    
    int startTime = 0;
    cout << "Enter start time in minutes past midnight: " << endl;
    cin >> startTime;
    
    int endTime = 0;
    cout << "Enter end time in minutes past midnight: " << endl;
    cin >> endTime;
    
    int cyclesElapsed = 0;
    while(cyclesElapsed < (endTime - startTime) / 15) {
        
        int hours = (startTime + (cyclesElapsed * 15)) / 60;
        int minutes = (startTime + (cyclesElapsed * 15)) % 60;
        
        string meridiem = ((hours / 12) % 2 == 0) ? "AM" : "PM";
        
        string clockhours = to_string(hours % 12);
        string clockminutes = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);
        
        cout << "Current time: " << clockhours << ":" << clockminutes << " " << meridiem << endl;
        
        cyclesElapsed ++;
        
    }
    
}