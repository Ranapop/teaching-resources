#include <stdio.h>
#include "buyer.h"

#define MAX_BRAND_NAME 10
#define MAX_MODEL_NAME 10
#define MAX_ADDITIONAL_ITEM_NAME 30

void displayBrandOptions(int noOfBrands, char brands[][MAX_BRAND_NAME]);
void displayModelOptions(int noOfModels, char brand[], char models[][MAX_MODEL_NAME], double prices[]);
int getChoiceIndex(int noOfChoices, int *state);
void printAdditionalItemsChoices(int noAdditionalItems, char additionalItems[][MAX_ADDITIONAL_ITEM_NAME], double additionalItemsPrices[]);
int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int * state);
void displayCarData(char model[], double modelPrice, int noAddItemsChosen, int chosenAdditionalItems[], char additionalItems[][MAX_ADDITIONAL_ITEM_NAME],
                    double additionalItemsPrices[]);

int main() {
    printf("Welcome to our car shop.\n");

    // cars data
    int noOfBrands = 3;
    char brands[][10] = {"Audi","BMW","Bentley"};
    int noModels[] = {3,3,3};
    char models[3][3][10] = {
            {"Audi A7", "Audi A8", "Audi Q2"},
            {"BMW 1", "BMW 2", "BMW 3"},
            {"Bentley 1", "Bentley 2", "Bentley 3"}
    };
    double prices[3][3] = {
            {50000, 60000, 70000},
            {50001, 60002, 70003},
            {150000, 160000, 170000}
    };

    int noAdditionalItems = 3;
    char additionalItems[][MAX_ADDITIONAL_ITEM_NAME] = {"Winter tires","Roof box","Wireless charger"};
    double additionalItemsPrices[] = {200, 400, 50};

    //user input
    char firstName[20];
    char lastName[20];
    char phoneNumber[10];
    char address[30];
    int choice, brandChoice, modelChoice;
    int noAddItemsChosen = 0;
    int chosenAdditionalItems[3];

    int state =0;
    int contractSigned = 0;
    while(!contractSigned){
        switch (state) {
            case 0: {
                inputPersonalData(firstName, lastName, phoneNumber, address);
                state++;
                break;
            }
            case 1: {
                // Choose the brand
                displayBrandOptions(noOfBrands,brands);
                brandChoice = getChoiceIndex(noOfBrands, &state);
                break;
            }
            case 2: {
                displayModelOptions(noModels[brandChoice], brands[brandChoice], models[brandChoice], prices[brandChoice]);
                modelChoice = getChoiceIndex(noModels[brandChoice], &state);
                break;
            }
            case 3: {
                printAdditionalItemsChoices(noAdditionalItems, additionalItems, additionalItemsPrices);
                noAddItemsChosen = chooseAdditionalItems(noAdditionalItems, chosenAdditionalItems, &state);
                break;
            }
            case 4:{
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
                if(choice=='a') {
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
    return 0;
}

void displayBrandOptions(int noOfBrands, char brands[][MAX_BRAND_NAME]) {
    // Choose the brand
    printf("Please choose the car brand\n");
    for(int i=0;i<noOfBrands;i++) {
        putchar('a'+i);
        printf(") %s\n",brands[i]);
    }
    printf("%c) Go back\n",'a'+noOfBrands);
}

void displayModelOptions(int noOfModels, char brand[], char models[][MAX_MODEL_NAME], double prices[]) {
    // Choose the car model
    printf("Please choose the car model for brand %s\n",brand);
    for(int i=0;i<noOfModels;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",models[i], prices[i]);
    }
    printf("%c) Go back\n",'a'+noOfModels);
}

int getChoiceIndex(int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    // consume new line
    getchar();
    if(choice == 'a'+noOfChoices) {
        (*state)--; // *state-- <=> *(state--)
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

void printAdditionalItemsChoices(int noAdditionalItems, char additionalItems[][MAX_ADDITIONAL_ITEM_NAME], double additionalItemsPrices[]) {
    // Choose the additional items
    printf("Choose additional items (separated by comma)\n");
    for (int i = 0; i < noAdditionalItems; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", additionalItems[i], additionalItemsPrices[i]);
    }
    printf("%c) Go back\n", 'a' + noAdditionalItems);
}

int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int * state) {

    int noAddItemsChosen = 0;

    char choice = getchar();
    if(choice == 'a'+noAdditionalItems) {
        (*state)--;
        //consume new line
        getchar();
    } else {
        noAddItemsChosen = 0;
        while (choice !='\n') {

            chosenAdditionalItems[noAddItemsChosen] = choice - 'a';
            noAddItemsChosen++;
            //read comma
            char comma = getchar();
            if(comma=='\n'){
                //after the last letter, a new line entered
                break;
            }
            choice = getchar();
        }
        (*state)++;
    }
    return noAddItemsChosen;
}


void displayCarData(char model[], double modelPrice, int noAddItemsChosen, int chosenAdditionalItems[], char additionalItems[][MAX_ADDITIONAL_ITEM_NAME],
                    double additionalItemsPrices[]) {
    printf("Car data:\n");
    printf("-car model: %s (%.2f)\n", model, modelPrice);
    double additionalItemsPrice = 0;
    for(int i=0;i<noAddItemsChosen;i++) {
        additionalItemsPrice += additionalItemsPrices[chosenAdditionalItems[i]];
    }
    printf("-additional items (%.2f)\n", additionalItemsPrice);
    if(noAddItemsChosen!=0){
        for(int i=0;i<noAddItemsChosen;i++) {
            printf("--%s (%.2f)\n", additionalItems[chosenAdditionalItems[i]], additionalItemsPrices[chosenAdditionalItems[i]]);
        }
    }
    printf("Total price: %.2f\n", modelPrice + additionalItemsPrice);
}