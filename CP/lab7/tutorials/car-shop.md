
# Validate phone number using strlen

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
