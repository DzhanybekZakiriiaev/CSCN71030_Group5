#include <stdio.h>
# include "menu.h"

// 

void displayWelcomeMessage() {
	printf(" Welcome to Wordle!!!\n");
	printf("Please Choose From an option from the menu below\n");
}

// 
void displayMenu() {
    printf("1. Start New Game\n");
    printf("2. View Instructions\n");
    printf("3. View Battle pass\n");
    printf("4. Exit\n");
}


// 

int getMenuChoice() {
    int choice;
    int isValid;

    do {
        printf("Enter your choice: ");
        isValid = scanf("%d", &choice);

        // Clear the input buffer
        while (getchar() != '\n');

        if (isValid != 1 || choice < 1 || choice > 4) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            isValid = 0; // Invalid input, prompt again
        }
    } while (isValid != 1);

    return choice;
}
