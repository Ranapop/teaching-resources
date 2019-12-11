# Overview
In this tutorial you will add the functionality of loading car data in the `car-shop` application from the console. The flow will be:
* the data is loaded from the console
* the user can buy the car (the options are those loaded from the console)


The input format for loading is as follows:
* on the first line the number of brands (noOfBrands)
* the following next 2* _noOFBrands_ lines:
    * \<brand\>:\<noOfModels\>
    * (<model_1>-<price_1>) (<model_2>-<price_2>)    (<model_noOfModels>-<price_noOfModels>)
* number of additional items (noOfAdditionalItems)
* (<item_1>-<price_1>) (<item_1>-<price_2>)    (<item_noOfAdditionalItems>-<price_noOfAdditionalItems>)

Data example:
```
2
audi:2
(audi a3-120) (audi a5-122) 
dacia:1
(dacia logan-1)
3
(blinds-1) (tires-2) (spray-3)
```

# Parsing the input

Add two function definitions in the upper part of the `main.c` file (with the other function definitions) for parsing the brands line and for parsing the models line:
* `void readBrand(char brandName[], int * noOfModels)`
* `void readModels(double * prices, char ** models)`

## Read brand

First, let's write a function for parsing the `<brand>:<noOfModels>` line. We will use `strtok` for dividing the string using the `:` delimiter. We will copy the first token to `brandName` and transform the second token to an int using `atoi` and put it in the `noOfModels`.

```c
// read brand name and no of models
void readBrand(char brandName[], int * noOfModels) {
    char line[MAX_LINE];
    gets(line);
    const char delim[2] = ":";
    char * token;
    //brand name
    token = strtok(line, delim);
    strcpy(brandName,token);
    //noOfModels
    token = strtok(NULL,delim);
    *noOfModels = atoi(token);
}
```
## Read models

We will use `strtok` for parsing the model names as well. We want to parse a string of the form: `(<model_1>-<price_1>) (<model_2>-<price_2>)    (<model_noOfModels>-<price_noOfModels>)` and extract the `model_1` and `model_2` etc. and `price_1` and `price_2` etc.. 

To achieve this, we can use strtok as follows:
* tokenize until `(` and throw the token away -- the space between parantheses
* tokenize until `-` and store the token as the model name
* tokenize until `)` and get the price from the token

There is no space before the first parenthesis, so we will place one. To do that, we will create a function that appends a character at the begining of the string. We can do that by moving the whole string (including the terminator) to the right with one position using `memmove`, then overwriting the character at the first position. We will call it `appendCharAtBeginning`:

```c
void appendCharAtBeginning(char * str, char c) {
    // +1 to include string terminator
    int len = strlen(str)+1;
    memmove(str+1,str,len);
    str[0] = c;
}
```

Once we have this function, we can implement `readModels` as described above.

```c
void readModels(double * prices, char ** models) {
    char line[MAX_LINE];
    gets(line);
    appendCharAtBeginning(line,' ');
    char * token = strtok(line, "(");
    // while token!=null
    int k=0;
    while (token!=NULL) {
        // read model name (until - )
        token = strtok(NULL, "-");
        strcpy(models[k],token);
        // read price (until ")" )
        token = strtok(NULL, ")");
        sscanf(token,"%lf",&prices[k]);
        k++;
        // read space until "("
        token = strtok(NULL, "(");
    }
}
```

Feel free to write code at the begining of the main function to test these functions before moving on.

# Read additional items

To read the additional items we need to parse the same format as for the brands, which means we could use the same function. We will rename it to `void readPairs(double * prices, char ** names)`, as well as doing some renaming in the function implementation:

```c
void readPairs(double * prices, char ** names) {
    char line[MAX_LINE];
    gets(line);
    appendCharAtBeginning(line,' ');
    char * token = strtok(line, "(");
    // while token!=null
    int k=0;
    while (token!=NULL) {
        // read name (until - )
        token = strtok(NULL, "-");
        strcpy(names[k],token);
        // read price (until ")" )
        token = strtok(NULL, ")");
        sscanf(token,"%lf",&prices[k]);
        k++;
        // read space until "("
        token = strtok(NULL, "(");
    }
}
```

# Allocating, filling and freeing the arrays

We keep the same data structures as until now:
* an array of strings - brand names 
* an array of ints - number of models for each brand
* an array of arrays of strings - model names
* an array of arrays of doubles - model prices

To allocate and fill the arrays (at the begining of the main function):
```c
// load data
 // read no of brands
 int noOfBrands = 3;
 scanf("%d", &noOfBrands);
 getchar();
 char **brands = (char **) malloc(noOfBrands * sizeof(char *));
 int *noOfModels = (int *) malloc(noOfBrands * sizeof(int));
 char ***models = (char ***) malloc(noOfBrands * sizeof(char **));
 double **prices = (double **) malloc(noOfBrands * sizeof(double *));
 for (int i = 0; i < noOfBrands; i++) {
     brands[i] = (char *) malloc(MAX_BRAND_NAME * sizeof(char));
     // read brand & no of models
     readBrand(brands[i], &noOfModels[i]);
     // read models
     models[i] = (char **) malloc(noOfModels[i] * sizeof(char *));
     prices[i] = (double *) malloc(noOfModels[i] * sizeof(double));
     for (int j = 0; j < noOfModels[i]; j++) {
         // read model name & model price
         models[i][j] = (char *) malloc(MAX_MODEL_NAME * sizeof(char));
     }
     readPairs(prices[i], models[i]);
 }

 //read additional items
 int noOfAdditionalItems;
 scanf("%d",&noOfAdditionalItems);
 char **additionalItems = (char **) malloc(noOfBrands * sizeof(char *));
 double *additionalItemsPrices = (double *) malloc(noOfBrands * sizeof(double));
 scanf("%d", &noOfAdditionalItems);
 for (int i = 0; i < noOfAdditionalItems; i++) {
     additionalItems[i] = (char *) malloc(MAX_ADDITIONAL_ITEM_NAME * sizeof(char));
 }
 readPairs(additionalItemsPrices, additionalItems);
 ```
 
 To free the arrays (at the end of the main function)
 ```c
 // free memory
 for(int i=0;i<noOfBrands;i++) {
     for(int j=0;j<noOfModels[i];j++) {
         free(models[i][j]);
     }
     free(brands[i]);
     free(models[i]);
     free(prices[i]);
     free(additionalItems[i]);
 }
 free(brands);
 free(noOfModels);
 free(models);
 free(prices);
 free(additionalItems);
 free(additionalItemsPrices);
 ```
 
 # Function changes
 
To work with these dynamically allocated data types we will have to change a few function headers (change the type of the parameters). The file `main.c` becomes:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buyer.h"

#define MAX_BRAND_NAME 10
#define MAX_MODEL_NAME 10
#define MAX_ADDITIONAL_ITEM_NAME 30
#define MAX_LINE 50

void displayBrandOptions(int noOfBrands, char **brands);

void displayModelOptions(int noOfModels, char brand[], char **models, double *prices);

int getChoiceIndex(int noOfChoices, int *state);

void printAdditionalItemsChoices(int noAdditionalItems, char **additionalItems,
                                 double *additionalItemsPrices);

int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int *state);

void displayCarData(char model[], double modelPrice, int noAddItemsChosen, int chosenAdditionalItems[],
                    char **additionalItems,
                    double additionalItemsPrices[]);

void readBrand(char *brandName, int *noOfModels);

void readPairs(double *prices, char **names);

int main() {

    // load data
    // read no of brands
    int noOfBrands = 3;
    scanf("%d", &noOfBrands);
    getchar();
    char **brands = (char **) malloc(noOfBrands * sizeof(char *));
    int *noOfModels = (int *) malloc(noOfBrands * sizeof(int));
    char ***models = (char ***) malloc(noOfBrands * sizeof(char **));
    double **prices = (double **) malloc(noOfBrands * sizeof(double *));
    for (int i = 0; i < noOfBrands; i++) {
        brands[i] = (char *) malloc(MAX_BRAND_NAME * sizeof(char));
        // read brand & no of models
        readBrand(brands[i], &noOfModels[i]);
        // read models
        models[i] = (char **) malloc(noOfModels[i] * sizeof(char *));
        prices[i] = (double *) malloc(noOfModels[i] * sizeof(double));
        for (int j = 0; j < noOfModels[i]; j++) {
            // read model name & model price
            models[i][j] = (char *) malloc(MAX_MODEL_NAME * sizeof(char));
        }
        readPairs(prices[i], models[i]);
    }

    //read additional items
    int noOfAdditionalItems;
    scanf("%d",&noOfAdditionalItems);
    char **additionalItems = (char **) malloc(noOfBrands * sizeof(char *));
    double *additionalItemsPrices = (double *) malloc(noOfBrands * sizeof(double));
    scanf("%d", &noOfAdditionalItems);
    for (int i = 0; i < noOfAdditionalItems; i++) {
        additionalItems[i] = (char *) malloc(MAX_ADDITIONAL_ITEM_NAME * sizeof(char));
    }
    readPairs(additionalItemsPrices, additionalItems);


    printf("Welcome to our car shop.\n");

    //user input
    char firstName[20];
    char lastName[20];
    char phoneNumber[10];
    char address[30];
    int choice, brandChoice, modelChoice;
    int noAddItemsChosen = 0;
    int chosenAdditionalItems[3];

    int state = 0;
    int contractSigned = 0;
    while (!contractSigned) {
        switch (state) {
            case 0: {
                inputPersonalData(firstName, lastName, phoneNumber, address);
                state++;
                break;
            }
            case 1: {
                // Choose the brand
                displayBrandOptions(noOfBrands, brands);
                brandChoice = getChoiceIndex(noOfBrands, &state);
                break;
            }
            case 2: {
                displayModelOptions(noOfModels[brandChoice], brands[brandChoice], models[brandChoice],
                                    prices[brandChoice]);
                modelChoice = getChoiceIndex(noOfModels[brandChoice], &state);
                break;
            }
            case 3: {
                printAdditionalItemsChoices(noOfAdditionalItems, additionalItems, additionalItemsPrices);
                noAddItemsChosen = chooseAdditionalItems(noOfAdditionalItems, chosenAdditionalItems, &state);
                break;
            }
            case 4: {
                // Display contract
                printf("Your contract is:\n");
                printf("-------------\n");
                displayPersonalData(firstName, lastName, phoneNumber, address);
                displayCarData(models[brandChoice][modelChoice], prices[brandChoice][modelChoice],
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
    for(int i=0;i<noOfBrands;i++) {
        for(int j=0;j<noOfModels[i];j++) {
            free(models[i][j]);
        }
        free(brands[i]);
        free(models[i]);
        free(prices[i]);
        free(additionalItems[i]);
    }
    free(brands);
    free(noOfModels);
    free(models);
    free(prices);
    free(additionalItems);
    free(additionalItemsPrices);

    return 0;
}

void displayBrandOptions(int noOfBrands, char **brands) {
    // Choose the brand
    printf("Please choose the car brand\n");
    for (int i = 0; i < noOfBrands; i++) {
        putchar('a' + i);
        printf(") %s\n", brands[i]);
    }
    printf("%c) Go back\n", 'a' + noOfBrands);
}

void displayModelOptions(int noOfModels, char brand[], char **models, double *prices) {
    // Choose the car model
    printf("Please choose the car model for brand %s\n", brand);
    for (int i = 0; i < noOfModels; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", models[i], prices[i]);
    }
    printf("%c) Go back\n", 'a' + noOfModels);
}

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


void displayCarData(char model[], double modelPrice, int noAddItemsChosen, int chosenAdditionalItems[],
                    char **additionalItems,
                    double additionalItemsPrices[]) {
    printf("Car data:\n");
    printf("-car model: %s (%.2f)\n", model, modelPrice);
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
    printf("Total price: %.2f\n", modelPrice + additionalItemsPrice);
}

// read brand name and no of models
void readBrand(char *brandName, int *noOfModels) {
    char *line = (char *) malloc(MAX_LINE * sizeof(char));
    gets(line);
    const char delim[2] = ":";
    char *token;
    //brand name
    token = strtok(line, delim);
    strcpy(brandName, token);
    //noOfModels
    token = strtok(NULL, delim);
    *noOfModels = atoi(token);
}

void appendCharAtBeginning(char *str, char c) {
    // +1 to include string terminator
    int len = strlen(str) + 1;
    memmove(str + 1, str, len);
    str[0] = ' ';
}

void readPairs(double *prices, char **names) {
    char line[MAX_LINE];
    gets(line);
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
```
