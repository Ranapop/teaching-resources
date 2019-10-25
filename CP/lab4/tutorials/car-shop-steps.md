# Desired flow:
```
Welcome to our car shop. Press 'q' to exit.
Please input your data.
---First Name
>Ana
---Last Name
>Pop
---Phone number
>074c3210dd
!Your phone number must contain only numbers
---Phone number
>0744321022
---Address
Str. Luna nr 21

Please choose the car brand
a) Audi
b) BMW
c) Bentley
->a

Please choose the model for brand Audi
a) Audi A7(50000)
a) Audi A8(60000)
a) Audi Q2(70000)
d) Go back
->a

Choose additional items (separated by comma)
a) Winter tires (200)
b) Roof box (400)
c) Wireless charger (50)
d) Go back
->a,c

Your contract is:
-------------
Customer data:
-name: Ana Pop
-phone number: 0744321022
-address: Str. Luna nr 21
Car data:
-car model: Audi A7 (50000)
-additional items (250)
--winter tires (200)
--wireless charger (50)
Total price: 50250
-------------
a) Sign
b) Go back
```

# Reading the name

![1_name.png](images/car-shop/1_name.png)

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

# Reading personal data (no validation)

![2_personal_data.png](images/car-shop/2_personal_data.png)

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

# Choose car brand

![3_chosen_car.png](images/car-shop/3_chosen_car.png)

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

# Choose car model

![4_choose_audi_model.png](images/car-shop/4_choose_audi_model.png)

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
