
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
    printf("Phone number: ");
    //test name
    printf("%s %s", firstName, lastName);

    return 0;
}
```
