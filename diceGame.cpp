/* -----------------------------------------
 * diceGame.cpp
 * 
 * Author: Mayur Patel
 * Last Modified: 6/26/2019
 * -----------------------------------------
 */

#include <iostream>    // for cin and cout
#include <cstdlib>     // for rand()
#include <time.h>      // for srand()

using namespace std;

// contasnt int global variables to keep the faces the same throughout the program
const int diceRed[6] = {1, 4, 4, 4, 4, 4},
          diceGreen[6] = {2, 2, 2, 5, 5, 5},
          diceBlue[6] = {6, 3, 3, 3, 3, 3};

// function to print the header of the program
void printHeader() {
    cout << "Author: Mayur Patel\n"
         << "Class: CS 141\n"
         << "System: C++ in codio.com\n\n"
         << "Welcome to the dice game, where you and your opponent each choose\n"
         << "one of the red, green or blue dice and roll them.\n\n"
         << "The dice contain the following sides:\n"
         << "Red: 1 4 4 4 4 4\n"
         << "Green: 2 2 2 5 5 5\n"
         << "Blue: 6 3 3 3 3 3\n\n"
         << "Enter the die color for Player 1 then Player 2 (R G or B): ";
}

// function to pick a randon integer for the use of picking a random face from the constant die variable
int pickRandom() {
    int randIndex;
   
    randIndex = rand() % 6;    // generate random variable from 0 - 5 and assign it to randIndex
    
    return randIndex;          // returns generated random number
}

// function to run the main part of the game with two char parameters, which are user inputs, recieved from main()
void initiateGame(char diceColorOne, char diceColorTwo) {
    int diceFaceOne,
        diceFaceTwo,
        pointsPlayerOne = 0,   // initialize the first players points
        pointsPlayerTwo = 0,   // initialize the second players points
        i;
    
    // loop to run the game 50 times starting at 1 and ending at 50
    for (i = 1; i <= 50; i++) {
        // creates the spacing necessary to keep the intial numbers 1 -9 even with two digit numbers
        if (i > 0 && i < 10) {
            cout << " ";
        }
        
        /* switch case to check the first players dice color choice by applying the index recieved from pickRandom() 
         * function to the right dice color and printing the correct output line
         */
        switch (diceColorOne) {
            case 'R': diceFaceOne = diceRed[pickRandom()];
                      cout << i << ". R:" << diceFaceOne << " ";
                      break;
            
            case 'G': diceFaceOne = diceGreen[pickRandom()];
                      cout << i << ". G:" << diceFaceOne << " ";
                      break;
            
            case 'B': diceFaceOne = diceBlue[pickRandom()];
                      cout << i << ". B:" << diceFaceOne << " ";
                      break;
        }
        
        /* switch case to check the second players dice color choice by applying the index recieved from pickRandom() 
         * function to the right dice color and printing the correct output line
         */
        switch (diceColorTwo) {
            case 'R': diceFaceTwo = diceRed[pickRandom()];
                      cout << "R:" << diceFaceTwo << ", ";
                      break;
            
            case 'G': diceFaceTwo = diceGreen[pickRandom()];
                      cout << "G:" << diceFaceTwo << ", ";
                      break;
        
            case 'B': diceFaceTwo = diceBlue[pickRandom()];
                      cout << "B:" << diceFaceTwo << ", ";
                      break;
        }
        
        // checks which face value is bigger and then subtracts the smaller from the bigger to apply points to the owner of the bigger value
        if (diceFaceOne > diceFaceTwo) {
            pointsPlayerOne = pointsPlayerOne + (diceFaceOne - diceFaceTwo);
        }
        else if (diceFaceTwo > diceFaceOne) {
            pointsPlayerTwo = pointsPlayerTwo + (diceFaceTwo - diceFaceOne);
        }
        
        // outputs the current score of the two players
        cout << "Score: " << pointsPlayerOne << " to " << pointsPlayerTwo <<endl;
    }
}

// main function to bring the whole program together and run it
int main(){
    char diceChoiceOne,    // player one's dice choice holder
         diceChoiceTwo;    // player two's dice choice holder
    
    // calls printHeader() function to print the header of the program
    printHeader();
    
    // gets user input for the two players dice choices
    cin >> diceChoiceOne >> diceChoiceTwo;
    
    // initializes the random seed with time
    srand(time(NULL));
    
    // runs the game by sending user input through initiateGame() function
    initiateGame(diceChoiceOne, diceChoiceTwo);
    
    return 0;
}