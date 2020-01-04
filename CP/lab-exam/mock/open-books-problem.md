# Open books problem

## Input

You will have to do some processing on students-related data.

A student has:
* a first name
* a last name
* a grade

You will have a file called `students.txt` which contains:
* on the first line _n_ numbers
* on the second line _n_ words representing the students' first names
* on the third line _n_ words representing the students' last names
* on the fourth line _n_ numbers representing the students' grades

Example input:
```
5
Marian Ana Vlad Ana Marian
Bucur Pop Cira Popescu Bucur
7.3 8 9.85 9.75 8
```

You have to define a structure to hold a student's data and load the data in the file in an array of structure. Each element in the array may be a structure or a pointer to a strucutre, it's up to you to choose.

## Processing tasks

### Task1: Order the students

You have to oder the students by the following rules:
* if possible, order them by their first name 
* if their first names are equals (in the example with "Ana"), order them by their last name (in the example "Pop" and "Popescu")
* if their first names and last names are equal, order them by their grades (in the example "Marian Bucur"). The students with the bigger grades should come first
* if all fields are equal, they can be placed in any order

You have to write in the output file the string "Task1:" followed by _n_ lines with the ordered students.

Example output:
```
Task1:
Ana Pop - 8.00
Ana Popescu - 9.75
Marian Bucur - 8.00
Marian Bucur - 7.30
Vlad Cira - 9.85
```

You can use `strcmp` for comparing strings. You should at least have a function that takes two students and give their order. You can extract more functions than that, and they should help you keep the implementation simple and readable. You may use any sorting algorithm, do not try to go for something more efficient and more difficult to implement. You can order directly on the array of structures or you can order the students indexes in the array of structures, and make sure you print them in the correct order.

NOTE: You will receive points even if you just print them in the file, without ordering them. This is also the most complex task so it's ok if you initially just print them in the file, then come back to change the implementation once you're done with the other tasks.

### Task2: Find average grade

Your task is to find the average grade and print it in the output file.

Example output:
```
Task2:
Average grade is 8.51
```

### Task3: Find the best student

You should find the student with the maximum rgrade and print its name (first+last) in the file.

Example output:
```
Task3:
Best student is Vlad Cira
```

## Output

You should print in `output.txt` the output from the 3 tasks, separated by empty lines.

Example output:
```
Task1:
Ana Pop - 8.00
Ana Popescu - 9.75
Marian Bucur - 8.00
Marian Bucur - 7.30
Vlad Cira - 9.85

Task2:
Average grade is 8.51

Task3:
Best student is Vlad Cira
```
## Grading

| Requirement                           | Points |
| ------------------------------------- | ------ |
| Open & close files                    | 1 p    |
| Allocate & free memory                | 2 p    |
| Read input                            | 1 p    |
| Print students in the file            | 0.5 p  |
| Write function for comparing students | 0.5 p  |
| Order students                        | 1 p    |
| Task2                                 | 1 p    |
| Task3                                 | 1 p    |
| Separate source files (note1)         | 1 p    |
| Code quality (note2)                  | 1 p    |
| ex-officio                            | 1 p    |

Notes:
* note1: you should have at least `main.c`, `student.c`, and `student.h`
* note2: you should
  * not use local paths for files (please use "../students.txt" and "../output.txt")
  * define constants
  * extract functions
  * name variables, constants and functions properly
