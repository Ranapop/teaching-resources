# Extracting functions

## Extracting inputPersonalData

![1_extract_input_personal_info.png](images/refactoring-car-shop/1_extract_input_personal_info.png)

This is the function implementation. The data that we want to read is sent as parameters. 

```c
void inputPersonalData(char firstName, char lastName[], char phoneNumber[], char address[]) {
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
}
```

We will call this function in our switch statement:

![2_call_input_personal_data.png](images/refactoring-car-shop/2_call_input_personal_data.png)

If we define `inputPersonalData` bellow our main, we need to declare it above the main function, so we can use it inside the main function:
This is the declaration:
```c
void inputPersonalData(char firstName, char lastName[], char phoneNumber[], char address[]);
```

And we will place it here:


![3_input_data_declaration.png](images/refactoring-car-shop/3_input_data_declaration.png)

## Extracting chooseCarBrand

We can next extract reading the car brand:

![4_extract_car_brand](images/refactoring-car-shop/4_extract_car_brand.png)

```c
char chooseCarBrand(int noOfBrands, char brands[][10]){
    // Choose the brand
    printf("Please choose the car brand\n");
    for(int i=0;i<noOfBrands;i++) {
        putchar('a'+i);
        printf(") %s\n",brands[i]);
    }
    printf("%c) Go back\n",'a'+noOfBrands);
    char choice = getchar();
    // consume new line
    getchar();
    return choice;
}
```

![5_call_choose_car_brand](images/refactoring-car-shop/5_call_choose_car_brand.png)

We define it below the other function, thus having:
```c
#include <stdio.h>

void inputPersonalData(char firstName, char lastName[], char phoneNumber[], char address[]);
char chooseCarBrand(int noOfBrands, char brands[][10]);
```

## Defining some constants

We can see that we had to pass `10` as max size of brand name in this function. And we also did it when defining the brands array of string in the main function. It's hard to keep track like that. And if we wanted to say the brand names should be as much as 20 characters, we would have to change that in a few places. So let's define the max brand name length as a constant:
```c
#define MAX_BRAND_NAME 10
```
Let's use it in the function header:
```c
char chooseCarBrand(int noOfBrands, char brands[][MAX_BRAND_NAME]);
...
char chooseCarBrand(int noOfBrands, char brands[][MAX_BRAND_NAME])
```
And in the declaration of brands in main:
```c

char brands[][MAX_BRAND_NAME] = {"Audi","BMW","Bentley"};
```

## Extracting chooseCarModel

![6_extract_car_model](images/refactoring-car-shop/6_extract_car_model.png)






