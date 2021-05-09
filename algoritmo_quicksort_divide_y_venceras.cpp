#include <stdlib.h>
#include <time.h>

#include <iostream>

/*  Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
    Lorenzo Segarra (alu51) */

using namespace std;

void imprimirVector(int n, int *v) {
    for (int i = 1; i <= n; i++) {
        if (i != n) {
            cout << v[i] << " ";
        } else {
            cout << v[i];
        }
    }
    cout << endl;
}

void rellenarVectorManual(int n, int *v) {
    for (int i = 1; i <= n; i++) {
        cout << "Introduce elemento " << i << ":";
        cin >> v[i];
        cout << endl;
    }
}

void rellenarVector(int n, int *v) {
    for (int i = 1; i <= n; i++) {
        v[i] = rand();
    }
}

void intercambiar(int *v, int i, int d) {
    int tmp;
    tmp = v[i];
    v[i] = v[d];
    v[d] = tmp;
}

int seleccionar_pivote(int *V, int izq, int der, int estrategia) {
    if (estrategia == 1) {
        int i, d, m;
        m = V[(izq + der) / 2];
        i = V[izq];
        d = V[der];
        if ((i < m && m < d) || (d < m && m < i)) {
            return (izq + der) / 2;
        } else if ((m < i && i < d) || (d < i && i < m)) {
            return izq;
        } else {
            return der;
        }
    }

    if (estrategia == 2) {
        return rand() % (der-izq + 1) + izq;
    }

    if (estrategia == 3) {
        return izq;
    }
    return 0;
}

void quicksort(int *V, int izq, int der, int estrategia) {
    int i, d, p, pivote;

    p = seleccionar_pivote(V, izq, der, estrategia);
    if (p > 0) {
        pivote = V[p];
        i = izq;
        d = der;
    }

    while (V[i] < pivote) {
        i += 1;
    }

    while (V[d] > pivote) {
        d -= 1;
    }

    if (i <= d) {
        intercambiar(V, i, d);
        i += 1;
        d -= 1;
    }

    if (izq < d) {
        quicksort(V, izq, d, estrategia);
    }

    if (i < der) {
        quicksort(V, i, der, estrategia);
    }
}

double tiempoEjecucion(int dimensionVector, int *v, int estrategia) {
    clock_t tinicio, tfin;
    double tiempo;
    tinicio = clock();
    quicksort(v, 1, dimensionVector, estrategia);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    return tiempo;
}

int main() {
    int dimensionVector, estrategia, *vector;
    // double t;
    // srand(5);

    cout << "Introduce num.total elementos del vector:";
    cin >> dimensionVector;
    cout << endl;
    vector = new int[dimensionVector + 1];
    rellenarVectorManual(dimensionVector, vector);
    // rellenarVector(dimensionVector, vector);
    cout << "Estrategia del pivote (1, 2, 3):";
    cin >> estrategia;
    cout << endl;
    cout << "Vector original: ";
    imprimirVector(dimensionVector, vector);
    quicksort(vector, 1, dimensionVector, estrategia);
    // t = tiempoEjecucion(dimensionVector, vector, estrategia);
    cout << "Vector ordenado: ";
    imprimirVector(dimensionVector, vector);
    // cout << "Tiempo de ejecucion <ms>: " << t << endl;
}