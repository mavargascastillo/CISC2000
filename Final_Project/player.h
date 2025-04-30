/* 
CISC 2000
Final Programming assignment
This is a random number guessing game that the user can play with a friend or against a
computer player.
This is the header file for the base class Player.
Date: Apr 30, 2025
Authors: Miguel Ángel Vargas & Nik Tanner
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player {
protected: 
// protected instead of private so that derived classes can access them without needing getters/setters
    string name;
    int numWins;

public:
    // Default constructor
    Player();

    // Mutator and accessor for name
    void setName(const string& newName);
    string getName() const;

    // Accessor for number of wins
    int getNumWins() const;

    // Virtual methods for polymorphism
    virtual int getGuess() { 
        return 0; 
    }
    virtual void wrongGuess(int guess, int answer);

    // End of round logic
    void endRound(bool didWin);

    // Operator overloads
    bool operator>(const Player& other) const;
    friend ostream& operator<<(ostream& out, const Player& p);

    // Virtual destructor
    virtual ~Player() {}
};

#endif