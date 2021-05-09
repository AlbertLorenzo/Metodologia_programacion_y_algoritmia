#include <stdlib.h>

#include <iostream>

#define LIMITE 10

/*  Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
    Lorenzo Segarra (alu51) */

void rellenar_vector_float(int n, float *V) {
    for (int i = 1; i <= n; i++) {
        std::cout << "Objeto " << i << ":" << std::endl;
        std::cin >> V[i];
    }
}

void rellenar_ceros(int n, int *V) {
    for (int i = 1; i <= n; i++) {
        V[i] = 0;
    }
}

float CalcularSuma(int *X, float *P, int k) {
    float suma = 0;
    for (int i = 1; i <= k; i++) {
        if (X[i] == 1) {
            suma += P[i];
        }
    }
    return suma;
}

void mochila(float *P, float *V, int *X, int k, int *Xoptimo, float &Voptimo, int n) {
    float peso, valor;
    if (k <= n) {
        for (int i = 0; i <= 1; i++) {
            X[k] = i;
            peso = CalcularSuma(X, P, k);
            if (peso <= LIMITE) {
                if (k == n) {
                    valor = CalcularSuma(X, V, k);
                    if (valor > Voptimo) {
                        for (int j = 1; j <= k; j++) {
                            Xoptimo[j] = X[j];
                        }
                        Voptimo = valor;
                    }
                } else {
                    mochila(P, V, X, k + 1, Xoptimo, Voptimo, n);
                }
            }
        }
    }
}

int main() {
    int num_total_objetos, *X, *Xoptimo;
    float peso, valor, Voptimo, *valor_objetos, *pesos_objetos;

    std::cout << "Introduce el total de objetos (n):";
    std::cin >> num_total_objetos;

    pesos_objetos = new float[num_total_objetos + 1];
    valor_objetos = new float[num_total_objetos + 1];
    Xoptimo = new int[num_total_objetos + 1];
    X = new int[num_total_objetos + 1];

    std::cout << "\nPESOS:" << std::endl;
    rellenar_vector_float(num_total_objetos, pesos_objetos);

    std::cout << "VALORES:" << std::endl;
    rellenar_vector_float(num_total_objetos, valor_objetos);

    rellenar_ceros(num_total_objetos, Xoptimo);
    rellenar_ceros(num_total_objetos, X);

    Voptimo = 0;
    mochila(pesos_objetos, valor_objetos, X, 1, Xoptimo, Voptimo, num_total_objetos);

    std::cout << "\nOBJETOS A INTRODUCIR EN LA MALETA" << std::endl;
    valor = 0;
    peso = 0;
    for (int i = 1; i <= num_total_objetos; i++) {
        if (Xoptimo[i] == 1) {
            std::cout << i << ": " << pesos_objetos[i] << "kg - Valor: " << valor_objetos[i] << std::endl;
            peso += pesos_objetos[i];
            valor += valor_objetos[i];
        }
    }
    std::cout << "\nPeso: " << peso << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "\nOBJETOS QUE QUEDAN FUERA:";
    for (int i = 1; i <= num_total_objetos; i++) {
        if (Xoptimo[i] == 0) {
            std::cout << " " << i;
        }
    }
    
    std::cout << std::endl;
    return 0;
}