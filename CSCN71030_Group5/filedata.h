#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void saveUser(char* username, int gamescore);
int loadUser(char* username);
int deleteData(char* username);
char* loadList(int choice);