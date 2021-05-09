#include <stdlib.h>

#include <iostream>

#define V 4
#define INF 999

void imprimir_solucion(int dist[][V]);

void floyd_warshall(int graph[][V]) {
  int dist[V][V], i, j, k;

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  imprimir_solucion(dist);
}

void imprimir_solucion(int dist[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF)
        std::cout << "INF"
                  << "     ";
      else
        std::cout << dist[i][j] << "     ";
    }
    std::cout << std::endl;
  }
}

int main() {
  int graph[V][V] = {
      {0, 30, 120, INF}, {50, 0, 70, 50}, {140, 60, 0, 30}, {25, 100, 80, 0}};

  floyd_warshall(graph);
  return 0;
}
