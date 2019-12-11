#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buyer.h"

#define MAX_BRAND_NAME 10
#define MAX_MODEL_NAME 10
#define MAX_ADDITIONAL_ITEM_NAME 30
#define MAX_LINE 50

#define FILE_PATH "../data.txt"

void displayBrandOptions(int noOfBrands, char **brands);

void displayModelOptions(int noOfModels, char brand[], char **models, double *prices);

int getChoiceIndex(int noOfChoices, int *state);

void printAdditionalItemsChoices(int noAdditionalItems, char **additionalItems,
                                 double *additionalItemsPrices);

int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int *state);

void displayCarData(char model[], double modelPrice, int noAddItemsChosen, int chosenAdditionalItems[],
                    char **additionalItems,
                    double additionalItemsPrices[]);

void readBrand(FILE *f, char *brandName, int *noOfModels);

void readPairs(FILE *f, double *prices, char **names);

void readData(FILE *carDataFile, int *noOfBrandsAddr, char ***brandsAddr, int **noOfModelsAddr,
              char ****modelsAddr, double ***pricesAddr,
              int *noOfAdditionalItemsAddr, char ***additionalItemsAddr, double **additionalItemsPricesAddr);

void freeData(int noOfBrands, char **brands, int *noOfModels,
              char ***models, double **prices,
              int noOfAdditionalItems, char **additionalItems, double *additionalItemsPrices);

int main() {

    FILE *carDataFile;
    carDataFile = fopen(FILE_PATH, "r");
    if (carDataFile == NULL) {
        perror("File could not be open");
        exit(-1);
    }

    int noOfBrands;
    char **brands;
    int *noOfModels;
    char ***models;
    double **prices;
    int noOfAdditionalItems;
    char **additionalItems;
    double *additionalItemsPrices;

    readData(carDataFile, &noOfBrands, &brands, &noOfModels, &models, &prices,
             &noOfAdditionalItems, &additionalItems, &additionalItemsPrices);

    fclose(carDataFile);

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
    freeData(noOfBrands, brands, noOfModels, models, prices,
             noOfAdditionalItems, additionalItems, additionalItemsPrices);
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

void readBrandsWithModels(FILE *carDataFile, int *noOfBrandsAddr, char ***brandsAddr, int **noOfModelsAddr,
                          char ****modelsAddr, double ***pricesAddr) {
    // read no of brands
    int noOfBrands;
    fscanf(carDataFile, "%d", &noOfBrands);
    fgetc(carDataFile);
    char **brands = (char **) malloc(noOfBrands * sizeof(char *));
    int *noOfModels = (int *) malloc(noOfBrands * sizeof(int));
    char ***models = (char ***) malloc(noOfBrands * sizeof(char **));
    double **prices = (double **) malloc(noOfBrands * sizeof(double *));
    for (int i = 0; i < noOfBrands; i++) {
        brands[i] = (char *) malloc(MAX_BRAND_NAME * sizeof(char));
        // read brand & no of models
        readBrand(carDataFile, brands[i], &noOfModels[i]);
        // read models
        models[i] = (char **) malloc(noOfModels[i] * sizeof(char *));
        prices[i] = (double *) malloc(noOfModels[i] * sizeof(double));
        for (int j = 0; j < noOfModels[i]; j++) {
            // read model name & model price
            models[i][j] = (char *) malloc(MAX_MODEL_NAME * sizeof(char));
        }
        readPairs(carDataFile, prices[i], models[i]);
    }
    *noOfBrandsAddr = noOfBrands;
    *brandsAddr = brands;
    *noOfModelsAddr = noOfModels;
    *modelsAddr = models;
    *pricesAddr = prices;
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

void readData(FILE *carDataFile, int *noOfBrandsAddr, char ***brandsAddr, int **noOfModelsAddr,
              char ****modelsAddr, double ***pricesAddr,
              int *noOfAdditionalItemsAddr, char ***additionalItemsAddr, double **additionalItemsPricesAddr) {
    readBrandsWithModels(carDataFile, noOfBrandsAddr, brandsAddr, noOfModelsAddr, modelsAddr, pricesAddr);
    readAdditionalItems(carDataFile, noOfAdditionalItemsAddr, additionalItemsAddr, additionalItemsPricesAddr);
}

void freeData(int noOfBrands, char **brands, int *noOfModels,
              char ***models, double **prices,
              int noOfAdditionalItems, char **additionalItems, double *additionalItemsPrices) {

    for (int i = 0; i < noOfBrands; i++) {
        for (int j = 0; j < noOfModels[i]; j++) {
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
    for (int i = 0; i < noOfAdditionalItems; i++) {
        free(additionalItems[i]);
    }
    free(additionalItems);
    free(additionalItemsPrices);
}