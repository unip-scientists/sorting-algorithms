#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN64

#include "windows.h"

#else

unsigned long GetTickCount()
{
    struct timespec ts;
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        // Handle error
        return 0;
    }
    
    // Convert seconds to milliseconds and add nanoseconds converted to milliseconds
    return (unsigned long)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

#endif


int benchmark(void (*fn)(int* array, int length), int totalInputLength)
{
    int start, end, elapsed_time;
    int vetor[totalInputLength];
    for (int x = 0; x < totalInputLength; x++)
    {
        vetor[x] = rand() % 4294967296;
    }

    start = GetTickCount();

    fn(vetor, totalInputLength);

    end = GetTickCount();

    elapsed_time = end - start;
    return elapsed_time;
}