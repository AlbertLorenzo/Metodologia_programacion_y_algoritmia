#include <stdlib.h>

#include <climits>
#include <fstream>
#include <iostream>
#include <string>

//Variables globales
int **matriz, num_ciudades;
std::string *ciudades;

int coste_minimo(int *coste, bool *visitado) {
    int min = INT_MAX, indice;
    for (int i = 0; i < num_ciudades; i++) {
        if (!visitado[i] && coste[i] <= min) {
            min = coste[i];
            indice = i;
        }
    }
    return indice;
}

void muestra_vuelos_baratos(int src, int *coste) {
    std::cout << "Destino\t\t Precio " << std::endl;
    std::cout << "-------\t\t ------ " << std::endl;
    for (int i = 0; i < num_ciudades; i++) {
        if (i != src) {
            std::cout << ciudades[i] << "\t\t " << coste[i] << std::endl;
        }
    }
}

void imprimir_ruta(int *arbol_ruta, int j) {
    if (arbol_ruta[j] == -1) {
        return;
    }
    imprimir_ruta(arbol_ruta, arbol_ruta[j]);
    std::cout << " -> " << ciudades[j];
}

void mostrar_rutas(int *coste, int *arbol_ruta, int src) {
    std::cout << "Destino\t\tPrecio\t\t\tRuta" << std::endl;
    std::cout << "-------\t\t------\t\t\t----" << std::endl;
    for (int i = 0; i < num_ciudades; i++) {
        if (i != src) {
            std::cout << ciudades[i] << "\t\t" << coste[i] << "\t\t" << ciudades[src];
            imprimir_ruta(arbol_ruta, i);
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void Dijkstra(int src, int opcion) {
    int coste[num_ciudades], arbol_ruta[num_ciudades], u;
    bool visitado[num_ciudades];

    for (int i = 0; i < num_ciudades; i++) {
        coste[i] = INT_MAX;
        visitado[i] = false;
    }

    coste[src] = 0;
    arbol_ruta[src] = -1;

    for (int i = 0; i < num_ciudades; i++) {
        u = coste_minimo(coste, visitado);
        visitado[u] = true;
        for (int v = 0; v < num_ciudades; v++) {
            if (!visitado[v] && matriz[u][v] && coste[u] != INT_MAX && coste[u] + matriz[u][v] < coste[v]) {
                arbol_ruta[v] = u;
                coste[v] = coste[u] + matriz[u][v];
            }
        }
    }

    if (opcion == 1) {
        mostrar_rutas(coste, arbol_ruta, src);
    } else {
        muestra_vuelos_baratos(src, coste);
    }
}

void rellenar_datos() {
    std::string ciudad, num_ciud, precio_ciud, nombre_archivo;
    std::cout << "Introduce el archivo de texto: ";
    std::cin >> nombre_archivo;
    std::ifstream datos(nombre_archivo, std::ios_base::in);
    datos >> num_ciudades;
    getline(datos, num_ciud);

    matriz = new int *[num_ciudades];
    ciudades = new std::string[num_ciudades];

    for (int i = 0; i < num_ciudades; i++) {
        getline(datos, ciudad);
        ciudades[i] = ciudad;
    }

    for (int i = 0; i < num_ciudades; i++) {
        matriz[i] = new int[num_ciudades];
        for (int j = 0; j < num_ciudades; j++) {
            datos >> matriz[i][j];
        }
    }
}

int comparar_ciudades(std::string ciudad) {
    for (int i = 0; i < num_ciudades; i++) {
        if (ciudad == ciudades[i]) {
            return i;
        }
    }
    return 0;
}

void mostrar_ciudades() {
    std::cout << "Ciudades disponibles: ";
    for (int i = 0; i < num_ciudades; i++) {
        std::cout << ciudades[i] << " ";
    }
    std::cout << std::endl;
}

void menu_principal() {
    int opcion_menu = 0, ciud_elegida;
    std::string ciudad_elegida;

    do {
        std::cout << "1.- Vuelos." << std::endl;
        std::cout << "2.- Precios de los vuelos mas baratos." << std::endl;
        std::cout << "3.- Precios y rutas de los vuelos mas baratos." << std::endl;
        std::cout << "4.- Salir." << std::endl;
        std::cout << "Introduce una opcion valida <1-4>: ";
        std::cin >> opcion_menu;

        switch (opcion_menu) {
            case 1: {
                rellenar_datos();
                break;
            }

            case 2: {
                mostrar_ciudades();
                std::cout << "Introduce la ciudad de origen: ";
                std::cin >> ciudad_elegida;
                ciud_elegida = comparar_ciudades(ciudad_elegida);
                Dijkstra(ciud_elegida, 0);
                break;
            }

            case 3: {
                mostrar_ciudades();
                std::cout << "Introduce la ciudad de origen: " << std::endl;
                std::cin >> ciudad_elegida;
                ciud_elegida = comparar_ciudades(ciudad_elegida);
                Dijkstra(ciud_elegida, 1);
                break;
            }

            default:
                break;
        }

    } while (opcion_menu != 4);
}

int main(void) {
    menu_principal();
}