# Sorting Methods

## Include the profiler

Start by testing a "hello world" with the included profiler.

```c
#include "Profiler.h"
#include <stdio.h>
#include <stdlib.h>

Profiler profiler("SortingMethods");

int main() {
    printf("%s", "Hello world!");
    return 0;
}
```
## Prepare logging

With this code, if DEBUG is not commented out, LOG will be replaced with printf. So when running the demo, leave ```#define DEBUG```, otherwise comment it out (when creating the graphs).

```c
#define DEBUG
#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
```

Create a function for printing an array

```c
void printArray(int * a, int n) {
    for(int i =0; i<n; i++) {
        LOG("%d ",a[i]);
    }
    LOG("\n");
}
```
## Implement bubble

Create a function for bubble and test it in main

```c
void bubbleSort(int * a, int n) {
    for (int i=0; i<n-1; i++) {
        for(int j=0; j< n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
        printArray(a,n);
    }
}

int main() {
    int a[5] = {10,3,7,11,2};
    printArray(a,5);
    bubbleSort(a,5);
    free(a);
    return 0;
}
```
## Demo

Move the code from main to a function ```demoBubble``` and call that instead:
```c
void demoBubble() {
    int a[5] = {10,3,7,11,2};
    bubbleSort(a,5);
}

int main() {

    demoBubble();
    return 0;
}
```

## Generate graph for the best case

First, we will define the name of the series we want to use. We could use strings without putting them in constants when calling profiler functions, but that is less clean and more error prone:

```c
#define BEST_BUBBLE_ASSIG_SERIES "BEST_bubble_assignments"
#define BEST_BUBBLE_COMP_SERIES "BEST_bubble_comparisons"
#define BEST_BUBBLE_OPERATIONS "BEST_bubble_operations"
```

We want to count the number of operations for bubble, both the assignments and the comparisons. To keep things simple, we will just declare two global variables, then increment them in the bubble function:
```c
int assig = 0;
int comp = 0;
```
```c
void bubbleSort(int * a, int n) {
    for (int i=0; i<n-1; i++) {
        for(int j=0; j< n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                assig += 3; // for the swap, 3 assignments were made so we increment the number of assignments by 3
            }
            comp += 1; // for comparing a[j] > a[j+1] a comparison was made, so we increment the number of comparisons
        }
        printArray(a,n);
    }
}
```
All 3 sorting methods behave best when the array is already sorted (they do the smallest number of operations then). We want to analyze how the sorting alorithms behave in this case. We will want to generate a chart for which the x axis represents the size of the input, while the y axis represents the number of operations done on that input. 

To do that for the best case, we create a function which gets the size of the input, and generates a sorted array of that size. We will call this function for each size of the input to obtain an ordered array, and then we will sort that ordered array and count the number of operations.

```c
int * generateBestCase(int n) {

    int * a = (int*)malloc(n * sizeof(int));
    for(int i=0; i < n; i++) {
        a[i]=i; 
    }
    return a;
}
```

Then create a function which for different sizes generates ordered arrays, sorts them with bubble and counts the operations:
```c
void generateBubbleGraphs() {
    for(int size=0; size < 10000; size += 100) {

        // generate best case
        assig = 0;
        comp = 0;
        int * a = generateBestCase(size);
        bubbleSort(a,size);
        profiler.countOperation(BEST_BUBBLE_ASSIG_SERIES, size, assig);
        profiler.countOperation(BEST_BUBBLE_COMP_SERIES, size, comp);
        free(a);
    }
    profiler.addSeries(BEST_BUBBLE_OPERATIONS_SERIES, BEST_BUBBLE_ASSIG_SERIES, AVG_BUBBLE_COMP_SERIES);
}
```

In main, use ```profiler.showReport()``` to actually create the html page:
```c
int main() {

    demoBubble();
    generateBubbleGraphs();
    profiler.showReport();
    return 0;
}
```

Before running, make sure to turn debugging offf:
```c
//#define DEBUG
```
## Generate graph for the average case 
Start by, again, defining the series' names:
```c
#define AVG_BUBBLE_ASSIG_SERIES "AVG_bubble_assignments"
#define AVG_BUBBLE_COMP_SERIES "AVG_bubble_comparisons"
#define AVG_BUBBLE_OPERATIONS_SERIES "AVG_bubble_operations"
```
In the loop of ```generateBubbleGraphs``` generate the avg case, sort the array and count the operations for avg:
```c
// generate average case
assig = 0;
comp = 0;
a = generateAvgCase(size);
bubbleSort(a,size);
profiler.countOperation(AVG_BUBBLE_ASSIG_SERIES, size, assig);
profiler.countOperation(AVG_BUBBLE_COMP_SERIES, size, comp);
free(a);
```
Then use ```addSeries``` to create the series for the total number of operations of bubble in the average case (out of the loop):
```c
profiler.addSeries(AVG_BUBBLE_OPERATIONS_SERIES, AVG_BUBBLE_ASSIG_SERIES, AVG_BUBBLE_COMP_SERIES);
```

This results in:
```c
void generateBubbleGraphs() {
    for(int size=0; size < 10000; size += 100) {

        // generate best case
        assig = 0;
        comp = 0;
        int * a = generateBestCase(size);
        bubbleSort(a,size);
        profiler.countOperation(BEST_BUBBLE_ASSIG_SERIES, size, assig);
        profiler.countOperation(BEST_BUBBLE_COMP_SERIES, size, comp);
        free(a);

        // generate average case
        assig = 0;
        comp = 0;
        a = generateAvgCase(size);
        bubbleSort(a,size);
        profiler.countOperation(AVG_BUBBLE_ASSIG_SERIES, size, assig);
        profiler.countOperation(AVG_BUBBLE_COMP_SERIES, size, comp);
        free(a);
    }
    profiler.addSeries(BEST_BUBBLE_OPERATIONS_SERIES, BEST_BUBBLE_ASSIG_SERIES, BEST_BUBBLE_COMP_SERIES);
    profiler.addSeries(AVG_BUBBLE_OPERATIONS_SERIES, AVG_BUBBLE_ASSIG_SERIES, AVG_BUBBLE_COMP_SERIES);
}
```
## Demo insertion sort

```c
void insertionSort(int * a, int n) {

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (key < a[j] && j >= 0) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        printArray(a,n);
    }
}

void demoInsertion() {
    printf("\nDEMO INSERTION\n");
    int a[5] = {10,3,7,11,2};
    insertionSort(a,5);
}
```
