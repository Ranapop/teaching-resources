//
// Created by roxanappop on 12/15/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "model.h"
#include "input.h"

#define MAX_MODEL_NAME 10

void readModels(FILE * carDataFile, model ** modelsAddr, int noOfModels) {
    model * models = (model*)malloc(noOfModels * sizeof(model));
    // allocate temporary arrays
    char ** names = (char **) malloc(noOfModels* sizeof(char *));
    double * prices = (double *) malloc(noOfModels * sizeof(double));
    for (int i = 0; i < noOfModels; i++) {
        // read model name & model price
        names[i] = (char *) malloc(MAX_MODEL_NAME * sizeof(char));
    }
    readPairs(carDataFile, prices, names);
    //put the data in a models array
    for(int i=0; i<noOfModels; i++) {
        models[i].name = names[i];
        models[i].price = prices[i];
    }
    // free temporary data, do not free the strings themselves
    free(names);
    free(prices);
    *modelsAddr = models;
}

void displayModelOptions(model * models, int noOfModels, char * brand) {
    // Choose the car model
    printf("Please choose the car model for brand %s\n", brand);
    for (int i = 0; i < noOfModels; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", models[i].name, models[i].price);
    }
    printf("%c) Go back\n", 'a' + noOfModels);
}

void displayModel(model * m) {
    printf("%s (%.2f)\n", m->name, m->price);
}

void freeModel(model * m) {
    free(m->name);
}