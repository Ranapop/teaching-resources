# Overview
In this tutorial you will add the functionality of loading car data in the `car-shop` application from the console. The flow will be:
* the data is loaded from the console
* the user can buy the car (the options are those loaded from the console)


The input format for loading is as follows:
* on the first line the number of brands (noOfBrands)
* the following next 2* _noOFBrands_ lines:
    * \<brand\>:\<noOfModels\>
    * (<model_1>-<price_1>) (<model_2>-<price_2>)    (<model_noOfModels>-<price_noOfModels>)

Data example:
```
2
audi:2
(audi a3-120) (audi a5-122) 
dacia:1
(dacia logan-1)
3
(blinds-1) (tires-2) (spray-3)
```

# Parsing the input

Add two function definitions in the upper part of the `main.c` file (with the other function definitions) for parsing the brands line and for parsing the models line:
* `void readBrand(char brandName[], int * noOfModels)`
* `void readModels(double * prices, char ** models)`

## Read brand

First, let's write a function for parsing the `<brand>:<noOfModels>` line. We will use `strtok` for dividing the string using the `:` delimiter. We will copy the first token to `brandName` and transform the second token to an int using `atoi` and put it in the `noOfModels`.

```c
// read brand name and no of models
void readBrand(char brandName[], int * noOfModels) {
    char line[MAX_LINE];
    gets(line);
    const char delim[2] = ":";
    char * token;
    //brand name
    token = strtok(line, delim);
    strcpy(brandName,token);
    //noOfModels
    token = strtok(NULL,delim);
    *noOfModels = atoi(token);
}
```
## Read models

We will use `strtok` for parsing the model names as well. We want to parse a string of the form: `(<model_1>-<price_1>) (<model_2>-<price_2>)    (<model_noOfModels>-<price_noOfModels>)` and extract the `model_1` and `model_2` etc. and `price_1` and `price_2` etc.. To do this, we 

```c
void appendCharAtBeginning(char * str, char c) {
    // +1 to include string terminator
    int len = strlen(str)+1;
    memmove(str+1,str,len);
    str[0] = ' ';
}

void readModels(double * prices, char ** models) {
    char line[MAX_LINE];
    gets(line);
    appendCharAtBeginning(line,' ');
    char * token = strtok(line, "(");
    // while token!=null
    int k=0;
    while (token!=NULL) {
        // read model name (until - )
        token = strtok(NULL, "-");
        strcpy(models[k],token);
        // read price (until ")" )
        token = strtok(NULL, ")");
        sscanf(token,"%lf",&prices[k]);
        k++;
        // read space until "("
        token = strtok(NULL, "(");
    }
}
```

In main() - at the begining:
```c
// load data
// read no of brands
int noOfBrands = 3;
scanf("%d",&noOfBrands);
getchar();
// read model with no of models
char testName[20];
int testNo;
readBrand(testName,&testNo);
readModels();
```
