#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"
// g++ Graph.cpp headGraph.cpp -o Graph && ./Graph

int main() {
  int n = 0;
  int **matrix = createGraph(&n);
  int p, c;
  int s, t;
  do {
    do {
      printf("\n[1]: Imprimir matriz de adjacências");
      printf("\n[2]: Remover arestas");
      printf("\n[3]: Remover um vértice");
      printf("\n[4]: Salvar grafo");
      printf("\n[5]: Dijkstra");
      printf("\n[6]: BFS");
      printf("\n[7]: DFS");
      printf("\n[0]: Sair\n\n");
      scanf("%i", &p);
      system("clear");
    } while (p < 0 || p > 17);

    switch (p) {
    case 1:
      printf("\n");
      printMatrix(matrix, n, n);
      break;
    case 2:
      matrix = removeEdges(matrix, n);
      break;
    case 3:
      matrix = removeVertice(matrix, &n);
      n--;
      break;
    case 4:
      saveGraph(matrix, n);
      break;
    case 5:
        printf("Digite o vértice inicial: ");
        scanf("%i", &s); 
        printf("Digite o vértice final: ");
        scanf("%i", &t);
        if(s > n || t > n || s <= 0 || t <= 0) printf("Vértice inválido.\n");
        else dijkstra(matrix, n, s, t);
        break;
    case 6:
        printf("Digite o vértice inicial: ");
        scanf("%i", &s); 
        if(s > n || s <= 0) printf("Vértice inválido.\n");
        else BFS(matrix, n, s);
        break;
    case 7:
        printf("Digite o vértice inicial: ");
        scanf("%i", &s); 
        if(s > n || s <= 0) printf("Vértice inválido.\n");
        else DFS(matrix, n, s);
        break;
    }
    fflush(stdin);
  } while (p != 0);

  printf("\nObrigado por usar nosso programa !!\n");
}