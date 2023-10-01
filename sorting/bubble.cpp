void bubbleSort(int *A, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = size-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}