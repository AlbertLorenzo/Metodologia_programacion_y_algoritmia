#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

/*
Hecho por:
Albert Lorenzo Segarra
*/

void Insercion(int n, int *v) {
    int x, j;
    for (int i = 2; i <= n; i++) {
        x = v[i];
        j = i - 1;
        while ((j > 0) && (v[j] > x)) {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = x;
    }
}   

void reversoVector(int n, int *v) {
    int a, indice;
    for (int i = 1; i <= n / 2; i++) {
        indice = n - (i - 1);
        a = v[i];
        v[i] = v[indice];
        v[indice] = a;
    }
}

void rellenarVector(int n, int *v) {
    for (int i = 1; i <= n; i++) {
        v[i] = rand();
    }
}

void imprimirVector(int *v, int inicio, int fin) {
    for (int i = inicio; i <= fin; i++) {
        if (i < fin) {
            cout << v[i] << " ";
        } else {
            cout << v[i];
        }
    }
    cout << endl;
}

double tiempoEjecucion(int n, int *v) {
    clock_t tinicio, tfin;
    double tiempo;
    tinicio = clock();
    Insercion(n, v);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;
    return tiempo;
}

int main() {
    int *vector, s, dimensionVector, vInicial, vFinal, muestraTiempo;

    cout << "Semilla para generar aleatorios:";
    cin >> s;
    srand(s);

    cout << "\n";

    cout << "Introduce tamanyo del vector:";
    cin >> dimensionVector;
    cout << endl;

    cout << "Posiciones INICIAL y FINAL del vector para mostrar\n";
    cout << "INICIAL:";
    cin >> vInicial;
    cout << "\n";
    cout << "FINAL:";
    cin >> vFinal;
    cout << endl;

    cout << "Mostrar tiempo de ejecucion (1:Si, 0:No):";
    cin >> muestraTiempo;
    cout << endl;
    cout << "\nALGORITMO DE INSERCION\n"
         << endl;

    vector = new int[dimensionVector + 1];
    rellenarVector(dimensionVector, vector);

    if (vector == NULL) {
        cout << "Error en el programa." << endl;
        return -1;
    } else {
        if (!muestraTiempo) {
            cout << "CASO CUALQUIERA" << endl;
            cout << "---------------" << endl;
            cout << "Vector a ordenar: ";
            imprimirVector(vector, vInicial, vFinal);
            Insercion(dimensionVector, vector);
            cout << "Vector ordenado: ";
            imprimirVector(vector, vInicial, vFinal);

            cout << "CASO MEJOR" << endl;
            cout << "---------------" << endl;
            cout << "Vector a ordenar: ";
            imprimirVector(vector, vInicial, vFinal);
            cout << "Vector ordenado: ";
            imprimirVector(vector, vInicial, vFinal);

            cout << "CASO PEOR" << endl;
            cout << "---------------" << endl;
            cout << "Vector a ordenar: ";
            reversoVector(dimensionVector, vector);
            imprimirVector(vector, vInicial, vFinal);
            Insercion(dimensionVector, vector);
            cout << "Vector ordenado: ";
            imprimirVector(vector, vInicial, vFinal);

        } else {
            double t;
            cout << "CASO CUALQUIERA" << endl;
            cout << "---------------" << endl;
            cout << "Vector a ordenar: ";
            imprimirVector(vector, vInicial, vFinal);
            t = tiempoEjecucion(dimensionVector, vector);
            cout << "Vector ordenado: ";
            imprimirVector(vector, vInicial, vFinal);
            cout << "Tiempo <ms>: " << t << endl;

            cout << "CASO MEJOR" << endl;
            cout << "---------------" << endl;
            cout << "Vector a ordenar: ";
            imprimirVector(vector, vInicial, vFinal);
            t = tiempoEjecucion(dimensionVector, vector);
            cout << "Vector ordenado: ";
            imprimirVector(vector, vInicial, vFinal);
            cout << "Tiempo <ms>: " << t << endl;

            cout << "CASO PEOR" << endl;
            cout << "---------------" << endl;
            cout << "Vector a ordenar: ";
            reversoVector(dimensionVector, vector);
            imprimirVector(vector, vInicial, vFinal);
            t = tiempoEjecucion(dimensionVector, vector);
            cout << "Vector ordenado: ";
            imprimirVector(vector, vInicial, vFinal);
            cout << "Tiempo <ms>: " << t << endl;
        }
    }

    cout << "FIN DEL PROGRAMA";
    cout << endl;
    return 0;
}