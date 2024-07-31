#include "game.h"
#include "menu.h"
#include "word.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filedata.h"



int main(void) {
    int choice;
    char* word = loadList(1);
    int score = loadUser("max.txt");
    displayWelcomeMessage();
    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            displayInstructions();
            break;
        case 2:
            roundGame(word);
            break;
        case 3:
            printf("Your score is: %d\n", score);
            break;
        case 4:
            printf("Exiting the game. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    // Ui test cases

    //test_REQ_GM_001();
    //test_REQ_GM_002();
    //test_REQ_GM_003();
    //test_REQ_GM_004();
    //test_REQ_GM_005();
    return 0;
}