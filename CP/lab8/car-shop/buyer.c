//
// Created by roxanappop on 11/1/2019.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define VALIDATE_LEN_MESSAGE "!!!The phone number should contain exactly 10 digits! Please input it again!\n"
#define VALIDATE_DIGITS_MESSAGE "!!!The phone number should contain only digits!\n"


void readPhoneNumber(char phoneNumber[]);
int containsOnlyDigits(char s[]);
int isLength(char s[]);
int validate(int (*fullfillsCondition)(char []), char phoneNumber[], char message[]);

void inputPersonalData(char firstName[], char lastName[], char phoneNumber[], char address[]) {
    // Input personal data
    printf("Please input your data\n");
    printf("---First name:\n");
    gets(firstName);
    printf("---Last name:\n");
    gets(lastName);
    readPhoneNumber(phoneNumber);
    printf("---Address\n");
    gets(address);
}

void displayPersonalData(char firstName[], char lastName[], char phoneNumber[], char address[]) {
    printf("Customer data:\n");
    printf("-name: %s %s\n", firstName, lastName);
    printf("-phone number: %s\n", phoneNumber);
    printf("-address: %s\n", address);
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