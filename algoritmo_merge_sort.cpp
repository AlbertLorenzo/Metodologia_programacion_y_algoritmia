#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#define n 6

void merge(int *v, int i, int m, int d) {
    
}

void merge_sort(int *v, int i, int d) {
    if (i < d) {
        int medio = (i + (d - 1)) / 2;

        merge_sort(v, i, medio);
        merge_sort(v, medio + 1, d);

        merge(v, i, medio, d);
    }
}

void imprimir_vector(int *v) {
    for (int i = 0; i < n; i++) {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

int main(void) {
    int vector[n] = {12, 11, 13, 5, 6, 7};
}