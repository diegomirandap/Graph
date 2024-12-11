#ifndef AUX_H
#define AUX_H

#define MAX_VERTICES 10

typedef struct no {
  char vertice;
  int peso;
  struct no* prox;
} No;

typedef struct lista {
  No* head;
} Lista;

typedef struct grafo {
  char vertices[MAX_VERTICES];
  Lista adj[MAX_VERTICES];
  int numVertices;
} Grafo;

void inicializarGrafo(Grafo* grafo, int numVertices, char* vetVertices);

void adicionarAresta(Grafo* grafo, char origem, char destino, int peso);

int distanciaMinima(int vetDistancias[], int vetVisitados[], int numVertices);

void dijkstra(Grafo* grafo, int vInicial);

void profundidadeRecursivo(Grafo* grafo, int vertice, int visitados[]);

void buscaEmProfundidade(Grafo* grafo, int vInicial);

#endif 
