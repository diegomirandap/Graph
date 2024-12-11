#include "aux.h"
#include <stdio.h>

int main() {
  Grafo grafo;
  int numVertices = 7;
  char vetVertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'H'};

  inicializarGrafo(&grafo, numVertices, vetVertices);

  adicionarAresta(&grafo, 'A', 'B', 5);
  adicionarAresta(&grafo, 'A', 'C', 4);
  adicionarAresta(&grafo, 'A', 'D', 2);
  adicionarAresta(&grafo, 'B', 'C', 6);
  adicionarAresta(&grafo, 'B', 'E', 6);
  adicionarAresta(&grafo, 'B', 'H', 9);
  adicionarAresta(&grafo, 'C', 'D', 3);
  adicionarAresta(&grafo, 'C', 'E', 4);
  adicionarAresta(&grafo, 'D', 'E', 5);
  adicionarAresta(&grafo, 'D', 'F', 9);
  adicionarAresta(&grafo, 'E', 'F', 2);
  adicionarAresta(&grafo, 'E', 'H', 6);
  adicionarAresta(&grafo, 'F', 'H', 3);

  dijkstra(&grafo, 0);
  buscaEmProfundidade(&grafo, 0);

  return 0;
}
