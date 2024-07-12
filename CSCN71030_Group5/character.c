#include "character.h"

void setGuessed(CHARACTER* character) {
    character->isGuessed = true;
}

bool isGuessed(CHARACTER character, char content) {
    return tolower(character.content) == tolower(content);
}
