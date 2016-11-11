// Brian Stone
// 11/8/16

// This program reads any text file and creates a concordance for it.
// Any word that is more than 3 characters in length and is not listed in the specified stop word file is placed into the concordance.
// Each word in the concordance is listed in an output file along with the number of instances of the word as well as the first line on which it appears.

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Word {
    private:
        string word = "";
        int count = 0;
        int firstLine = 0;
    public:
        void setWord(string inputWord) {
            word = inputWord;
        }
        void addToCount() {
            ++ count;
        }
        void setFirstLine(int inputLine) {
            firstLine = inputLine;
        }
        string getWord() {
            return word;
        }
        int getCount() {
            return count;
        }
        int getFirstLine() {
            return firstLine;
        }
};

int main() {
    Word word[100];                     // Our concordance
    ifstream inFS;                      // Reads input file
    ifstream stopFS;                    // Reads stop word file
    ofstream outFS;                     // Reads output file
    istringstream lineStream;           // Reads lines from input file
    string fileName;
    string lineString;
    string inputWord;                   // The word that inFS is on
    string stopWord;                    // The word that stopFS is on
    int inputLine = 0;                  // The line that inFS is on
    int i = 0;                          // General-purpose loop counter
    int j = 0;                          // Current array position
    int maxLength = 0;                  // The length of the longest word
    bool valid;                         // False if currentWord is in stop word file or is more than 3 characters long
    
    cout << "Please enter the name of your input file (including its extension): ";
    while(!inFS.is_open()) {
        cin >> fileName;
        
        inFS.open(fileName);
        if (!inFS.is_open()) {
            cout << endl << "That is not a valid file name. Please enter a different name: ";
        }
    }
    
    cout << endl << "Please enter the name of your output file (including its extension): ";
    while(!outFS.is_open()) {
        cin >> fileName;
        
        outFS.open(fileName);
        if (!outFS.is_open()) {
            cout << endl << "That is not a valid file name. Please enter a different name: ";
        }
    }
    
    cout << endl << "Please enter the name of your stop word file (including its extension): ";
    while(!stopFS.is_open()) {
        cin >> fileName;
        
        stopFS.open(fileName);
        if (!stopFS.is_open()) {
            cout << endl << "That is not a valid file name. Please enter a different name: ";
        }
    }
    
    while (!inFS.eof()) {                                                       // We haven't reached the end of the input file
        ++ inputLine;
        lineStream.clear();
        getline(inFS, lineString);                                              // Take the first line of the input file
        lineStream.str(lineString);
        while (!lineStream.eof()) {                                             // We haven't reached the end of the line
            valid = true;
            lineStream >> inputWord;
            for (i = 3; i < inputWord.length(); ++ i) {
                if (ispunct(inputWord[i]) && inputWord[i] != '\'') {            // String contains punctuation, remove it
                    inputWord.resize(i);
                }
            }
            if (inputWord.length() > 3) {
                stopFS.close();
                stopFS.open(fileName);
                while (valid && !stopFS.eof()) {
                    stopFS >> stopWord;
                    if (inputWord == stopWord) {                                // Word is listed in stop word file, set valid to false
                        valid = false;
                    }
                }
            }
            else {                                                              // Word is less than 3 characters long
                valid = false;
            }
            if (valid) {
                inputWord[0] = toupper(inputWord[0]);                           // Capitalize
                for (i = 0; i < 100; ++ i) {
                    if (word[i].getWord() == inputWord) {                       // We have this word already, add 1 to count
                        word[i].addToCount();
                        i = 101;
                    }
                }
                if (i == 100) {                                                 // We don't have this word yet, add it and go to next array slot
                    word[j].setWord(inputWord);
                    word[j].addToCount();
                    word[j].setFirstLine(inputLine);
                    ++ j;
                    if (inputWord.length() > maxLength) {
                        maxLength = inputWord.length();
                    }
                }
            }
        }
    }
    
    outFS << left << setw(maxLength + 1) << "Word" << setw(maxLength + 1) << "Count" << setw(maxLength + 1) << "First Line" << endl << setfill('-') << setw((maxLength + 1) * 3) << "" << setfill(' ') << endl;
    cout << endl << left << setw(maxLength + 1) << "Word" << setw(maxLength + 1) << "Count" << setw(maxLength + 1) << "First Line" << endl << setfill('-') << setw((maxLength + 1) * 3) << "" << setfill(' ') << endl;
    for (i = 0; word[i].getWord() != "" && i < 25; ++ i) {
        outFS << setw(maxLength + 1) << word[i].getWord() << setw(maxLength + 1) << word[i].getCount() << setw(maxLength + 1) << word[i].getFirstLine() << endl;
        cout << setw(maxLength + 1) << word[i].getWord() << setw(maxLength + 1) << word[i].getCount() << setw(maxLength + 1) << word[i].getFirstLine() << endl;
    }
}