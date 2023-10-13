#include "sorting/sorting.h"
#include <iostream>
#include <cstring>


void runManyTest(void (*fn)(int *A, int length)) {
    static int inputNumber[] = {10000, 20000, 40000, 80000};

    std::string sheet[102][5];
    sheet[0][0] = "Benchmark";
    sheet[0][1] = "10000 numbers";
    sheet[0][2] = "20000 numbers";
    sheet[0][3] = "40000 numbers";
    sheet[0][4] = "80000 numbers";

    for (int currentInputTest = 0; currentInputTest < 4; currentInputTest++) {
        for (int testCase = 0; testCase < 100; testCase++) {
            int duration = benchmark(fn, inputNumber[currentInputTest]);
            sheet[testCase+1][currentInputTest+1] = std::to_string(duration);

            std::cout << "Benchmarking ["<< testCase << "] " 
                << "on input length of " << inputNumber[currentInputTest] << std::endl;
        }
    }

    for(int row = 0; row < 101; row++) {
        sheet[row+1][0] = std::to_string(row+1);

        for(int col = 0; col < 5; col++) {
            std::cout << sheet[row][col];

            if (col < 4) {
                std::cout << ";";
            }
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "selection") == 0) {
        std::cout << "Running [Selection]" << std::endl << std::endl;
        runManyTest(&selectionSort);
    } else if (strcmp(argv[1], "bubble") == 0) {
        std::cout << "Running [Bubble]" << std::endl << std::endl;
        runManyTest(&bubbleSort);
    } else if (strcmp(argv[1], "insertion") == 0) {
        std::cout << "Running [Insertion]" << std::endl << std::endl;
        runManyTest(&insertionSort);
    } else if (strcmp(argv[1], "merge") == 0) {
        std::cout << "Running [Merge]" << std::endl << std::endl;
        runManyTest(&mergeSort);
    } else {
        std::cout << "No sorting algorithm chosen" << std::endl;
    }

    return 0;
}