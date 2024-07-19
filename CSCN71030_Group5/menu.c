#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"
#include "game.h" // Include your game header file

void displayWelcomeMessage() {
    printf("Welcome to Wordle!!!\n");
    printf("Please choose an option from the menu below\n");
}

void displayMenu() {
    printf("1. View Instructions\n");
    printf("2. Start Game\n");
    printf("3. View Played Words\n");
    printf("4. Add Custom Words\n");
    printf("5. Exit\n");
}

int getMenuChoice() {
    int choice;
    int isValid;

    do {
        printf("Enter your choice: ");
        isValid = scanf("%d", &choice);

        // Clear the input buffer
        while (getchar() != '\n');

        if (isValid != 1 || choice < 1 || choice > 5) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            isValid = 0; // Invalid input, prompt again
        }
    } while (isValid != 1);

    return choice;
}

void displayInstructions() {
    printf("Wordle Game Instructions:\n");
    printf("1. Guess the 5-letter word within 6 attempts.\n");
    printf("2. Each guess must be a valid 5-letter word.\n");
    printf("3. After each guess, the color of the tiles will change to show how close your guess was to the word.\n");
    printf("   - Red: Incorrect letter\n");
    printf("   - Green: Correct letter in the correct position\n");
    printf("   - Yellow: Correct letter in the wrong position\n");
    printf(" \n");
}

void viewPlayedWords() {
 
    printf("We've Not Implemented the code yet\n");
}

void addCustomWords() {
    // Placeholder for adding custom words
    printf("We're yet to implement this too \n");
}


