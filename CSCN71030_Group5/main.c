#include "game.h"
#include "menu.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

 /*   // Ui test cases
    test_UI_TestCase_001();
    test_UI_TestCase_002();
    test_UI_TestCase_003();
    test_UI_TestCase_004();
    test_UI_TestCase_005();

*/

    return 0;
}