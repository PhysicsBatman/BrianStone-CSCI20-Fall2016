// Brian Stone
// 11/17/16

// This program launches 1-5 single-stage rockets and calculates, based on the user's specifications, the maximum height of the rocket.
// If the rocket exceeds the escape velocity of Earth, the Sun, or the Milky Way Galaxy, the program will notify the user but not calculate a maximum height.

#include <iostream>
#include <cmath>
using namespace std;

class Rocket {
    private:
        string name;        // Name of the rocket
        double rocketMass;  // Mass of the rocket without fuel (in kilograms)
        double fuelMass;    // Mass of the fuel (in kilograms)
        double exhaustV;    // Effective exhaust velocity of the fuel (in meters per second)
    public:
        void describe(string inputName, double inputRocketMass, double inputFuelMass, double inputExhaustV) {   // Sets the variables
            name = inputName;
            rocketMass = inputRocketMass;
            fuelMass = inputFuelMass;
            exhaustV = inputExhaustV;
        }
        double launch() {   // Calculates and returns the launch velocity
            return exhaustV * log((rocketMass + fuelMass) / rocketMass);
        }
        string getName() {  // Returns the name of the rocket
            return name;
        }
};

void getInput(double& value) {  // Makes getting input easier
    value = 0;
    while (value <= 0) {
        cin >> value;
        
        if (value <= 0) {
            cout << "That number is invalid." << endl;
        }
    }
}

int main() {
    int numRockets = 0; // The number of rockets to launch
    int i;              // Counter
    // Physical constants
    const double EARTH_RADIUS = 6.371e6;
    const double GRAV_CONST = 6.67408e-11;
    const double EARTH_MASS = 5.972e24;
    const double EARTH_ESC_VEL = sqrt((2 * GRAV_CONST * EARTH_MASS) / EARTH_RADIUS);
    const double SUN_ESC_VEL = 42.1e3;
    const double GALAXY_ESC_VEL = 537e3;
    // Input
    string name;
    double rocketMass;
    double fuelMass;
    double exhaustV;
    double deltaV; // Calculated launch velocity
    
    cout << "How many rockets would you like to launch? (1-5)" << endl;
    while(numRockets > 5 || numRockets < 1) {
        cin >> numRockets;
        
        if (numRockets > 5 || numRockets < 1) {
            cout << "That number is invalid." << endl;
        }
    }
    
    Rocket rocket[numRockets];
    
    // Prompt the user for specifications
    for (i = 0; i < numRockets; ++ i) {
        cout << endl << "Please enter the name of Rocket #" << i + 1 << ":";
        cin.ignore();
        getline(cin, name);
        
        cout << endl << "Please enter the mass of Rocket #" << i + 1 << " in metric tonnes, excluding fuel: ";
        getInput(rocketMass);
        
        cout << endl << "Please enter the mass of fuel in Rocket #" << i + 1 << " in metric tonnes: ";
        getInput(fuelMass);
        
        cout << endl << "Please enter the effective exhaust velocity of the fuel in Rocket #" << i + 1 << " in kilometers per second: ";
        getInput(exhaustV);
        
        rocket[i].describe(name, rocketMass * 1000, fuelMass * 1000, exhaustV * 1000);
    }
    
    // Output the results of the launch
    cout << endl;
    for (i = 0; i < numRockets; ++ i) {
        deltaV = rocket[i].launch();
        if (deltaV < EARTH_ESC_VEL) {
            cout << rocket[i].getName() << " reached a height of " << (1 / ((1 / EARTH_RADIUS) - (pow(deltaV, 2) / (2 * GRAV_CONST * EARTH_MASS)))) - EARTH_RADIUS << " meters!" << endl;
        }
        else if (deltaV < SUN_ESC_VEL) {
            cout << rocket[i].getName() << " escaped the gravity of Earth!" << endl;
        }
        else if (deltaV < GALAXY_ESC_VEL) {
            cout << rocket[i].getName() << " escaped the gravity of the Sun!" << endl;
        }
        else {
            cout << rocket[i].getName() << " escaped the gravity of the Milky Way, and was arrested for speeding." << endl;
        }
    }
}