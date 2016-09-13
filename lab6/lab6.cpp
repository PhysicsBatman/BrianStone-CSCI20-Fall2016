#include <iostream>
using namespace std;

void copyright() {
    cout << endl;
    cout << "（ ͡° ͜ʖ ͡°)つ━☆・*。" << endl;
    cout << "⊂　　 ノ 　　　・゜+." << endl;
    cout << "　しーＪ　　　°。+ ´¨)" << endl;
    cout << "　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)" << endl;
    cout << "　　　　　　　　　　(¸.·´ (¸.·' ☆ Copyright Brian Stone 2016" << endl;
}

int main()
{
    string name;
    int number1;
    string noun;
    char character;
    float number2;
    
    cout << "Please enter a name:";
    cin >> name;
    cout << "Please enter a positive integer:";
    cin >> number1;
    cout << "Please enter a plural noun:";
    cin >> noun;
    cout << "Please enter a single character:";
    cin >> character;
    cout << "Please enter any number:";
    cin >> number2;
    
    cout << "Once upon a time, there was a person named " << name << ". " << name << " had " << number1 << " " << noun << ". One of these " << noun << ", however, was very special to " << name << ", because it was inscribed with a single \"" << character << "\". One day, " << name << " realized this most prized possession was missing. And so they traveled " << number2 << " miles, searching for this most sacred of " << noun << "." << endl;
    cout << "They found it." << endl;
    cout << "The End." << endl;
    
    copyright();
}