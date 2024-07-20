#pragma once
#include "character.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define WORD_LENGTH 5

typedef struct word{
	CHARACTER characters[WORD_LENGTH];
	bool isGuessed;
}WORD;

void printWords(WORD* word);

void setGuessed(WORD* word);

bool isWordGuessed(WORD, char*);

void printAnswer(char* answer);