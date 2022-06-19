#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"




int main() {
    printf("Hello, World!\n");
    int a[SIZE];
    clock_t start, finish;
    double duration;
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand()%SIZE;
    }
//    for (int i = 0; i < SIZE; ++i) {
//        printf("%d ", a[i]);
//    }
    printf("sorting\n");
    start = clock();
//    InsertSort(a, SIZE);
//    HS_InsertSort(a, SIZE);
//    QuickSort(a, 0,SIZE-1);
    SelectSort(a, SIZE);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n%f seconds\n", duration);

    return 0;
}
