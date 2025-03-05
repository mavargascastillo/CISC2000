/* 
CISC 2000
Programming assignment #6:
This program checks if an arbitrary string is a palindrome. That is, it checks if the string is the same when read left to right
and right to left
Date: Mar 04, 2025
Author: Miguel Ángel Vargas
 */

/* 
 * pallindrome: checks a string to see if it is a pallindrome.
 *  
 *  Examples:
 * 
 *  Able was I 'ere I saw Elba.
 *  Madam, I'm Adam.
 *  A man, a plan, a canal, Panama.
 *  Racecar
 * 
 *  First, create a clean version of the string. 
 *  	- convert all characters to lower case.
 *  	- remove all punctuation.
 * 
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *   
 *  Third
 *  	- compare the two strings 
 *  		if they are the same, palindrome.
 *  		else, not palindrome.
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> // for the reverse function
using namespace std;
 
 
string removePunct(string str);
// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convertToLower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

    // ToDo: Declare two vectors of strings to save the input strings: palindromes,
    // not_palindromes.
    vector<string> palindromes, not_palindromes;
    string strInput;

    // ToDo: Implement a loop to read in the palindrome strings using getline until
    // the user quits. The user will enter the word "quit" to exit the loop.

    while (true) {
        cout << "Enter your palindrome or type quit: " << endl;
        getline(cin, strInput);
        if (strInput == "quit") {
            break;
        }

        // ToDo: In the loop, call the isPalindrome function on the input string and
        // store it in the palindromes vector if true and the notPalindromes vector if
        // false.

        if (isPalindrome(strInput)){
            palindromes.push_back(strInput);
        } else {
            not_palindromes.push_back(strInput);
        }
    }

    // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
    // heading and the list that are not palindromes under a Not Palindrome heading.
    // The display function should print a tab character before printing the string.

    cout << "Palindromes:" << endl;
    display(palindromes);

    cout << "\nNOT Palindromes:" << endl;
    display(not_palindromes);

    return 0;
}

string removePunct(string str) {
    string result; // this will be the string that is returned without punctuation
    for (char c : str) {
        if (isalnum(c)) { // checks if each character is alphanumeric
            result += c; // add each character to the final string if it is indeed alphanumeric
        }
    }
    return result;
}

string convertToLower(string str) {
    for (char &c : str){ // we pass c by reference to directly change the value of str characters
        c = tolower(c);
    }
    return str;
}

string reverse(string str) {
    reverse(str.begin(), str.end());
    return str;
}

void display(vector<string> vstrings){
    for (const string &str : vstrings){
        // we pass str by reference and as a constant to avoid making copies of the vector's elements and ensuring
        // we do not change their values
        cout << "\t" << str << endl;
    }
}

bool isPalindrome(string str) {
    // given that we are only passing one string, we will call all the string functions we have written 
    // from isPalindrome
    string finalString = convertToLower(removePunct(str));
    return finalString == reverse(finalString); // performs the boolean check and returns true if true
}