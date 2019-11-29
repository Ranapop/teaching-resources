
Data:

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


void readModels() {
    char line[MAX_LINE];
    gets(line);
    char * token = strtok(line, "(");
    // while token!=null
    while (token!=NULL) {
        // read model name (until - )
        token = strtok(NULL, "-");
        // read price (until ")" )
        token = strtok(NULL, ")");
        // read space until "("
        token = strtok(NULL, "(");
    }
}
```
