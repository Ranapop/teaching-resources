In this tutorial you will add the functionality of loading car data in the `car-shop` application from the console. The flow will be:
* the data is loaded from the console
* the user can buy the car (the options are those loaded from the console)

The input format for loading is as follows:
* on the first line the number of brands (noOfBrands)
* the following next 2* _noOFBrands_ lines:
** <brand>:<noOfModels>
** (<model_1> <price_1>) (<model_2> <price_2>)    (<model_noOfModels> <price_noOfModels>)

```
2
audi:2
(audi a3-120) (audi a5-122) 
dacia:1
(dacia logan-1)
3
(blinds-1) (tires-2) (spray-3)
```

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
