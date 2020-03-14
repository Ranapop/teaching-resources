# Overview

* You will have to do some processing on actors-related data.
* You should use the lab-exam repo you received. 
* You can use one source file only if you want (main.c).
* You have 1h
* ex officio: 2p

You can take the structure of a movie and put it in your project:

```c
typedef struct _actor {
    int age;
    int noMovies;
    char * name;
    char * award;
} actor;
```

# Data

You are provided with a function that gives you dummy data. You should work on this data for tasks 1-4.

```c
actor * getDummyActors(int * n) {
    *n = 4;
    actor * actors = (actor*)malloc(4* sizeof(actor));

    actors[0].age=14;
    actors[0].noMovies = 1;
    actors[0].name = "Anna";
    actors[0].award = "some award";

    actors[1].age=16;
    actors[1].noMovies = 3;
    actors[1].name = "Elsa";
    actors[1].award = "some other award";

    actors[2].age=30;
    actors[2].noMovies = 7;
    actors[2].name = "Michael";
    actors[2].award = "award with long name";

    actors[3].age=35;
    actors[3].noMovies = 5;
    actors[3].name = "Christopher";
    actors[3].award = "award with long name";

    return actors;
}
```

# Task 1) Print the actors in a file (1p)

You should print in `../out.txt` the movies in the format:

```c
"Actor %s of age %d was in %d movies and won \"%s\"\n"
```

Print for this task:
* "Task1"
* each actor on a new line

Output:
```
Task1:
Actor Anna of age 14 was in 1 movies and won "some award"
Actor Elsa of age 16 was in 3 movies and won "some other award"
Actor Michael of age 30 was in 7 movies and won "award with long name"
Actor Christopher of age 35 was in 5 movies and won "award with long name"
```

# Task 2) Print award with longest name (1p)

Print in the file which award has the longest name. You may use functions from `string.h`.

Use the format:
```c
"The longest award is \"%s\""
```

Output file: 
```
Task2:
The longest award is "award with long name"
```

# Task 3) Print actors who got the award from task 2 (1p)

Print the actors' names who got the award with the longest name. 

In the dummy data, there are 2 actors who won the award "award with long name" that should be printed.

Output file:
```
Task3:
The actors who got the award "award with long name" are:
Michael
Christopher
```

# Task 4) Print youngest actor who played in more then \<nr> movies (2p)

Read from the __console__ a number of movies, then print in the __output__ file the youngest actor (with the smallest age) which has __at least__ that many movies.

For example, if the number is 2, there are 3 actors which played in at least 3 movies: Elsa, Michael and Christopher. The youngest of them is Elsa.

You should promt the user (console) with this message:
```c
"Please input the minimum number of movies\n"
```

Console:
```
Please input the minimum number of movies
>2
```

Output file:
```
Task4:
Youngest actor who played in at least 2 movies is Elsa
```

You can consider the max age is 150
```c
#define MAX_AGE 150
```

# Output file after tasks 1-4
```
Task1:
Actor Anna of age 14 was in 1 movies and won "some award"
Actor Elsa of age 16 was in 3 movies and won "some other award"
Actor Michael of age 30 was in 7 movies and won "award with long name"
Actor Christopher of age 35 was in 5 movies and won "award with long name"

Task2:
The longest award is "award with long name"

Task3:
The actors who got the award "award with long name" are:
Michael
Christopher

Task4:
Youngest actor who played in at least 2 movies is Elsa
```

# Task 5) Read actors (2p)

You should read an array of actors from the file "../in.txt" and output them to the console. You do not have to redo task1-4 with this data! You can leave those with the dummy data.

File format:
* first line: n - number of actors
* second line: age (n numbers)
* third line: numbers of movies (n numbers)
* fourth line: names (n words, can consider each name does not contain spaces)
* fifth line: awards (n words, can consider each award does not contain spaces)

You should dynamically allocate the array. You can consider the strings are <20 chars.

```c
#define MAX_NAME 20
#define MAX_AWARD 20
```

Example
```
3
20 17 33
2 3 5
actor1 actor2 actor3
award1 award2 award3
```

You should write in the __console__:
* message "Read actors are:" 
* on each subsequent line the actors in the format Actor (\<age>,\<noMovies>,\<name>,\<award>)

Console:
```
Read actors are:
Actor (20,2,actor1,award1)
Actor (17,3,actor2,award2)
Actor (33,5,actor3,award3)
```

# Task 6) Push the code (1p)

Please push the code in the provided repo. No need for multiple branches (&pull req).

# Notes

Please:
* close files and free memory

You may be penalized for code quality!
