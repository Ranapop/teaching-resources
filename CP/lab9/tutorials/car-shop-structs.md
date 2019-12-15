
# Overview

In this tutorial we will be defining structures for our entities in the `car-shop` application. We could identify:
* buyer (first name, last name, phone number, address)
* model (name, price, brandName)
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

First, we will create 2 new files, 'input.h' and 'input.c'. We will move the implementations of `getChoiceIndex`, `appendCharAtBeginning` and `readPairs` into 'input.c` and expose the following in `input.h` (no need to expose `appendCharAtBeginning`, as it's only used internally in `input.c`):

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
void displayModelOptions(model ** models, int noOfModels, char * brand);
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
void displayModelOptions(model ** models, int noOfModels, char * brand) {
    // Choose the car model
    printf("Please choose the car model for brand %s\n", brand);
    for (int i = 0; i < noOfModels; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", models[i]->name, models[i]->price);
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
