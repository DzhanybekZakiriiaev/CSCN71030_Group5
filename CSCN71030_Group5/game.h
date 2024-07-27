#pragma once
#include "character.h"
#include "word.h"
#include "input.h"
#include <stdio.h>

int roundGame(char* word);

void initWords(WORD* words);

void check(char* answer, WORD* word);