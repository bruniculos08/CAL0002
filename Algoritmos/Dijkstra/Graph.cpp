#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"
// g++ Graph.cpp headGraph.cpp -o Graph && ./Graph

using namespace std;

int main() {
  Graph G = createGraph();
  char vi, vj;
  int p;
  do {
    do {
      printf("\n[1]: Imprimir lista de adjacências");
      printf("\n[2]: Dijkstra");
      printf("\n[3]: BFS");
      printf("\n[4]: DFS");
      printf("\n[5]: Encontrar todos os componentes conexos via BFS");
      printf("\n[0]: Sair\n\n");
      scanf("%i", &p);
      system("clear");
    } while (p < 0 || p > 17);

    switch (p) {
    case 1:
      printGraph(G);
      printf("\n");
      break;
    case 2:
        fflush(stdin);
        printf("Digite o vértice inicial: ");
        cin >> vi;
        printf("Digite o vértice final: ");
        cin >> vj;
        dijkstra(G, vi, vj);
        break;
    case 3:
        printf("Digite o vértice inicial: ");
        cin >> vi;
        BFS(G, vi);
        break;
    case 4:
        printf("Digite o vértice inicial: ");
        cin >> vi;
        DFS(G, vi);
        break;
    case 5:
        printComponents(&G);
        break;
    }
    fflush(stdin);
  } while (p != 0);
}