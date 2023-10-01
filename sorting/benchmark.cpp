#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TAM 10000

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


int benchmark(void (*fn)(int* array, int length))
{
    int inicio, final, tempo_decorrido;
    int vetor[TAM];
    for (int x = 0; x < TAM; x++)
    {
        vetor[x] = rand() % 100;
    }

    inicio = GetTickCount();

    fn(vetor, TAM);

    final = GetTickCount();

    tempo_decorrido = final - inicio;
    return tempo_decorrido;
}