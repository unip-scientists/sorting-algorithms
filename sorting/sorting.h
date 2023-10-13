#ifndef SORTING_H
#define SORTING_H

int benchmark(void (*fn)(int* array, int length), int totalInputLength);
void selectionSort(int *A, int size);
void bubbleSort(int *A, int size);
void insertionSort(int *A, int size);
void mergeSort(int *A, int size);

#endif