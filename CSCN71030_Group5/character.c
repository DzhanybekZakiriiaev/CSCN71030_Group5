#include "character.h"
#include "stdio.h"
#include <string.h>

bool isGuessed(CHARACTER character, char content) {
    return tolower(character.content) == tolower(content);
}
