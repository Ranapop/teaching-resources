
# Overview

In this tutorial we will be defining structures for our entities in the `car-shop` application. We could identify:
* buyer (first name, last name, phone number, address)
* model (name, price, brandName)
* additional item (name, price)
* contract (customer, model, additional items)

# Buyer

Start by defining a structure for the buyer in `buyer.h`:
```c
typedef struct _buyer {
    char * firstName;
    char * lastName;
    char * phoneNumber;
    char * address;
} buyer;
```

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

In main.c, we can use this function now to create a new buyer (put it with the other declarations, for ex after chosenAdditionalItems:
```c
buyer b = createBuyer();
```

