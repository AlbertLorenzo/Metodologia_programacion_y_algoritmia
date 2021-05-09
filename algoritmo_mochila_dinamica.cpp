#include <stdlib.h>

#include <iostream>

/*  Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
    Lorenzo Segarra (alu51) */

using namespace std;

float maximo(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void rellenar_vector(int n, int *V) {
    for (int i = 1; i <= n; i++) {
        cout << "Peso del objeto " << i << ":" << endl;
        cin >> V[i];
    }
}

void rellenar_vector_float(int n, float *V) {
    for (int i = 1; i <= n; i++) {
        cout << "Valor del objeto " << i << ":" << endl;
        cin >> V[i];
    }
}

float mochila(int M, int n, int *P, float *V) {
    float **T = new float *[n + 1];

    if (T == NULL) {
        cout << "Error al reservar memoria" << endl;
        return -1;
    }

    for (int i = 0; i <= n; i++) {
        T[i] = new float[M + 1];
        if (T[i] == NULL) {
            cout << "Error al reservar memoria" << endl;
            return 0;
        }
    }

    for (int i = 0; i <= M; i++) {
        T[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        T[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (P[i] > j) {
                T[i][j] = T[i - 1][j];
            } else {
                T[i][j] = maximo(T[i - 1][j], V[i] + T[i - 1][j - P[i]]);
            }
        }
    }

    return T[n][M];
}

int main() {
    int peso_maximo, num_total_objetos, *pesos_objetos;
    float *valor_objetos, resultado;

    cout << "Peso maximo de la mochila:";
    cin >> peso_maximo;

    cout << "\nTotal de objetos:\n";
    cin >> num_total_objetos;

    pesos_objetos = new int[num_total_objetos + 1];
    valor_objetos = new float[num_total_objetos + 1];

    rellenar_vector(num_total_objetos, pesos_objetos);
    rellenar_vector_float(num_total_objetos, valor_objetos);

    resultado = mochila(peso_maximo, num_total_objetos, pesos_objetos, valor_objetos);

    cout << "Valor maximo que puede llevar: " << resultado;

    cout << endl;
    return 0;
}