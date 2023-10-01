int max(int *A, int p, int q, int *j) {
    int min = 2*1000;
    for (int i = p; i < q; i++) {
        if (A[i] < min) {
            min = A[i];
            *j = i;
        }
    }
    return min;
}

void selectionSort(int *A, int size) {
    for (int i = 0; i < size; i++) {
        int j = 0;
        int min = max(A, i, size, &j);

        A[j] = A[i];
        A[i] = min;
    }
}