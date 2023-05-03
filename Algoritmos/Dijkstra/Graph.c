#include <stdio.h>
#include <stdlib.h>
#include "headGraph.h"
// gcc Graph.c headGraph.c -o Graph && ./Graph

int main() {
  int n = 0;
  int **matrix = createGraph(&n);
  int p, c;
  int s, t;
  do {
    do {
      printf("\n[1]: Imprimir matriz de adjacências");
      printf("\n[2]: Verificar Laços");
      printf("\n[3]: Verificar Grau de cada vértice");
      printf("\n[4]: Verificar Vértices Isolados");
      printf("\n[5]: Verificar Teorema das Arestas");
      printf("\n[6]: Verificar Arestas Múltiplas");
      printf("\n[7]: Exibir vértices, número de nós e arestas");
      printf("\n[8]: Exibir soma de todos os graus dos vértices");
      printf("\n[9]: Exibir número de vértices com grau ímpar");
      printf("\n[10]: Exibir o passeio de um vértice");
      printf("\n[11]: Verificar se o grafo é simples");
      printf("\n[12]: Verificar se o grafo é completo");
      printf("\n[13]: Verificar se o grafo é regular");
      printf("\n[14]: Remover arestas");
      printf("\n[15]: Remover um vértice");
      printf("\n[16]: Salvar grafo");
      printf("\n[16]: Salvar grafo");
      printf("\n[17]: Dijkstra");
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
      loops(matrix, n);
      break;
    case 3:
      for (int i = 0; i < n; i++) {
        printf("Grau de v[%i] = %i\n", i + 1, degree(i, matrix, n));
      }
      fflush(stdin);
      break;
    case 4:
      isolatedVertices(matrix, n);
      break;
    case 5:
      maximumOfEdges(matrix, n);
      break;
    case 6:
      multipleEdges(matrix, n);
      printf("\n");
      break;
    case 7:
      numberOfEdges(matrix, n);
      break;
    case 8:
      degreeSum(matrix, n);
      break;
    case 9:
      handShake(matrix, n);
      break;
    case 10:
      printf("\nInsira o tamanho do passeio:\n");
      scanf("%i", &c);
      if (c <= 0) {
        printf("\nCaminho nulo\n");
      }
      tour(matrix, n, c);
      break;
    case 11:
      simpleGraph(matrix, n);
      break;
    case 12:
      completeGraph(matrix, n);
      break;
    case 13:
      regularGraph(matrix, n);
      for (int i = 0; i < n; i++) printf("Grau de v[%i] = %i\n", i + 1, degree(i, matrix, n));
      break;
    case 14:
      matrix = removeEdges(matrix, n);
      break;
    case 15:
      matrix = removeVertice(matrix, &n);
      n--;
      break;
    case 16:
      saveGraph(matrix, n);
      break;
    case 17:
        printf("Digite o vértice inicial: ");
        scanf("%i", &s); 
        printf("Digite o vértice final: ");
        scanf("%i", &t);
        if(s > n || t > n || s <= 0 || t <= 0) printf("Vértice inválido.\n");
        else dijkstra(matrix, n, s, t);
        break;
    }
    fflush(stdin);
  } while (p != 0);

  printf("\nObrigado por usar nosso programa !!\n");
}