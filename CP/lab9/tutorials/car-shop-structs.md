
# Overview

In this tutorial we will be defining structures for our entities in the `car-shop` application. We could identify:
* buyer (first name, last name, phone number, address)
* model (name, price)
* brand (name, noOfModels, models)
* additional item (name, price)
* contract (buyer, model, additional items)

# Buyer

## Defining the structure

Start by defining a structure for the buyer in `buyer.h`:

```c
typedef struct _buyer {
    char * firstName;
    char * lastName;
    char * phoneNumber;
    char * address;
} buyer;
```

## Allocating memory for members

If we're defining the structure members like this, we will need to dynamically allocate them. For this, in `buyer.c` we define some constants:

```c
#define MAX_BUYER_NAME 20
#define  MAX_PHONE_NUMBER 10
#define MAX_ADDRESS 30
```
and create a function which allocates the memory for the structure:

```c
buyer createBuyer(){
    buyer b;
    b.firstName = (char*)malloc(MAX_BUYER_NAME* sizeof(char));
    b.lastName = (char*)malloc(MAX_BUYER_NAME* sizeof(char));
    b.phoneNumber = (char*)malloc(MAX_PHONE_NUMBER* sizeof(char));
    b.address = (char*)malloc(MAX_ADDRESS* sizeof(char));
    return b;
}
```
We expose this function in `buyer.h`:

```c
buyer createBuyer();
```

## Using the structure in inputPersonalData & displayPersonalData

In main.c, we can use this function now to create a new buyer (put it with the other declarations, for ex after chosenAdditionalItems:

```c
buyer b = createBuyer();
```

Now we can change the functions `inputPersonalData` and `displayPersonalData` to use this structure instead. Their implementations become:
```c
void inputPersonalData(buyer b) {
    // Input personal data
    printf("Please input your data\n");
    printf("---First name:\n");
    gets(b.firstName);
    printf("---Last name:\n");
    gets(b.lastName);
    readPhoneNumber(b.phoneNumber);
    printf("---Address\n");
    gets(b.address);
}

void displayPersonalData(buyer b) {
    printf("Customer data:\n");
    printf("-name: %s %s\n", b.firstName, b.lastName);
    printf("-phone number: %s\n", b.phoneNumber);
    printf("-address: %s\n", b.address);
}
```
and their definitions (`buyer.h`):
```c
void inputPersonalData(buyer b);
void displayPersonalData(buyer b);
```

We can use them in main.c like this:
```c
inputPersonalData(b);
```
```c
displayPersonalData(b);
```
and we can remove from `main()` the following:
```c
char firstName[20];
char lastName[20];
char phoneNumber[10];
char address[30];
```

## Pass by reference

It's better to pass structures by reference (sending just the address, not the whole data). We will modify our functions to do that. 
In `buyer.c`:
```c
void inputPersonalData(buyer * b) {
    // Input personal data
    printf("Please input your data\n");
    printf("---First name:\n");
    gets(b->firstName);
    printf("---Last name:\n");
    gets(b->lastName);
    readPhoneNumber(b->phoneNumber);
    printf("---Address\n");
    gets(b->address);
}

void displayPersonalData(buyer * b) {
    printf("Customer data:\n");
    printf("-name: %s %s\n", b->firstName, b->lastName);
    printf("-phone number: %s\n", b->phoneNumber);
    printf("-address: %s\n", b->address);
}
```
In buyer.h:
```c
void inputPersonalData(buyer * b);
void displayPersonalData(buyer * b);
```
And in `main.c`:
```c
inputPersonalData(&b);
```
```c
displayPersonalData(&b);
```

# Model

## Refactoring

First, we will create 2 new files, `input.h` and `input.c`. We will move the implementations of `getChoiceIndex`, `appendCharAtBeginning` and `readPairs` into `input.c` and expose the following in `input.h` (no need to expose `appendCharAtBeginning`, as it's only used internally in `input.c`):

```c
//
// Created by roxanappop on 12/15/2019.
//

#ifndef CAR_SHOP_INPUT_H
#define CAR_SHOP_INPUT_H

#define MAX_LINE 50

int getChoiceIndex(int noOfChoices, int *state);
void readPairs(FILE *f, double *prices, char **names);

#endif //CAR_SHOP_INPUT_H
```
# Files model.h and model.c

Create a file `model.h` with the following content:
```c
#ifndef CAR_SHOP_MODEL_H
#define CAR_SHOP_MODEL_H

typedef struct _model {
    char * name;
    double price;
} model;

void readModels(FILE * carDataFile, model ** modelsAddr, int noOfModels);
void displayModelOptions(model * models, int noOfModels, char * brand);
void displayModel(model * m);
void freeModel(model * m);

#endif //CAR_SHOP_MODEL_H
```
and the implementations in `model.c`:
```c
#include "input.h"

#define MAX_MODEL_NAME 10

// will be used in readData
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

// will replace the previous displayModelOptions impl
void displayModelOptions(model * models, int noOfModels, char * brand) {
    // Choose the car model
    printf("Please choose the car model for brand %s\n", brand);
    for (int i = 0; i < noOfModels; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", models[i].name, models[i].price);
    }
    printf("%c) Go back\n", 'a' + noOfModels);
}

// will be used in displayCarData
void displayModel(model * m) {
    printf("%s (%.2f)\n", m->name, m->price);
}

//will be used in freeData
void freeModel(model * m) {
    free(m->name);
}
```

In `main.c` get rid of the `models` and `prices` variables, and create:
```c
model ** modelsMatrix;
```
Do the necessary modifications to use the functions in `model.h` and have your code build. The function headers used in main should look like:
```c
void displayBrandOptions(int noOfBrands, char **brands);

void printAdditionalItemsChoices(int noAdditionalItems, char **additionalItems,
                                 double *additionalItemsPrices);

int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int *state);

void displayCarData(model * m, int noAddItemsChosen, int chosenAdditionalItems[],
                    char **additionalItems,
                    double additionalItemsPrices[]);

void readBrand(FILE *f, char *brandName, int *noOfModels);

void readData(FILE *carDataFile, int *noOfBrandsAddr, char ***brandsAddr, int **noOfModelsAddr, model ***modelsAddr,
              int *noOfAdditionalItemsAddr, char ***additionalItemsAddr, double **additionalItemsPricesAddr);

void freeData(int noOfBrands, char **brands, int *noOfModels, model **models,
              int noOfAdditionalItems, char **additionalItems, double *additionalItemsPrices);
```
If you have issues adapting the implementation yourself, you can look over: https://github.com/Ranapop/teaching-resources/tree/master/CP/lab9/tutorials/aux/after-model

# Brand

Create files `brand.h` and `brand.c` with the following content:

brand.h
```c
typedef struct _brand {
    char * name;
    int noOfModels;
    model * models;
} brand;

void readBrandsWithModels(FILE *carDataFile, int *noOfBrandsAddr, brand ** brandsAddr);
void displayBrandOptions(int noOfBrands, brand * brands);
void freeBrands(brand * brands, int noOfBrands);
```
brand.c
```c
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
```

And change the `main.c` file accordingly, resulting in:
```c
#include <stdio.h>
#include <stdlib.h>
#include "buyer.h"
#include "input.h"
#include "model.h"
#include "brand.h"

#define MAX_ADDITIONAL_ITEM_NAME 30

#define FILE_PATH "../data.txt"

void printAdditionalItemsChoices(int noAdditionalItems, char **additionalItems,
                                 double *additionalItemsPrices);

int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int *state);

void displayCarData(model *m, int noAddItemsChosen, int chosenAdditionalItems[],
                    char **additionalItems,
                    double additionalItemsPrices[]);

void readData(FILE *carDataFile, int *noOfBrandsAddr, brand **brandsAddr,
              int *noOfAdditionalItemsAddr, char ***additionalItemsAddr, double **additionalItemsPricesAddr);

void freeData(brand *brands, int noOfBrands,
              int noOfAdditionalItems, char **additionalItems, double *additionalItemsPrices);

int main() {

    FILE *carDataFile;
    carDataFile = fopen(FILE_PATH, "r");
    if (carDataFile == NULL) {
        perror("File could not be open");
        exit(-1);
    }

    int noOfBrands;
    brand *brands;
    int noOfAdditionalItems;
    char **additionalItems;
    double *additionalItemsPrices;

    readData(carDataFile, &noOfBrands, &brands,
             &noOfAdditionalItems, &additionalItems, &additionalItemsPrices);

    fclose(carDataFile);

    printf("Welcome to our car shop.\n");

    //user input
    int choice, brandChoice, modelChoice;
    int noAddItemsChosen = 0;
    int chosenAdditionalItems[3];

    buyer b = createBuyer();
    enum State {
        INPUT_BUYER_DATA, CHOOSE_BRAND, CHOOSE_MODEL, CHOOSE_ADDITIONAL_ITEM, SIGN_CONTRACT
    };

    int state = 0;
    int contractSigned = 0;
    while (!contractSigned) {
        switch (state) {
            case INPUT_BUYER_DATA: {
                inputPersonalData(&b);
                state++;
                break;
            }
            case CHOOSE_BRAND: {
                displayBrandOptions(noOfBrands, brands);
                brandChoice = getChoiceIndex(noOfBrands, &state);
                break;
            }
            case CHOOSE_MODEL: {
                displayModelOptions(brands[brandChoice].models, brands[brandChoice].noOfModels,
                                    brands[brandChoice].name);
                modelChoice = getChoiceIndex(brands[brandChoice].noOfModels, &state);
                break;
            }
            case CHOOSE_ADDITIONAL_ITEM: {
                printAdditionalItemsChoices(noOfAdditionalItems, additionalItems, additionalItemsPrices);
                noAddItemsChosen = chooseAdditionalItems(noOfAdditionalItems, chosenAdditionalItems, &state);
                break;
            }
            case SIGN_CONTRACT: {
                // Display contract
                printf("Your contract is:\n");
                printf("-------------\n");
                displayPersonalData(&b);
                displayCarData(&(brands[brandChoice].models[modelChoice]),
                               noAddItemsChosen, chosenAdditionalItems, additionalItems, additionalItemsPrices);
                printf("-------------\n");
                printf("a) Sign\n");
                printf("b) Go back\n");
                choice = getchar();
                if (choice == 'a') {
                    contractSigned = 1;
                } else {
                    state--;
                }
                // consume new line
                getchar();
                break;
            }
        }
    }

    // free memory
    freeData(brands, noOfBrands,
             noOfAdditionalItems, additionalItems, additionalItemsPrices);
    return 0;
}

void printAdditionalItemsChoices(int noAdditionalItems, char **additionalItems, double *additionalItemsPrices) {
    // Choose the additional items
    printf("Choose additional items (separated by comma)\n");
    for (int i = 0; i < noAdditionalItems; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", additionalItems[i], additionalItemsPrices[i]);
    }
    printf("%c) Go back\n", 'a' + noAdditionalItems);
}

int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int *state) {

    int noAddItemsChosen = 0;

    char choice = getchar();
    if (choice == 'a' + noAdditionalItems) {
        (*state)--;
        //consume new line
        getchar();
    } else {
        noAddItemsChosen = 0;
        while (choice != '\n') {

            chosenAdditionalItems[noAddItemsChosen] = choice - 'a';
            noAddItemsChosen++;
            //read comma
            char comma = getchar();
            if (comma == '\n') {
                //after the last letter, a new line entered
                break;
            }
            choice = getchar();
        }
        (*state)++;
    }
    return noAddItemsChosen;
}


void displayCarData(model *m, int noAddItemsChosen, int chosenAdditionalItems[],
                    char **additionalItems,
                    double additionalItemsPrices[]) {
    printf("Car data:\n");
    printf("-car model:");
    displayModel(m);
    double additionalItemsPrice = 0;
    for (int i = 0; i < noAddItemsChosen; i++) {
        additionalItemsPrice += additionalItemsPrices[chosenAdditionalItems[i]];
    }
    printf("-additional items (%.2f)\n", additionalItemsPrice);
    if (noAddItemsChosen != 0) {
        for (int i = 0; i < noAddItemsChosen; i++) {
            printf("--%s (%.2f)\n", additionalItems[chosenAdditionalItems[i]],
                   additionalItemsPrices[chosenAdditionalItems[i]]);
        }
    }
    printf("Total price: %.2f\n", m->price + additionalItemsPrice);
}

void readAdditionalItems(FILE *carDataFile, int *noOfAdditionalItemsAddr, char ***additionalItemsAddr,
                         double **additionalItemsPricesAddr) {
    //read additional items
    int noOfAdditionalItems;
    fscanf(carDataFile, "%d", &noOfAdditionalItems);
    fgetc(carDataFile);
    char **additionalItems = (char **) malloc(noOfAdditionalItems * sizeof(char *));
    double *additionalItemsPrices = (double *) malloc(noOfAdditionalItems * sizeof(double));
    fscanf(carDataFile, "%d", &noOfAdditionalItems);
    for (int i = 0; i < noOfAdditionalItems; i++) {
        additionalItems[i] = (char *) malloc(MAX_ADDITIONAL_ITEM_NAME * sizeof(char));
    }
    readPairs(carDataFile, additionalItemsPrices, additionalItems);
    *noOfAdditionalItemsAddr = noOfAdditionalItems;
    *additionalItemsAddr = additionalItems;
    *additionalItemsPricesAddr = additionalItemsPrices;
}

void readData(FILE *carDataFile, int *noOfBrandsAddr, brand **brandsAddr,
              int *noOfAdditionalItemsAddr, char ***additionalItemsAddr, double **additionalItemsPricesAddr) {
    readBrandsWithModels(carDataFile, noOfBrandsAddr, brandsAddr);
    readAdditionalItems(carDataFile, noOfAdditionalItemsAddr, additionalItemsAddr, additionalItemsPricesAddr);
}

void freeData(brand *brands, int noOfBrands,
              int noOfAdditionalItems, char **additionalItems, double *additionalItemsPrices) {
    freeBrands(brands, noOfBrands);
    for (int i = 0; i < noOfAdditionalItems; i++) {
        free(additionalItems[i]);
    }
    free(additionalItems);
    free(additionalItemsPrices);
}
```
You can see the final changes in the `car-shop` folder of this lab (`lab9`) as well.
