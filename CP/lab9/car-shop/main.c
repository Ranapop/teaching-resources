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
