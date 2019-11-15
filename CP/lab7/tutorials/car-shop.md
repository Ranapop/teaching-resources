
# Validate phone number 

## Validate that it contains exactly 10 digits

```c
void readPhoneNumber(char phoneNumber[]) {
    printf("---Phone number\n");
    int isValid =0;
    while(!isValid) {
        gets(phoneNumber);
        int len = strlen(phoneNumber);
        if(len==PHONE_NUMBER_LEN) {
            isValid = 1;
        } else {
            printf("!!!The phone number should contain exactly %d digits! Please input it again!\n",PHONE_NUMBER_LEN);
        }
    }
}
```

## Validate that it contains only digits

Create a function that verifies a string only contains digits:

```c
int containsOnlyDigits(char s[]) {
    for(int i=0;i<strlen(s);i++) {
        if(!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}
```

Modify our `readPhoneNumber` function:

```c
void readPhoneNumber(char phoneNumber[]) {
    printf("---Phone number\n");
    int isValid =0;
    while(!isValid) {
        gets(phoneNumber);
        int len = strlen(phoneNumber);
        if(len==PHONE_NUMBER_LEN) {
            isValid = 1;
            // verify if the number contains only digits
            if(!containsOnlyDigits(phoneNumber)) {
                isValid = 0;
                printf("!!!The phone number should contain only digits!\n");
            }
        } else {
            printf("!!!The phone number should contain exactly %d digits! Please input it again!\n",PHONE_NUMBER_LEN);
        }

    }
}
```

## Refactor

```c
int validateLength(char phoneNumber[]) {
    if(strlen(phoneNumber) == 10) {
        return 1;
    } else {
        printf("!!!The phone number should contain exactly 10 digits! Please input it again!\n");
        return 0;
    }
}

int validateDigits(char phoneNumber[]) {
    if (containsOnlyDigits(phoneNumber)) {
        return 1;
    } else {
        printf("!!!The phone number should contain only digits!\n");
    }
    return 0;
}
```

and call them:

```c
isOk = validateLength(phoneNumber) && validateDigits(phoneNumber);
```

Using function pointers:
```c
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
```

and call them:

```c
isOk = validate(&isLength, phoneNumber, VALIDATE_LEN_MESSAGE) && validate(&containsOnlyDigits,phoneNumber, VALIDATE_DIGITS_MESSAGE);
```

# Validate email address

```c
int endsWith(char s[], char substr[]) {
    char * ret = strstr(s,substr);
    if(ret == NULL) {
        return 0;
    }
    return strlen(ret) == strlen(substr);
}
```

```c
void readEmailAddress(char address[]) {

    printf("---Email address\n");
    int isValid = 0;
    while(!isValid) {
        gets(address);
        // verify the address ends in @yahoo.com or @gmail.com
        if (endsWith(address,"@yahoo.com") || endsWith(address,"@gmail.com")) {
            isValid = 1;
        } else {
            printf("!!!Invalid email address\n");
        }
    }
}
```
