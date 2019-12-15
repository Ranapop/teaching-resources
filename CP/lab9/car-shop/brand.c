//
// Created by roxanappop on 12/15/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brand.h"
#include "input.h"

#define MAX_BRAND_NAME 10

brand createBrand() {
    brand b;
    b.name = (char *) malloc(MAX_BRAND_NAME * sizeof(char));
    b.models = NULL;
    return b;
}

// read brand name and no of models
void readBrand(FILE *f, char *brandName, int *noOfModels) {
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line) - 1] = '\0';
    const char delim[2] = ":";
    char *token;
    //brand name
    token = strtok(line, delim);
    strcpy(brandName, token);
    //noOfModels
    token = strtok(NULL, delim);
    *noOfModels = atoi(token);
}


void readBrandsWithModels(FILE *carDataFile, int *noOfBrandsAddr, brand **brandsAddr) {
    // read no of brands
    int noOfBrands;
    fscanf(carDataFile, "%d", &noOfBrands);
    fgetc(carDataFile);
    brand *brands = (brand *) malloc(noOfBrands * sizeof(brand));
    for (int i = 0; i < noOfBrands; i++) {
        brands[i] = createBrand();
        // read brand & no of models
        readBrand(carDataFile, brands[i].name, &(brands[i].noOfModels));
        // read models
        readModels(carDataFile, &(brands[i].models), brands[i].noOfModels);
    }
    *noOfBrandsAddr = noOfBrands;
    *brandsAddr = brands;
}


void displayBrandOptions(int noOfBrands, brand * brands) {
    // Choose the brand
    printf("Please choose the car brand\n");
    for (int i = 0; i < noOfBrands; i++) {
        putchar('a' + i);
        printf(") %s\n", brands[i].name);
    }
    printf("%c) Go back\n", 'a' + noOfBrands);
}

void freeBrands(brand * brands, int noOfBrands) {
    for (int i = 0; i < noOfBrands; i++) {
        for (int j = 0; j < brands[i].noOfModels; j++) {
            freeModel(&(brands[i].models[j]));
        }
        free(brands[i].models);
        free(brands[i].name);
    }
    free(brands);
}