#include <iostream>
using namespace std;

class ATM {
    private:
        double moolah;
    public:
        ATM() {
            moolah = 0;
        }
        ATM(double initialBalance) {
            moolah = initialBalance;
        }
        double currentBalance() {
            return moolah;
        }
        void withdraw(double amountWithdrawn) {
            moolah = moolah - amountWithdrawn;
        }
        void deposit(double amountDeposited) {
            moolah = moolah + amountDeposited;
        }
        void printStatement() {
            cout << "Your current balance is: $" << moolah << endl;
        }
};

int main() {
    ATM account1;
    account1.deposit(100);
    account1.withdraw(20);
    account1.printStatement();
    account1.withdraw(60);
    account1.withdraw(40);
    account1.printStatement();
    account1.deposit(73);
    account1.withdraw(40);
    
    cout << endl;
    ATM account2(100000);
    cout << "$" << account2.currentBalance() << "? That's a lot of money!" << endl;
}