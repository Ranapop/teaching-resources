//
// Created by roxanappop on 12/15/2019.
//
#include <stdio.h>
#include <string.h>
#include "input.h"

int getChoiceIndex(int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    // consume new line
    getchar();
    if (choice == 'a' + noOfChoices) {
        (*state)--; // *state-- <=> *(state--)
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

void appendCharAtBeginning(char *str, char c) {
    // +1 to include string terminator
    int len = strlen(str) + 1;
    memmove(str + 1, str, len);
    str[0] = ' ';
}

void readPairs(FILE *f, double *prices, char **names) {
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line) - 1] = '\0';
    appendCharAtBeginning(line, ' ');
    char *token = strtok(line, "(");
    // while token!=null
    int k = 0;
    while (token != NULL) {
        // read name (until - )
        token = strtok(NULL, "-");
        strcpy(names[k], token);
        // read price (until ")" )
        token = strtok(NULL, ")");
        sscanf(token, "%lf", &prices[k]);
        k++;
        // read space until "("
        token = strtok(NULL, "(");
    }
}