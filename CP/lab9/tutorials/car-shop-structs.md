
# Overview

In this tutorial we will be defining structures for our entities in the `car-shop` application. We could identify:
* buyer (first name, last name, phone number, address)
* model (name, price, brandName)
* additional item (name, price)
* contract (customer, model, additional items)

# Buyer

Start by defining a structur for the buyer in `buyer.h`:
```c
typedef struct _buyer {
    char * firstName;
    char * lastName;
    char * phoneNumber;
    char * address;
} buyer;
```

