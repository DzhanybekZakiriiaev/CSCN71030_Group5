#include "input.h"
#include <string.h>

char* getValidStringInput(char* prompt, int maxLength) {
    printf("%s", prompt);
    char* stringArray = (char*)malloc(maxLength * sizeof(char));
    if (stringArray == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    fgets(stringArray, maxLength, stdin);
    size_t length = strlen(stringArray); 
    if (stringArray[length - 1] == '\n') {
        stringArray[length - 1] = '\0';
    }
    else {
        while (getchar() != '\n');
    }
    return _strupr(stringArray);
}

int getValidInt(char* prompt, int minValue, int maxValue) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1 || input < minValue || input > maxValue) {
        while (getchar() != '\n');
        printf("\033[31mInvalid input. Please enter an number between %d and %d\n\033[0m", minValue, maxValue);
        printf("%s", prompt);
    }
    while ((getchar()) != '\n');
    return input;
}

