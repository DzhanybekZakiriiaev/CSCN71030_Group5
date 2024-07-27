#define GUESSES 6
#include "game.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include "word.h"

int roundGame(char* answer) {
    WORD words[GUESSES];
    initWords(words);
    printf("\033[H\033[2J");
    printWords(words);
    for (int i = 0; i < GUESSES; i++) {
        char* input = getValidStringInput("", WORD_LENGTH + 1);
        for (int j = 0; j < WORD_LENGTH; j++) {
            words[i].characters[j].content = input[j];
            words[i].characters[j].isGuessed = false;
            words[i].characters[j].isPositioned = false;
        }

        check(answer, &words[i]);

        printf("\033[H\033[2J");
        printWords(words);

        if (words[i].isGuessed) {
            printf("Congratulations! You've guessed the word.\n");
            return 1;
        }
    }
    printAnswer(answer);
    printf("Better luck next time!\n");
    return 0;
}

void initWords(WORD* words) {
    for (int i = 0; i < GUESSES; i++) {
        for (int j = 0; j < WORD_LENGTH; j++) {
            words[i].characters[j].content = ' ';
            words[i].characters[j].isGuessed = false;
            words[i].characters[j].isPositioned = false;
        }
        words[i].isGuessed = false;
    }
}

void check(char* answer, WORD* word) {
    bool matched[WORD_LENGTH] = { false };

    // Check for correct position
    for (int j = 0; j < WORD_LENGTH; j++) {
        if (word->characters[j].content == answer[j]) {
            word->characters[j].isGuessed = true;
            word->characters[j].isPositioned = true;
            matched[j] = true;
        }
    }

    // Check for correct letters in wrong position
    for (int j = 0; j < WORD_LENGTH; j++) {
        if (!word->characters[j].isPositioned) {
            for (int k = 0; k < WORD_LENGTH; k++) {
                if (!matched[k] && word->characters[j].content == answer[k]) {
                    word->characters[j].isGuessed = true;
                    matched[k] = true;
                    break;
                }
            }
        }
    }

    // Check if the whole word is correctly guessed
    bool allPositioned = true;
    for (int p = 0; p < WORD_LENGTH; p++) {
        if (!word->characters[p].isPositioned) {
            allPositioned = false;
            break;
        }
    }
    if (allPositioned) {
        setGuessed(word);
    }
}
