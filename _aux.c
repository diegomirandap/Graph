#include "aux.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void inicializarGrafo(Grafo* grafo, int numVertices, char* vetVertices) {
  grafo->numVertices = numVertices;

  for (int i = 0; i < numVertices; i++) {
    char vertice = vetVertices[i];
    grafo->vertices[i] = vertice;
    grafo->adj[i].head = NULL;
  }
}

int indiceVertice(char vertice, Grafo* grafo) {
  for (int i = 0; i < grafo->numVertices; i++) {
    if (grafo->vertices[i] == vertice) {
      return i;
    }
  }
  return -1;
}

void adicionarAresta(Grafo* grafo, char origem, char destino, int peso) {
  int indiceOrigem, indiceDestino;

  indiceOrigem = indiceVertice(origem, grafo);
  indiceDestino = indiceVertice(destino, grafo);

  if (indiceOrigem == -1 || indiceDestino == -1) {
    return;
  }

  No* novo = (No*)malloc(sizeof(No));
  novo->vertice = destino;
  novo->peso = peso;
  novo->prox = NULL;

  // Insere em primeiro o último a ter sido adicionado
  if (grafo->adj[indiceOrigem].head == NULL) {
    grafo->adj[indiceOrigem].head = novo;
  } else {
    novo->prox = grafo->adj[indiceOrigem].head;
    grafo->adj[indiceOrigem].head = novo;
  }
}

int distanciaMinima(int vetDistancias[], int vetVisitados[], int numVertices) {
  int minDistancia = INT_MAX;
  int minVertice = -1;

  for (int i = 0; i < numVertices; i++) {
    if (vetVisitados[i] == 0 && vetDistancias[i] <= minDistancia) {
      minDistancia = vetDistancias[i];
      minVertice = i;
    }
  }

  return minVertice;
}

void dijkstra(Grafo* grafo, int vInicial) {
  int i, vetDistancias[MAX_VERTICES], vetVisitados[MAX_VERTICES];

  for (i = 0; i < grafo->numVertices; i++) {
    vetDistancias[i] = INT_MAX;
    vetVisitados[i] = 0;
  }

  vetDistancias[vInicial] = 0;

  for (i = 0; i < grafo->numVertices; i++) {
    int vAtual = distanciaMinima(vetDistancias, vetVisitados, grafo->numVertices);
    vetVisitados[vAtual] = 1;

    No* noAdjacente = grafo->adj[vAtual].head;
    while (noAdjacente != NULL) {
      int adjacentVertex = indiceVertice(noAdjacente->vertice, grafo);
      int edgeWeight = noAdjacente->peso;

      if (vetVisitados[adjacentVertex] == 0 && edgeWeight != 0 &&
          vetDistancias[vAtual] != INT_MAX &&
          vetDistancias[vAtual] + edgeWeight < vetDistancias[adjacentVertex]) {
        vetDistancias[adjacentVertex] = vetDistancias[vAtual] + edgeWeight;
      }

      noAdjacente = noAdjacente->prox;
    }
  }

  printf("Menores distancias para o vertice %c:\n", grafo->vertices[vInicial]);

  for (int i = 0; i < grafo->numVertices; i++) {
    printf("%c: ", grafo->vertices[i]);
    if (vetDistancias[i] == INT_MAX) {
      printf("Infinito\n");
    } else {
      printf("%d\n", vetDistancias[i]);
    }
  }
}

void profundidadeRecursivo(Grafo* grafo, int vertice, int visitados[]) {
  visitados[vertice] = 1;
  printf("%c\n", grafo->vertices[vertice]);

  No* adjacentNode = grafo->adj[vertice].head;
  while (adjacentNode != NULL) {
    int adjacentVertex = indiceVertice(adjacentNode->vertice, grafo);
    if (visitados[adjacentVertex] == 0) {
      profundidadeRecursivo(grafo, adjacentVertex, visitados);
    }
    adjacentNode = adjacentNode->prox;
  }
}

void buscaEmProfundidade(Grafo* grafo, int vInicial) {
  int visited[MAX_VERTICES];
  for (int i = 0; i < grafo->numVertices; i++) {
    visited[i] = 0;
  }

  printf("Caminho da busca em profundidade a partir de %c:\n", grafo->vertices[vInicial]);
  profundidadeRecursivo(grafo, vInicial, visited);
}
