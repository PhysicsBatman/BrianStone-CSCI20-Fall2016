// Brian Stone
// 10/18/16
// Assignment #3 - Rock Paper Scissors Game
// The computer and the user each chooses one of three options.
// "Rock" beats "Scissors," "Scissors" beats "Paper" and "Paper" beats "Rock."
// The use determines the maximum number of non-tie rounds (3, 5 or 7).
// Once either player wins a majority of these rounds, the game ends.

#include <iostream>
using namespace std;

class Referee {
    private:
        int outcome;
    public:
        void compareHands(int playerChoice, int computerChoice) {
            switch(computerChoice) {
                case 0:
                    switch(playerChoice) {
                        case 0:
                            outcome = 0;
                            break;
                        case 1:
                            outcome = 1;
                            break;
                        case 2:
                            outcome = 2;
                            break;
                    }
                    break;
                case 1:
                    switch(playerChoice) {
                        case 0:
                            outcome = 2;
                            break;
                        case 1:
                            outcome = 0;
                            break;
                        case 2:
                            outcome = 1;
                            break;
                    }
                    break;
                case 2:
                    switch(playerChoice) {
                        case 0:
                            outcome = 1;
                            break;
                        case 1:
                            outcome = 2;
                            break;
                        case 2:
                            outcome = 0;
                            break;
                    }
                    break;
            }
        }
        int getOutcome() {
            return outcome;
        }
};

int main() {
    int numRounds;
    cout << "It's time to play Rock Paper Scissors! Best out of 3, 5 or 7?" << endl;
    cin >> numRounds;
    cout << endl;
    
    switch(numRounds) {
        case 3:
        case 5:
        case 7:
            break;
        default:
            numRounds = 3;
            break;
    }
    
    int playerScore = 0;
    int computerScore = 0;
    while(playerScore <= numRounds / 2 && computerScore <= numRounds / 2) {
        int playerChoice;
        bool validInput = false;
        while(!validInput) {
            string input;
            cout << "Rock, paper or scissors?" << endl;
            cin >> input;
            
            if (input == "Rock" || input == "rock") {
                cout << "Player: Rock" << endl;
                playerChoice = 0;
                validInput = true;
            }
            else if (input == "Paper" || input == "paper") {
                cout << "Player: Paper" << endl;
                playerChoice = 1;
                validInput = true;
            }
            else if (input == "Scissors" || input == "scissors") {
                cout << "Player: Scissors" << endl;
                playerChoice = 2;
                validInput = true;
            }
        }
        
        int computerChoice = rand() % 3;
        switch(computerChoice) {
            case 0:
                cout << "Computer: Rock" << endl;
            case 1:
                cout << "Computer: Paper" << endl;
            case 2:
                cout << "Computer: Scissors" << endl;
        }
        
        Referee James;
        James.compareHands(playerChoice, computerChoice);
        int outcome = James.getOutcome();
        
        switch(outcome) {
            case 0:
                cout << "Tie!" << endl << endl;
                break;
            case 1:
                cout << "You win!" << endl << endl;
                ++ playerScore;
                break;
            case 2:
                cout << "You lose!" << endl << endl;
                ++ computerScore;
                break;
        }
    }
    
    cout << "Final score: " << playerScore << " - " << computerScore << endl;
    
    if (playerScore > computerScore) {
        cout << "Congratulations! You are a master of RNG!" << endl;
    }
    else {
        cout << "Darn! Better luck next time!" << endl;
    }
}