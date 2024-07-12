#include "word.h"
#include "character.h"

void setGuessed(WORD* word) {
    word->isGuessed = true;
}

bool isWordGuessed(WORD word, char* chars) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (!isGuessed(word.characters[i], chars[i])) {
            return false;
        }
    }
    return true;
}
