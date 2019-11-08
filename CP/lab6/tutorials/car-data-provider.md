
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

# Function for reading model
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
```c
int * noOfModels = (int*)malloc(noOfBrands * sizeof(int));
char *** models = (char***)malloc(noOfBrands * sizeof(char**));
double ** prices = (double**)malloc(noOfBrands* sizeof(double*));
for(int i=0; i<noOfBrands; i++) {
    // read no of models
    printf("Please input no of models for brand %s\n",brands[i]);
    scanf("%d",&noOfModels[i]);
    getchar();

    //read models & prices
    models[i] = (char**)malloc(noOfModels[i]* sizeof(char*));
    prices[i] = (double*)malloc(noOfModels[i]* sizeof(double));

    printf("Please input models&prices: each line model,price\n");
    for(int j=0;j<noOfModels[i];j++){
        models[i][j] = (char*)malloc(MAX_MODEL_NAME* sizeof(char));
        readModel(models[i][j]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &prices[i][j]);
    }
}
```

# Display data
```c
printf("The data is:\n");
for(int i=0;i<noOfBrands;i++) {
    // display brand
    printf("%s: ", brands[i]);
    for(int j=0;j<noOfModels[i];j++) {
        printf("(%s, %.2lf) ",models[i][j],prices[i][j]);
    }
    printf("\n");
}
```

# Free memory

```c
for(int i=0;i<noOfBrands;i++) {
    for(int j=0;j<noOfModels;j++) {
        free(models[i][j]);
    }
    free(models[i]);
    free(prices[i]);
    free(brands[i]);
}
free(models);
free(prices);
free(brands);
free(noOfModels);
```

# Recap
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_BRAND_NAME 10
#define MAX_MODEL_NAME 20
#define MAX_LINE 10
void readModel(char * model);

int main() {

    //read no of brands
    int noOfBrands;
    printf("Please input number of brands\n");
    scanf("%d",&noOfBrands);

    //read brands
    char ** brands;
    brands = (char**)malloc(noOfBrands* sizeof(char*));
    for(int i=0;i<noOfBrands;i++) {
        // read each brand
        brands[i] = (char*)malloc(MAX_BRAND_NAME* sizeof(char));
        scanf("%s",brands[i]);
    }

    // testing purpose; todo: delete at next step
    for(int i=0;i<noOfBrands;i++){
        printf("Brand %s\n",brands[i]);
    }

    int * noOfModels = (int*)malloc(noOfBrands * sizeof(int));
    char *** models = (char***)malloc(noOfBrands * sizeof(char**));
    double ** prices = (double**)malloc(noOfBrands* sizeof(double*));
    for(int i=0; i<noOfBrands; i++) {
        // read no of models
        printf("Please input no of models for brand %s\n",brands[i]);
        scanf("%d",&noOfModels[i]);
        getchar();

        //read models & prices
        models[i] = (char**)malloc(noOfModels[i]* sizeof(char*));
        prices[i] = (double*)malloc(noOfModels[i]* sizeof(double));

        printf("Please input models&prices: each line model,price\n");
        for(int j=0;j<noOfModels[i];j++){
            models[i][j] = (char*)malloc(MAX_MODEL_NAME* sizeof(char));
            readModel(models[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &prices[i][j]);
        }
    }

    // display data
    printf("The data is:\n");
    for(int i=0;i<noOfBrands;i++) {
        // display brand
        printf("%s: ", brands[i]);
        for(int j=0;j<noOfModels[i];j++) {
            printf("(%s, %.2lf) ",models[i][j],prices[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i=0;i<noOfBrands;i++) {
        for(int j=0;j<noOfModels;j++) {
            free(models[i][j]);
        }
        free(models[i]);
        free(prices[i]);
        free(brands[i]);
    }
    free(models);
    free(prices);
    free(brands);
    free(noOfModels);

    return 0;
}

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
