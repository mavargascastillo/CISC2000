/* 
CISC 2000
Final Programming assignment
This is a random number guessing game that the user can play with a friend or against a
computer player.
This is the implementation file for the base class Player.
Date: Apr 30, 2025
Authors: Miguel Ángel Vargas & Nik Tanner
 */

#include "Player.h"
#include <iostream>
using namespace std;

// Default constructor
Player::Player() : name(""), numWins(0) {}

// Mutator for name
void Player::setName(const string& newName) {
    name = newName;
}

// Accessor for name
string Player::getName() const {
    return name;
}

// Accessor for number of wins
int Player::getNumWins() const {
    return numWins;
}

// Handle wrong guess
void Player::wrongGuess(int guess, int answer) {
    if (guess > answer)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
}

// End of round: update win count
void Player::endRound(bool didWin) {
    if (didWin)
        numWins++;
}

// Overload > operator to compare wins
bool Player::operator>(const Player& other) const {
    // we compare the current player against the other player's # of wins
    return numWins > other.numWins;
}

// Overload << operator to output name and wins
ostream& operator<<(ostream& out, const Player& p) {
    out << p.name << " has " << p.numWins << " win";
    // this is just a cheeky thing to handle when the wins = 1 or > 1. 
    if (p.numWins != 1) out << "s";
    return out;
}
