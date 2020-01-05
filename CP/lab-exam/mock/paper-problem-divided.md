Note: ex-officio 1p
Maximum grade: 11p

# 1) Read an array of words from a file (2.5p)

You have to implement a function with the following header:
```c
char ** readWords(FILE * f, int * n);
```

The function receives an opened file `f`. You may assume the file was opened successfully. The contents of the file are of the form:
```
<n>
<word_1> <word_2> ... <word_n>
```
Example:
```
4
ana are o floare
```

The function should:
* return through _n_ the number of words
* return an array of strings containing the words (should be allocated in the function)

You can assume you have a constant `MAX_WORD_LEN` defined which represents the maximum length of a word.

Your answer:
```c
char ** readWords(FILE * f, int * n) {
    
    
    
    
    
       
        
   
    
}
```

# 2) Free memory (1p)

You should write a function that frees the memory of an array of strings. It should have the following header:
```c
void freeMemory(char ** words, int n);
```

Your answer:
```c
void freeMemory(char ** words, int n) {
    
       
    
    

}
```

# 3) Count vowels iteratively (1.5p)

You have to write a function for counting the number of vowels in a word. You may assume you have a function that tells you if a given character is a vowel or not:
```c
int isVowel(char c)
```
You have to implement:
```c
int countVowels(char * word);
```
You can use functions from `string.h`.

Your answer:
```c
int countVowels(char * str) {
    
    
    
    
    
    
    
    
}
```

# 3) Count vowels recursively (1p)

You have to implement again countVowels, but with a recursive solution:
```c
int countVowels(char * word);
```

You may assume (again) you have `isVowel` implemented. You can use auxilary functions.

Your answer:
```











````

# 4) Count vowels of words in a file (4p)

## Input

You are given as input a file `input.txt` with the following content (same as exercise 1):
* on the first line a number _n_
* on the second line _n_ words
You may assume you have the file name defined in the constant `INPUT_FILE_NAME`.

## Task

Your task is to count the number of vowels in each word, and write that number in the console.

Input (input.txt):
```
4
ana are o floare
```
Output (console):
```
2 2 1 3
```

You:
* can use any of the functions defined at previous exercises (even if you didn't do the implementation)
* should check the file can be opened successfully
* if the file cannot be opened successfully
  * write an error message with `perror`
  * exit the program with exit and exit code EXIT_FAILURE
* should close the input file
* should free the memory

You only have to implement the main function:
```c
int main() {
















}
```
## Grading
* opening file: 1.5
* main flow (read, process, output): 2
* cleaning up (free memory, close file): 0.5
