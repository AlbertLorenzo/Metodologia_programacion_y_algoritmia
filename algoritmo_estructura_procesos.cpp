#include <bits/stdc++.h>

// Estructura para las clases
struct Clase {
  float horaInicio;
  float horaFin;
  std::string nombreClase;
  bool operator<(const Clase& c1) const { return (horaInicio < c1.horaInicio); }
};

int main() {
  // Base de datos
  int const NUMERODECLASES = 6;

  float const horasInicio[NUMERODECLASES] = {11.00, 9.00,  12.30,
                                             9.00,  11.30, 10.30};

  float const horasFin[NUMERODECLASES] = {13.00, 10.30, 14.00,
                                          11.00, 12.30, 11.30};

  std::string const nombresClases[NUMERODECLASES] = {
      "Administracion y Direccion de Empresas",
      "Biotecnologia",
      "Ciencias de la Actividad Fisica y del Deporte",
      "Comunicacion Audiovisual",
      "Estadistica Empresarial",
      "Ingenieria Informática en Tecnologias de la Informacion"};

  // Vector de objetos
  Clase clases[NUMERODECLASES];

  // Código para insertar información en cada objeto
  for (int i = 0; i < NUMERODECLASES; i++) {
    clases[i].horaInicio = horasInicio[i];
    clases[i].horaFin = horasFin[i];
    clases[i].nombreClase = nombresClases[i];
  }

  // Ordenar vector de objetos por selección
  for (int i = 0; i < NUMERODECLASES - 1; i++) {
    int min = i;
    for (int j = i + 1; j < NUMERODECLASES; j++) {
      if (clases[j].horaInicio < clases[min].horaInicio) {
        min = j;
      }
    }
    Clase temp = clases[min];
    clases[min] = clases[i];
    clases[i] = temp;
  }

  // Código para imprimir vector de objetos
  for (auto&& clase : clases) {
    std::cout << clase.horaInicio << " - " << clase.horaFin << " "
              << clase.nombreClase << std::endl;
  }
}