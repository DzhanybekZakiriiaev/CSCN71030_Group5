#pragma once
#include <stdbool.h>

typedef struct character {
	char content;
	bool isGuessed;
}CHARACTER;

void setGuessed(CHARACTER*);

bool isGuessed(CHARACTER, char);

