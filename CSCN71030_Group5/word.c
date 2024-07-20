#include "word.h"
#include "character.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define GUESSES 6

bool isWordGuessed(WORD word, char* chars) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (!isGuessed(word.characters[i], chars[i])) {
            return false;
        }
    }
    return true;
}

void setGuessed(WORD* word) {
    word->isGuessed = true;
}

void printWords(WORD* words) {
    for (int i = 0; i < GUESSES; i++) {
        printf("_________________________________________________________________________________\n");
        for (int j = 0; j < WORD_LENGTH; j++) {
            printf("|");
            if (words[i].characters[j].isGuessed == true && words[i].characters[j].isPositioned == true) {
                printf(GREEN "\t%c\t" RESET, words[i].characters[j].content);
            }
            else if (words[i].characters[j].isGuessed == true && words[i].characters[j].isPositioned != true) {
                printf(YELLOW "\t%c\t" RESET, words[i].characters[j].content);
            }
            else {
                printf(RED "\t%c\t" RESET, words[i].characters[j].content);
            }
        }
        printf("|\n");
    }
}

void printAnswer(char* answer) {
    printf("_________________________________________________________________________________\n");
    for (int i = 0; i < WORD_LENGTH; i++) {
        printf("|");
        printf(GREEN "\t%c\t" RESET, answer[i]);
    }
    printf("|\n");
}

