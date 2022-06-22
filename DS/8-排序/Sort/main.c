#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

int main() {
    printf("Hello, World!\n");
    int a[SIZE] = {1,2,3};
    int b[8] = {53,17,78,9,45,65,87,32};
    printf("b[8]地址： %d， a地址: %d \n", &b[8] , a);
    printf("b[8] = %d , b[9] = %d, b[10] = %d, b[11] = %d", b[8], b[9], b[10], b[11]);
    clock_t start, finish;
    double duration;
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand()%SIZE;
    }
    printf("\nsorting\n");
    start = clock();
//    InsertSort(a, SIZE);
//    HS_InsertSort(a, SIZE);
//    QuickSort(a, 0,SIZE-1);
//    SelectSort(a, SIZE);
//    HeapSort(b, SIZE);
//    SmallHeapSort(a,SIZE);
    MergeSort(a, 0, SIZE-1);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n%f seconds\n", duration);

    return 0;
}
