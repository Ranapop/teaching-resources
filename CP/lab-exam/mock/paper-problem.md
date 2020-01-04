Your task is to count the number of vowels in each word, doing so with a  recursive solution. You should implement and use a function with the following header:
```c
int countVowels(char * word);
```
An iterative solution will be accepted, but for a smaller grade.

## Output
You have to write in `output.txt` a sequence of numbers representing the vowel counts.

Output example:
```
2 2 2
```

## Assumptions

You may assume the words are up to 20 characters each.
You may not assume the file `input.txt` exists, and your program should exit immediately if the file does not exist or cannot be opened.

## Grading 

| Requirement                           | Points |
| ------------------------------------- | ------ |
| Open the files                        | 1 p    |
| Close the files                       | 0.5 p  |
| Allocate memory                       | 2 p    |
| Free memory                           | 1 p    |
| Implement function                    | 1 p    |
| Recursive solution                    | 1 p    |
| Define constants                      | 0.5 p  |
| Implement function                    | 1 p    |
| Proper variables and functions naming | 1 p    |
| ex-officio                            | 1 p    |

Notes:
* you should check if the files opened successfully (if not, error message & exit)
* you should check if the memory was allocated successfully (if not, error message & exit)
