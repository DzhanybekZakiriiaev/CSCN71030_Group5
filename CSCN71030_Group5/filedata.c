#define _CRT_SECURE_NO_WARNINGS
#include "filedata.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LINE_MAX 7

int loadUser(char* username) {
	FILE* user;

	user = fopen(username, "r");
	if (user == NULL) {
		printf("No data found! \n");
		return 0;
	}
	int s = 0;
	fscanf(user, "%d", &s);
	fclose(user);
	return s;
}
int deleteData(char* username) {
	return remove(username);
}
void saveUser(char* username, int gamescore) {
	FILE* user;
	user = fopen(username, "w");
	if (user == NULL) {
		printf("No data found! \n");
		return 0;
	}
	fprintf(user, "%d", gamescore);
	fclose(user);
}
char* loadList(int choice) {
	FILE* list;
	int read = 5, line = 1;
	char* gameword = malloc(sizeof(gameword));
	bool reader = true;

	srand(time(NULL));
	read = rand();
	read = read % 2803;
	if (choice == 1) {

		list = fopen("word5.txt", "r");
		if (list == NULL) {
			printf("FILE ERROR");
			return 1;
		}
		do {
			fgets(gameword, LINE_MAX, list);
			if (feof(list)) {
				reader = false;
			}
			else if (line == read) {
				reader = false;
			}
			line = line + 1;
		} while (reader == true);


	}

	char* ret = malloc(sizeof(ret));
	ret = gameword;
	return ret;

}