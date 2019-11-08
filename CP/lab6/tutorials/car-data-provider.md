
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

# Funcrtion for reading model
```c
void readModel(char * model) {
    char c = getchar();
    int i=0;
    while(c!=',') {
        model[i] = c;
        c = getchar();
        i++;
    }
    model[i] = '\0';
}
```

# Read models and prices

# Display data
```c
for(int i=0;i<noOfBrands;i++) {
    // display brand
    printf("%s: ", brands[i]);
    for(int j=0;j<noOfModels[i];j++) {
        printf("(%s, %.2lf) ",models[i][j],prices[i][j]);
    }
    printf("\n");
}
```

