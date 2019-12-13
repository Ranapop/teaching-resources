//
// Created by roxanappop on 11/1/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "buyer.h"

#define VALIDATE_LEN_MESSAGE "!!!The phone number should contain exactly 10 digits! Please input it again!\n"
#define VALIDATE_DIGITS_MESSAGE "!!!The phone number should contain only digits!\n"

#define MAX_BUYER_NAME 20
#define  MAX_PHONE_NUMBER 10
#define MAX_ADDRESS 30

void readPhoneNumber(char phoneNumber[]);
int containsOnlyDigits(char s[]);
int isLength(char s[]);
int validate(int (*fullfillsCondition)(char []), char phoneNumber[], char message[]);

buyer createBuyer(){
    buyer b;
    b.firstName = (char*)malloc(MAX_BUYER_NAME* sizeof(char));
    b.lastName = (char*)malloc(MAX_BUYER_NAME* sizeof(char));
    b.phoneNumber = (char*)malloc(MAX_PHONE_NUMBER* sizeof(char));
    b.address = (char*)malloc(MAX_ADDRESS* sizeof(char));
    return b;
}

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

void readPhoneNumber(char phoneNumber[]) {
    printf("---Phone number\n");
    int isOk = 0;
    while (!isOk) {
        gets(phoneNumber);
        isOk = validate(&isLength, phoneNumber, VALIDATE_LEN_MESSAGE)
                && validate(&containsOnlyDigits, phoneNumber, VALIDATE_DIGITS_MESSAGE);
    }
}

int containsOnlyDigits(char s[]) {
    for(int i=0;i<strlen(s);i++) {
        if(!isdigit(s[i]))
            return 0;
    }
    return 1;
}

int isLength(char s[]) {
    return strlen(s) == 10;
}

int validate(int (*fullfillsCondition)(char []), char phoneNumber[], char message[]) {
    if (fullfillsCondition(phoneNumber)) {
        return 1;
    } else {
        printf(message);
    }
    return 0;
}