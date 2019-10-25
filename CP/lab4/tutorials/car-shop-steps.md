
```c
#include <stdio.h>

int main() {
    printf("Welcome to our car shop.\n");


    // Input personal data
    char firstName[20];
    char lastName[20];
    int phoneNumber[10];
    printf("Please input your data\n");
    printf("First name: ");
    gets(firstName);
    printf("Last name: ");
    gets(lastName);
    
    //test name
    printf("%s %s", firstName, lastName);

    return 0;
}
```

```c
// Input personal data
char firstName[20];
char lastName[20];
char phoneNumber[10];
char address[30];
printf("Please input your data\n");
printf("---First name:\n");
gets(firstName);
printf("---Last name:\n");
gets(lastName);
printf("---Phone number\n");
gets(phoneNumber);
printf("---Address\n");
gets(address);
```

```c
// Choose the brand
int carBrandIndex;
char brand[10];
char brands[][10] = {"Audi","BMW","Bentley"};
printf("Please choose the car brand\n");
for(int i=0;i<3;i++) {
    putchar('a'+i);
    printf(") %s\n",brands[i]);
}
char choice = getchar();
int brandChoice = choice - 'a';
printf("Chosen car is %s\n",brands[brandChoice]);
```

```c
// Choose the car model
printf("Please choose the car model for brand %s\n",brands[brandChoice]);
switch(brandChoice) {
    // Audi
    case 0: {
        char models[][10] = {"Audi A7", "Audi A8", "Audi Q2"};
        double prices[] = {50000, 60000, 70000};
        for(int i=0;i<3;i++) {
            putchar('a'+i);
            printf(") %s (%.2f)\n",models[i],prices[i]);
        }
        // consume new line
        getchar();
        choice = getchar();
        int modelChoice = choice - 'a';
        printf("Model chosen: %s", models[modelChoice]);
        break;
    }
    case 1: {
        printf("No models\n");
        break;
    }
    case 2: {
        printf("No models\n");
        break;
    }
}
```
