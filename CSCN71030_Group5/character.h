#pragma once
#include <stdbool.h>

typedef struct character {
	char content;
	bool isGuessed;
	bool isPositioned;
}CHARACTER;


bool isGuessed(CHARACTER, char);

