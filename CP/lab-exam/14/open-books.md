# Overview

* You will have to do some processing on movies-related data.
* You should use the lab-exam repo you received. 
* You can use one source file only if you want (main.c).
* You have 1h
* ex officio: 2p

You can take the structure of a movie and put it in your project:

```c
typedef struct _movie {
    int year;
    float imdbRating;
    char * title;
    char * director;
} movie;
```

# Data

You are provided with a function that gives you dummy data. You should work on this data for tasks 1-4.

```c
movie * getDummyMovies(int * n) {
    *n = 5;
    movie * movies = (movie*)malloc(5* sizeof(movie));
    movies[0].year=1970;
    movies[0].imdbRating = 9.7;
    movies[0].title = "Best movie of 1970";
    movies[0].director = "scorsese";

    movies[1].year=1960;
    movies[1].imdbRating = 9;
    movies[1].title = "Movie 1960";
    movies[1].director = "kubrick";

    movies[2].year=1970;
    movies[2].imdbRating = 9.5;
    movies[2].title = "Not quite best movie of 1970";
    movies[2].director = "hitchcock";

    movies[3].year=1998;
    movies[3].imdbRating = 8.5;
    movies[3].title = "some movie";
    movies[3].director = "tarantino";

    movies[4].year=1965;
    movies[4].imdbRating = 8.5;
    movies[4].title = "another h movie";
    movies[4].director = "hitchcock";
    return movies;
}
```

# Task 1) Print the movies in a file (1p)

You should print in `../out.txt` the movies in the format:

```c
"Movie \"%s\" from year %d, directed by %s, rated at %.2lf\n"
```

Print for this task:
* "Task1"
* each movie on a new line

Output:
```
Task1:
Movie "Best movie of 1970" from year 1970, directed by scorsese, rated at 9.70
Movie "Movie 1960" from year 1960, directed by kubrick, rated at 9.00
Movie "Not quite best movie of 1970" from year 1970, directed by hitchcock, rated at 9.50
Movie "some movie" from year 1998, directed by tarantino, rated at 8.50
Movie "another h movie" from year 1965, directed by hitchcock, rated at 8.50
```

# Task 2) Print first director alphabetically (1p)

Print in the file which director would be the first director in alphabetical order. You may use functions from `string.h`.

Use the format:
```c
"The first director (alphabetically) is %s"
```

Output file: 
```
Task2:
The first director (alphabetically) is hitchcock
```

# Task 3) Print the movies of the director from task 2 (1p)

Print the movies' titles of director from task2. 

In the dummy data, there are 2 movies with director "hitchcock" that should be printed.

Output file:
```
Task3:
The movies for director hitchcock are:
Not quite best movie of 1970
another h movie
```

# Task 4) Get best movie of a given year (2p)

Read from the __console__ a year, then print in the __output__ file the best movie (with the highest rating) from that year.

You should promt the user (console) with this message:
```c
"Please input the year to show the best movie from\n"
```

Console:
```
Please input the year to show the best movie from
>1970
```

Output file:
```
Task4:
Best movie of the year 1970 is "Best movie of 1970"
```


# Output file after tasks 1-4
```
Task1:
Movie "Best movie of 1970" from year 1970, directed by scorsese, rated at 9.70
Movie "Movie 1960" from year 1960, directed by kubrick, rated at 9.00
Movie "Not quite best movie of 1970" from year 1970, directed by hitchcock, rated at 9.50
Movie "some movie" from year 1998, directed by tarantino, rated at 8.50
Movie "another h movie" from year 1965, directed by hitchcock, rated at 8.50

Task2:
The first director (alphabetically) is hitchcock

Task3:
The movies for director hitchcock are:
Not quite best movie of 1970
another h movie

Task4:
Best movie of the year 1970 is "Best movie of 1970"
```

# Task 5) Read movies (2p)

You should read an array of movies from the file "../in.txt" and output them to the console. You do not have to redo task1-4 with this data! You can leave those with the dummy data.

File format:
* first line: n - number of movies
* second line: years (n numbers)
* third line: imdb rating (n floats)
* fourth line: titles (n words, can consider each title does not contain spaces)
* fifth line: directors (n words, can consider each director does not contain spaces)

Maximum number of characters in strings:
```c
#define MAX_TITLE 20
#define MAX_DIRECTOR_NAME
```

Example
3
1970 1980 1990
9 9.5 10
movie1 movie2 movie3
director1 director2 director3
```

You should write in the __console__:
* message "Read movies are:" 
* on each subsequent line the movies in the format Movie (\<year>,\<rating>,\<title>,\<director>)

Console:
```
Read movies are:
Movie (1970,9.00,movie1,director1)
Movie (1980,9.50,movie2,director2)
Movie (1990,10.00,movie3,director3)
```

# Task 6) Push the code (1p)

Please push the code in the provided repo. No need for multiple branches (&pull req).

# Notes

Please:
* close files and free memory

You may be penalized for code quality.
