//
// Created by roxanappop on 10/31/2019.
//

#ifndef CAR_SHOP_BUYER_H
#define CAR_SHOP_BUYER_H

typedef struct _buyer {
    char * firstName;
    char * lastName;
    char * phoneNumber;
    char * address;
} buyer;

//function prototypes

buyer createBuyer();
void inputPersonalData(buyer * b);
void displayPersonalData(buyer * b);

#endif //CAR_SHOP_BUYER_H
