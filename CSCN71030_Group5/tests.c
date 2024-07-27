#include "tests.h"

void test_REQ_GM_001() {
    bool pass = true;

    char target[WORD_LENGTH] = "APPLE";
    WORD guess = { {{'A', false, false}, {'P', false, false}, {'R', false, false}, {'O', false, false}, {'N', false, false}}, false };
    check(target, &guess);

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (target[i] == guess.characters[i].content) {
            if (!guess.characters[i].isGuessed || !guess.characters[i].isPositioned) {
                pass = false;
                break;
            }
        }
    }

    if (pass) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void test_REQ_GM_002() {
    bool pass = true;

    char target[WORD_LENGTH] = "APPLE";
    WORD guess = { {{'P', false, false}, {'L', false, false}, {'A', false, false}, {'N', false, false}, {'E', false, false}}, false };
    check(target, &guess);

    for (int i = 0; i < WORD_LENGTH; i++) {
        if (strchr(target, guess.characters[i].content) && target[i] != guess.characters[i].content) {
            if (!guess.characters[i].isGuessed || guess.characters[i].isPositioned) {
                pass = false;
                break;
            }
        }
    }

    if (pass) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void test_REQ_GM_003() {
    char target[WORD_LENGTH] = "APPLE";
    WORD guess = { {{'P', false, false}, {'U', false, false}, {'P', false, false}, {'P', false, false}, {'Y', false, false}}, false };
    check(target, &guess);

    int count = 0;
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guess.characters[i].content == 'P') {
            if ((guess.characters[i].isGuessed && !guess.characters[i].isPositioned) || (guess.characters[i].isGuessed && guess.characters[i].isPositioned)) {
                count++;
            }
        }
    }

    if (count == 2) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void test_REQ_GM_004() {
    bool pass = true;

    char target[WORD_LENGTH] = "APPLE";
    WORD guess = { {{'A', false, false}, {'P', false, false}, {'P', false, false}, {'L', false, false}, {'E', false, false}}, false };
    check(target, &guess);

    if (!guess.isGuessed) {
        pass = false;
    }

    if (pass) {
        printf("PASS\n");
    }
    else {
        printf("FAIL\n");
    }
}

void test_REQ_GM_005() {
    bool pass = true;

    char target[WORD_LENGTH] = "APPLE";
    WORD guesses[] = {
        {{{'A', false, false}, {'P', false, false}, {'R', false, false}, {'O', false, false}, {'N', false, false}}, false},
        {{{'P', false, false}, {'L', false, false}, {'A', false, false}, {'N', false, false}, {'E', false, false}}, false},
        {{{'A', false, false}, {'P', false, false}, {'P', false, false}, {'L', false, false}, {'E', false, false}}, false},
        {{{' ', false, false}, {' ', false, false}, {' ', false, false}, {' ', false, false}, {' ', false, false}}, false},
        {{{' ', false, false}, {' ', false, false}, {' ', false, false}, {' ', false, false}, {' ', false, false}}, false},
        {{{' ', false, false}, {' ', false, false}, {' ', false, false}, {' ', false, false}, {' ', false, false}}, false}
    };

    for (int i = 0; i < 3; i++) {
        check(target, &guesses[i]);
    }

    printWords(guesses);

    printf("Check the printed feedback history to verify the correctness.\n");
}