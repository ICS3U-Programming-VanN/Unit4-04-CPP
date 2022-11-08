// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: November 7, 2022
// This program asks the user to guess a generated Guess
// if the user guesses it wrong, the program will continue
// to ask the user to guess(this continues until the user gets it right)


#include <iostream>
#include <random>


int main() {
    // Generates a random number from 0-9
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);

    // Correct Number constant declared
    const int CORRECT_NUMBER = idist(rgen);

    // Declared Variables
    int userGuessInt;
    float userGuessFloat;
    std::string userGuessString;

    // Do-while loop that keeps looping until the user breaks out of it
    do {
        // Asks user for their guess
        std::cout << "Enter your whole number guess (0-9): ";
        std::cin >> userGuessString;

        // Checks for exceptions
        try {
            // Converts userGuess into an integer to check for invalid input
            userGuessInt = stoi(userGuessString);

            // Converts userGuess into an float to check for invalid input
            userGuessFloat = stof(userGuessString);

            // IF the user's guess is out of the given range (0-9)
            // or contains a decimal
            if (userGuessInt < 0 || userGuessInt != userGuessFloat
                                || userGuessInt > 9) {
                std::cout << "Please enter a whole number between 0-9!" <<
                "Try again.\n" << std::endl;

            // IF the user entered a valid guess
            } else {
                // If the user guesses the number correctly
                if (userGuessInt == CORRECT_NUMBER) {
                    // Displays to user that they got the number correct
                    std::cout << "You guessed the number correctly! "
                              << "The correct number was "
                              << CORRECT_NUMBER << std::endl;

                    // Breaks out of the loop
                    break;

                // IF the user guesses wrong
                } else {
                    // Displays to user that they guessed wrong
                    std::cout << "You guessed wrong! Try again.\n" << std::endl;
                }
            }
        // In the event of an exception:
        } catch (std::invalid_argument) {
            std::cout << userGuessString <<
            " is not a valid guess! Try again.\n" << std::endl;
        }
    // Keeps looping until broken out of
    } while (true);

    // Final message displayed to user regardless of input
    std::cout << "Thank you for playing!" << std::endl;
}
