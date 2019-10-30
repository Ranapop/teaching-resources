# Extracting functions

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

