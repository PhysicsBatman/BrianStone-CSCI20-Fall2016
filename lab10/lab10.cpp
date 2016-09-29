#include <iostream>
using namespace std;

int main() {
    int suzyAge = 25;
    int johnAge = 21;
    cout << "(suzyAge < johnAge) == " << (suzyAge < johnAge) << endl;
    
    int x = 7;
    int y = 7;
    cout << "(x >= y) == " << (x >= y) << endl;
    
    int a = 1;
    int b = 9;
    cout << "(a == b) == " << (a == b) << endl;
    
    int limit = 20;
    int count = 10;
    cout << "((limit * count) / 2 > 0) == " << ((limit * count) / 2 > 0) << endl;
    
    int t = -4;
    int z = 0;
    cout << "((t > 5) || (z < 2)) == " << ((t > 5) || (z < 2)) << endl;
    
    int variable = -5;
    cout << "(!(variable > 0)) == " << (!(variable > 0)) << endl;
    
    a = 16;
    cout << "((a / 4 < 8) && (a >= 4)) == " << ((a / 4 < 8) && (a >= 4)) << endl;
    
    x = -2;
    y = 5;
    cout << "((x * y < 10) || (y * z < 10)) == " << ((x * y < 10) || (y * z < 10)) << endl;
    
    int j = -2;
    int k = 5;
    int l = 4;
    cout << "(!(j * l < 10) || ((y / x) * 4 < y * 2)) == " << (!(j * l < 10) || ((y / x) * 4 < y * 2)) << endl;
}