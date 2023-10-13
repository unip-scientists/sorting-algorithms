void insertionSort(int *A, int size) {
    for (int i = 1; i < size; i++) {
        int key = A[i];
        int j = i-1;

        while (j >= 0 && key < A[j]) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = key;
    }
}