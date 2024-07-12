#pragma once
#include "character.h"
#include <stdbool.h>
#define WORD_LENGTH 5

typedef struct word{
	CHARACTER characters[WORD_LENGTH];
	bool isGuessed;
}WORD;

void setGuessed(WORD*);

bool isWordGuessed(WORD, char*);