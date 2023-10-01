#ifndef SORTING_H
#define SORTING_H

int benchmark(void (*fn)(int* array, int length));
void selectionSort(int *A, int size);
void bubbleSort(int *A, int size);

#endif