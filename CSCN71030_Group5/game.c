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
        bool matched[WORD_LENGTH] = { false };
        for (int j = 0; j < WORD_LENGTH; j++) {
            words[i].characters[j].content = input[j];
            words[i].characters[j].isGuessed = false;
            words[i].characters[j].isPositioned = false;
        }
        for (int j = 0; j < WORD_LENGTH; j++) {
            if (words[i].characters[j].content == answer[j]) {
                words[i].characters[j].isGuessed = true;
                words[i].characters[j].isPositioned = true;
                matched[j] = true;
            }
        }
        for (int j = 0; j < WORD_LENGTH; j++) {
            if (!words[i].characters[j].isPositioned) {
                for (int k = 0; k < WORD_LENGTH; k++) {
                    if (!matched[k] && words[i].characters[j].content == answer[k]) {
                        words[i].characters[j].isGuessed = true;
                        matched[k] = true;
                        break;
                    }
                }
            }
        }
        bool allPositioned = true;
        for (int p = 0; p < WORD_LENGTH; p++) {
            if (!words[i].characters[p].isPositioned) {
                allPositioned = false;
                break;
            }
        }
        if (allPositioned) {
            setGuessed(&words[i]);
        }
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