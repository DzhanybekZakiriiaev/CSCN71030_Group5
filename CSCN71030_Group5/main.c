#include <stdio.h>
//#include "menu.h"
#include "game.h"

int main(void) {
    int choice;
    displayWelcomeMessage();

    //wordle();
    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            displayInstructions();
            break;
        case 2:
            roundGame("ROUND");
            break;
        case 3:
            viewPlayedWords();
            break;
        case 4:
            addCustomWords();
            break;
        case 5:
            printf("Exiting the game. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}