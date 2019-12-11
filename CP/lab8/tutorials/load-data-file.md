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
  }```

# Modifying the input functions to read from a file

# Closing the file

# Refactor
