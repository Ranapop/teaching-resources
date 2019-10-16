#include "Profiler.h"
#include <stdio.h>
#include <stdlib.h>
#define DEBUG
#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

#define BEST_BUBBLE_ASSIG_SERIES "BEST_bubble_assignments"
#define BEST_BUBBLE_COMP_SERIES "BEST_bubble_comparisons"
#define BEST_BUBBLE_OPERATIONS_SERIES "BEST_bubble_operations"

#define AVG_BUBBLE_ASSIG_SERIES "AVG_bubble_assignments"
#define AVG_BUBBLE_COMP_SERIES "AVG_bubble_comparisons"
#define AVG_BUBBLE_OPERATIONS_SERIES "AVG_bubble_operations"

Profiler profiler("SortingMethods");

int assig = 0;
int comp = 0;

int * generateBestCase(int n) {

    int * a = (int*)malloc(n * sizeof(int));
    for(int i=0; i < n; i++) {
        a[i]=i;
    }
    return a;
}

int * generateAvgCase(int n) {
    int * a = (int*)malloc(n * sizeof(int));
    FillRandomArray(a, n, 1, n, true,0);
    return a;
}

int * generateWorstCase(int n) {
    int * a = (int*)malloc(n * sizeof(int));
    FillRandomArray(a, n, 1, n, true,0);
    return a;
}

void printArray(int * a, int n) {
    for(int i =0; i<n; i++) {
        LOG("%d ",a[i]);
    }
    LOG("\n");
}

void bubbleSort(int * a, int n) {
    for (int i=0; i<n-1; i++) {
        for(int j=0; j< n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                assig += 3;
            }
            comp += 1;
        }
        printArray(a,n);
    }
}

void demoBubble() {
    printf("\nDEMO BUBBLE\n");
    int a[5] = {12,3,7,11,2};
    bubbleSort(a,5);
}


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
    int a[5] = {12,3,7,11,2};
    insertionSort(a,5);
}

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

int main() {

    demoBubble();
    demoInsertion();
    //generateBubbleGraphs();
    profiler.showReport();
    return 0;
}

