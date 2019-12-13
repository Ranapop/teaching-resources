# Overview

This tutorial works upon the `load-data-console` tutorial. We want to load the data from a file `data.txt` which resides at the same level as `main.c`.

# Opening the file

We open the file at FILE_PATH. If the fopen function is not successfull it returns NULL. We will check for that, and in case the file is not open successfully, we terminate the program.
The FILE_PATH is a constant holding `"../data.txt"`.

```c
FILE * carDataFile;
carDataFile = fopen(FILE_PATH, "r");
if(carDataFile==NULL) {
    perror("File could not be open");
    exit(-1);
}
```

# Modifying the input functions to read from a file

We modify `scanf -> fscanf` and `getchar -> fgetc` in the snippet bellow:

```c
// load data
// read no of brands
int noOfBrands;
fscanf(carDataFile, "%d", &noOfBrands);
fgetc(carDataFile);
char **brands = (char **) malloc(noOfBrands * sizeof(char *));
int *noOfModels = (int *) malloc(noOfBrands * sizeof(int));
char ***models = (char ***) malloc(noOfBrands * sizeof(char **));
double **prices = (double **) malloc(noOfBrands * sizeof(double *));
for (int i = 0; i < noOfBrands; i++) {
    brands[i] = (char *) malloc(MAX_BRAND_NAME * sizeof(char));
    // read brand & no of models
    readBrand(carDataFile, brands[i], &noOfModels[i]);
    // read models
    models[i] = (char **) malloc(noOfModels[i] * sizeof(char *));
    prices[i] = (double *) malloc(noOfModels[i] * sizeof(double));
    for (int j = 0; j < noOfModels[i]; j++) {
        // read model name & model price
        models[i][j] = (char *) malloc(MAX_MODEL_NAME * sizeof(char));
    }
    readPairs(carDataFile, prices[i], models[i]);
}

//read additional items
int noOfAdditionalItems;
fscanf(carDataFile, "%d", &noOfAdditionalItems);
fgetc(carDataFile);
char **additionalItems = (char **) malloc(noOfBrands * sizeof(char *));
double *additionalItemsPrices = (double *) malloc(noOfBrands * sizeof(double));
fscanf(carDataFile, "%d", &noOfAdditionalItems);
for (int i = 0; i < noOfAdditionalItems; i++) {
    additionalItems[i] = (char *) malloc(MAX_ADDITIONAL_ITEM_NAME * sizeof(char));
}
readPairs(carDataFile, additionalItemsPrices, additionalItems);
```

And we will modify our two reading functions. Please be aware that `fgets` does not replace `\n` with `\0` so we will do that manually:

```c
// read brand name and no of models
void readBrand(FILE *f, char *brandName, int *noOfModels) {
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line)-1]='\0';
    const char delim[2] = ":";
    char *token;
    //brand name
    token = strtok(line, delim);
    strcpy(brandName, token);
    //noOfModels
    token = strtok(NULL, delim);
    *noOfModels = atoi(token);
}

void readPairs(FILE *f, double *prices, char **names) {
    char line[MAX_LINE];
    fgets(line, MAX_LINE, f);
    line[strlen(line)-1]='\0';
    appendCharAtBeginning(line, ' ');
    char *token = strtok(line, "(");
    // while token!=null
    int k = 0;
    while (token != NULL) {
        // read name (until - )
        token = strtok(NULL, "-");
        strcpy(names[k], token);
        // read price (until ")" )
        token = strtok(NULL, ")");
        sscanf(token, "%lf", &prices[k]);
        k++;
        // read space until "("
        token = strtok(NULL, "(");
    }
}
```

# Closing the file

After reading the data, we can close the file:

```c
fclose(carDataFile);
````

# Refactor

We can extract some functions for reading the data (including memory allocation). We will just need to send the addresses of our data structures to be able to do the allocations inside the functions:
```c
void readBrandsWithModels(FILE *carDataFile, int *noOfBrandsAddr, char ***brandsAddr, int **noOfModelsAddr,
                          char ****modelsAddr, double ***pricesAddr) {
    // read no of brands
    int noOfBrands;
    fscanf(carDataFile, "%d", &noOfBrands);
    fgetc(carDataFile);
    char **brands = (char **) malloc(noOfBrands * sizeof(char *));
    int *noOfModels = (int *) malloc(noOfBrands * sizeof(int));
    char ***models = (char ***) malloc(noOfBrands * sizeof(char **));
    double **prices = (double **) malloc(noOfBrands * sizeof(double *));
    for (int i = 0; i < noOfBrands; i++) {
        brands[i] = (char *) malloc(MAX_BRAND_NAME * sizeof(char));
        // read brand & no of models
        readBrand(carDataFile, brands[i], &noOfModels[i]);
        // read models
        models[i] = (char **) malloc(noOfModels[i] * sizeof(char *));
        prices[i] = (double *) malloc(noOfModels[i] * sizeof(double));
        for (int j = 0; j < noOfModels[i]; j++) {
            // read model name & model price
            models[i][j] = (char *) malloc(MAX_MODEL_NAME * sizeof(char));
        }
        readPairs(carDataFile, prices[i], models[i]);
    }
    *noOfBrandsAddr = noOfBrands;
    *brandsAddr = brands;
    *noOfModelsAddr = noOfModels;
    *modelsAddr = models;
    *pricesAddr = prices;
}

void readAdditionalItems(FILE *carDataFile, int *noOfAdditionalItemsAddr, char ***additionalItemsAddr,
                         double **additionalItemsPricesAddr) {
    //read additional items
    int noOfAdditionalItems;
    fscanf(carDataFile, "%d", &noOfAdditionalItems);
    fgetc(carDataFile);
    char **additionalItems = (char **) malloc(noOfAdditionalItems * sizeof(char *));
    double *additionalItemsPrices = (double *) malloc(noOfAdditionalItems * sizeof(double));
    fscanf(carDataFile, "%d", &noOfAdditionalItems);
    for (int i = 0; i < noOfAdditionalItems; i++) {
        additionalItems[i] = (char *) malloc(MAX_ADDITIONAL_ITEM_NAME * sizeof(char));
    }
    readPairs(carDataFile, additionalItemsPrices, additionalItems);
    *noOfAdditionalItemsAddr = noOfAdditionalItems;
    *additionalItemsAddr = additionalItems;
    *additionalItemsPricesAddr = additionalItemsPrices;
}

void readData(FILE *carDataFile, int *noOfBrandsAddr, char ***brandsAddr, int **noOfModelsAddr,
              char ****modelsAddr, double ***pricesAddr,
              int *noOfAdditionalItemsAddr, char ***additionalItemsAddr, double **additionalItemsPricesAddr) {
    readBrandsWithModels(carDataFile, noOfBrandsAddr, brandsAddr, noOfModelsAddr, modelsAddr, pricesAddr);
    readAdditionalItems(carDataFile, noOfAdditionalItemsAddr, additionalItemsAddr, additionalItemsPricesAddr);
}
```

We can also create a function for freeing the memory:
```c
void freeData(int noOfBrands, char **brands, int *noOfModels,
              char ***models, double **prices,
              int noOfAdditionalItems, char **additionalItems, double *additionalItemsPrices) {

    for (int i = 0; i < noOfBrands; i++) {
        for (int j = 0; j < noOfModels[i]; j++) {
            free(models[i][j]);
        }
        free(brands[i]);
        free(models[i]);
        free(prices[i]);
    }
    free(brands);
    free(noOfModels);
    free(models);
    free(prices);
    for (int i = 0; i < noOfAdditionalItems; i++) {
        free(additionalItems[i]);
    }
    free(additionalItems);
    free(additionalItemsPrices);
}
```

More could be extracted but we will leave it like this for now. The final result can be found in the `car-shop` folder of this laboratory.
