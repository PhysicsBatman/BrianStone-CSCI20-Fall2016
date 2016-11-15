#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
                char firststr[10];                                                      // C-string that stores user input
                int firstname = 0;                                                      // The length of the input
                char *head = firststr;                                                  // Points to the C-string
                char *tail = firststr;                                                  // Points to the C-string
                cout << "Please enter a 10 letter word or less" << endl;
                cin >> firststr;
                strlen(firststr);                                                       // This line is useless
                firstname = strlen(firststr);                                           // Stores the length of the input
                cout << "Your word is " << firststr << endl;
                if (firstname<10)
                {
                                while (*head != '\0')                                   // Outputs the C-string forwards
                                {
                                                cout << *head;                          // Output current character
                                                head++;                                 // Move to next character
                                }
                }
                else                                                                    // The word is too big
                {
                                cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;    
                }
                cout << endl;
                tail = &firststr[strlen(firststr) - 1];                                 // Unlike the "head" pointer, "tail" reads backwards from the end of the C-string
                if (firstname < 10)
                {
                                while (*tail>0)                                         // Outputs the C-string backwards
                                {
                                                cout << *tail;                          // Output current character
                                                tail--;                                 // Move to next character
                                }
                }
                cout << endl;
                head = firststr;
                tail = &firststr[strlen(firststr) - 1];
                head++;                                                                 // Set "head" pointer to second character in C-string
                tail--;                                                                 // Set "tail" pointer to second-to-last character in C-string
                if (*head == *tail)                                                     // The second and second-to-last characters in the C-strings are the same
                {
                                cout << "It is an palindrome!" << endl;                 // Tells the user that the word is a palindrome, even though it probably isn't, you liar >:(
                }
                else
                {
                                cout << "It is not an palindrome" << endl;
                }
 
                return 0;
}