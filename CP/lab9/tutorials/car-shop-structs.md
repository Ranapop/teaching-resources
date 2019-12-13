
# Overview

In this tutorial we will be defining structures for our entities in the `car-shop` application. We could identify:
* buyer (first name, last name, phone number, address)
* model (name, price, brandName)
* additional item (name, price)
* contract (customer, model, additional items)

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
                
