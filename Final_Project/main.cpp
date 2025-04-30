/* 
CISC 2000
Final Programming assignment
This is a random number guessing game that the user can play with a friend or against a
computer player. The program will generate a number between 0 and 99, and players will take
turns guessing the number until one of them answers the guess correctly.
Date: Apr 30, 2025
Authors: Miguel Ángel Vargas & Nik Tanner
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype> // to use toupper
// Include the other header files you write for the three classes.
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
using namespace std;

//Declare all three function here!
void play(Player& player1, Player& player2);
// Pre: the two Player objects have been initialized
// Post: does not return a type. Instead, it is the function that handles the main logic of the game

bool checkForWin(Player& player, int answer);
// Pre: the two Player objects have been initialized, as the function will evaluate both Players' answers
// Post: returns true if the respective player guessed the number correctly

void displayGameStats(const Player& player1, const Player& player2);
// Pre: the two Player objects have been initialized
// Post: displays the stats (the number of wins) for each of the players

int main()
{
    // Set the Random Seed!
    srand(static_cast<unsigned int>(time(0)));

    int numPlayers;
    Player* p1, * p2;

    // Determine the number of players via user input and looping.
    do {
        cout << "Enter number of players (0, 1, or 2): ";
        cin >> numPlayers;
        if (numPlayers != 0 && numPlayers != 1 && numPlayers != 2) {
            cout << "Please re-enter the number of players." << endl;
        }
    } while (numPlayers != 0 && numPlayers != 1 && numPlayers != 2);

    HumanPlayer h1("Player 1"), h2("Player 2");
    ComputerPlayer c1("CPU 1"), c2("CPU 2");
    
    // Set up player pointers.
    // This is where polymorphism comes into play! We can point Player* to any of the classes!
    if (numPlayers == 0) {
        p1 = &c1;  // Computer
        p2 = &c2;  // Computer
    }
    else if (numPlayers == 1) {
        p1 = &h1;  // Human
        p2 = &c1;  // Computer
    } else {
        p1 = &h1;  // Human 1
        p2 = &h2;  // Human 2
    }
    
    // Write the game loop here.
    char playAgain;

    do {
        play(*p1, *p2);

        do {
            cout << "Would you like to play again? (Y/N): ";
            cin >> playAgain;
            playAgain = toupper(playAgain); // Normalize to uppercase
            if (playAgain != 'Y' && playAgain != 'N') {
                cout << "Please re-enter your answer. (Y/N):" << endl;
            }
        } while (playAgain != 'Y' && playAgain != 'N');

    } while (playAgain == 'Y');

    cout << endl;
    // Show output game stats functions
    displayGameStats(*p1, *p2);

    return 0;
}

void play(Player& player1, Player& player2)
{
    int answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        win = checkForWin(player1, answer);
        if (win)
        {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win)
        {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

bool checkForWin(Player& player, int answer)
{
    bool win = false;
    cout << player.getName() << "'s turn to guess." << endl;
    int guess = player.getGuess();
    cout << "You guessed " << guess << ". ";
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        win = true;
    }
    else
        player.wrongGuess(guess, answer);
    return win;
}

// Function to output game stats!
void displayGameStats(const Player& player1, const Player& player2)
{
    cout << "Game Summary:" << endl;
    cout << player1.getName() << " won " << player1.getNumWins() << " time(s)." << endl;
    cout << player2.getName() << " won " << player2.getNumWins() << " time(s)." << endl;
}
