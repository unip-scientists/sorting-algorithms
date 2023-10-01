#include "sorting/sorting.h"
#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) {
    int duration = 0;
    if (strcmp(argv[0], "selection")) {
        duration = benchmark(&selectionSort);
    } else if (strcmp(argv[0], "bubble")) {
        duration = benchmark(&bubbleSort);
    }

    std::cout << "Duration: " << duration << "ms";
    return 0;
}