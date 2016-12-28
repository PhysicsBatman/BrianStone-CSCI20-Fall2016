// Virtual Railgun Rockets

#include <iostream>
#include <cmath>
using namespace std;

class Railgun {
    private:
        double railgunMass;
        double fuelMass;
        double exhaustV;
    public:
        void describe(double inputRailgunMass, double inputFuelMass, double inputExhaustV) {
            railgunMass = inputRailgunMass;
            fuelMass = inputFuelMass;
            exhaustV = inputExhaustV;
        }
        double launch() {
            return exhaustV * log((railgunMass + fuelMass) / railgunMass);
        }
};

void getInput(double& value) {
    value = 0;
    while (value <= 0) {
        cin >> value;
        
        if (value <= 0) {
            cout << "That number is invalid." << endl;
        }
    }
}

int main() {
    int numRailguns = 0;
    int i;
    
    const double EARTH_RADIUS = 6.371e6;
    const double GRAV_CONST = 6.67408e-11;
    const double EARTH_MASS = 5.972e24;
    const double EARTH_ESC_VEL = sqrt((2 * GRAV_CONST * EARTH_MASS) / EARTH_RADIUS);
    const double SUN_ESC_VEL = 42.1e3;
    const double GALAXY_ESC_VEL = 537e3;
    
    double railgunMass;
    double exhaustV;
    
    double bField;
    double current;
    double projMass;
    double projLength;
    double projNum;
    double railLength;
    
    double deltaV;
    
    cout << "How many rockets would you like to launch? (1-5)" << endl;
    while(numRailguns > 5 || numRailguns < 1) {
        cin >> numRailguns;
        
        if (numRailguns > 5 || numRailguns < 1) {
            cout << "That number is invalid." << endl;
        }
    }
    
    Railgun railgun[numRailguns];
    
    for (i = 0; i < numRailguns; ++ i) {
        cout << endl << "Enter the mass of Railgun #" << i + 1 << " in metric tonnes, excluding projectiles: ";
        getInput(railgunMass);
        
        cout << endl << "Now, enter the value of the magnetic field of Railgun #" << i + 1 << " in teslas: ";
        getInput(bField);
        
        cout << endl << "Now, enter the value of the current of Railgun #" << i + 1 << " in amperes: ";
        getInput(current);
        
        cout << endl << "Now, enter the length of Railgun #" << i + 1 << " in meters: ";
        getInput(railLength);
        
        cout << endl << "Now, enter the mass of each projectile in Railgun #" << i + 1 << " in grams: ";
        getInput(projMass);
        
        cout << endl << "Now, enter the length of each projectile in Railgun #" << i + 1 << " in meters: ";
        getInput(projLength);
        
        cout << endl << "Finally, enter the number of projectiles in Railgun #" << i + 1 << " in thousands: ";
        getInput(projNum);
        
        exhaustV = sqrt(2 * railLength * ((current * projLength * bField) / (projMass / 1000)));
        
        railgun[i].describe(railgunMass * 1000, projMass * projNum * 1000, exhaustV);
    }
    
    cout << endl;
    for (i = 0; i < numRailguns; ++ i) {
        deltaV = railgun[i].launch();
        if (deltaV < EARTH_ESC_VEL) {
            cout << "Railgun #" << i + 1 << " reached a height of " << (1 / ((1 / EARTH_RADIUS) - (pow(deltaV, 2) / (2 * GRAV_CONST * EARTH_MASS)))) - EARTH_RADIUS << " meters!" << endl;
        }
        else if (deltaV < SUN_ESC_VEL) {
            cout << "Railgun #" << i + 1 << " escaped the gravity of Earth!" << endl;
        }
        else if (deltaV < GALAXY_ESC_VEL) {
            cout << "Railgun #" << i + 1 << " escaped the gravity of the Sun!" << endl;
        }
        else {
            cout << "Railgun #" << i + 1 << " escaped the gravity of the Milky Way, and was arrested for speeding." << endl;
        }
    }
}