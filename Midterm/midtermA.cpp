/* 
CISC 2000
Midterm A:
This program returns the number of vowels in a string provided by the user
Date: Feb 28, 2025
Author: Miguel Ángel Vargas
 */

#include <iostream>
#include <string>
using namespace std;

const string VOWELS = "AEIOUaeiou";
int countVowels(string& phrase); 
// Pre: the string has been initialized
// Post: returns the number of vowels in the given string

int main()
{
    string phrase;
    
    while (true){
        cout << "Enter a phrase (Type quit to end): ";
        getline(cin, phrase); // use getline in case we want to input more than a word

        if (phrase == "quit"){
            return 0;
        }

        int numVowels = countVowels(phrase);
        cout << "Number of vowels: " << numVowels << endl;
    }
    cout << "Enter a phrase (Type quit to end): ";
    return 0; 
    
}
    
// Implement the function!
int countVowels(string& phrase) // change to reference so that we can use a range based loop
{ 
    int vowelCount = 0;

    for (char c : phrase){
        if (VOWELS.find(c) != string::npos){ // loops through every character of the phrase
            vowelCount++;
        }
    }
    return vowelCount;
}
