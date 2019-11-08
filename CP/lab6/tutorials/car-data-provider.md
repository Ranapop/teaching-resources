
# Read number of brands

```c
int noOfBrands;
printf("Please input the number of brands\n");
scanf("%d",&noOfBrands);
```

# Read brands

```c
printf("Please input brands (separated by space)\n");
char ** brands; // char brands[][]
brands = (char**)malloc(noOfBrands* sizeof(char*));
for(int i=0;i<noOfBrands;i++) {
    // read brand
    brands[i] = (char*)malloc(MAX_BRAND_NAME* sizeof(char));
    scanf("%s",brands[i]);
}

// testing purpose; todo: delete at next step
for(int i=0;i<noOfBrands;i++){
    printf("Brand %s\n",brands[i]);
}
```
