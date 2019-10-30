#include <stdio.h>

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
    char additionalItems[][30] = {"Winter tires","Roof box","Wireless charger"};
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
                // Input personal data
                printf("Please input your data\n");
                printf("---First name:\n");
                gets(firstName);
                printf("---Last name:\n");
                gets(lastName);
                printf("---Phone number\n");
                gets(phoneNumber);
                printf("---Address\n");
                gets(address);
                state++;
                break;
            }
            case 1: {
                // Choose the brand
                printf("Please choose the car brand\n");
                for(int i=0;i<noOfBrands;i++) {
                    putchar('a'+i);
                    printf(") %s\n",brands[i]);
                }
                printf("%c) Go back\n",'a'+noOfBrands);
                choice = getchar();
                // consume new line
                getchar();
                if(choice == 'a'+noOfBrands) {
                    state--;
                    break;
                }
                brandChoice = choice - 'a';
                state++;
                break;
            }
            case 2: {
                // Choose the car model
                printf("Please choose the car model for brand %s\n",brands[brandChoice]);
                for(int i=0;i<noModels[brandChoice];i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n",models[brandChoice][i], prices[brandChoice][i]);
                }
                printf("%c) Go back\n",'a'+noModels[brandChoice]);
                choice = getchar();
                // consume new line
                getchar();
                if(choice == 'a'+noModels[brandChoice]) {
                    state--;
                    break;
                }
                modelChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                // Choose the additional items
                printf("Choose additional items (separated by comma)\n");
                for(int i=0;i<noAdditionalItems;i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n", additionalItems[i], additionalItemsPrices[i]);
                }
                printf("%c) Go back\n",'a'+noAdditionalItems);
                //read additional items

                //we want to check here for '\n' to allow the user to select 0 additional items
                choice = getchar();
                if(choice == 'a'+noAdditionalItems) {
                    state--;
                    //consume new line
                    getchar();
                    break;
                }
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
                state++;
                break;
            }
            case 4:{
                // Display contract
                printf("Your contract is:\n");
                printf("-------------\n");
                printf("Customer data:\n");
                printf("-name: %s %s\n", firstName, lastName);
                printf("-phone number: %s\n", phoneNumber);
                printf("-address: %s\n", address);
                printf("Car data:\n");
                printf("-car model: %s (%.2f)\n", models[brandChoice][modelChoice], prices[brandChoice][modelChoice]);
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
                printf("Total price: %.2f\n", prices[brandChoice][modelChoice] + additionalItemsPrice);
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
