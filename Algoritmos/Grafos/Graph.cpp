#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "headGraph.h"
// g++ Graph.cpp headGraph.cpp -o Graph && ./Graph

using namespace std;

int main() {
  Graph G = createGraph();
  char vi, vj;
  int p;
  do {
    do {
      cout << "\n[1]: Imprimir lista de adjacências";
      cout << "\n[2]: Dijkstra";
      cout << "\n[3]: BFS";
      cout << "\n[4]: DFS";
      cout << "\n[5]: Encontrar todos os componentes conexos via BFS";
      cout << "\n[6]: Encontrar todos os componentes conexos via DFS";
      cout << "\n[0]: Sair\n";
      cin >> p;
      system("clear");
    } while (p < 0 || p > 17);

    switch (p) {
    case 1:
      printGraph(G);
      break;
    case 2:
        cout << "Digite o vértice inicial: ";
        cin >> vi;
        cout << "Digite o vértice final: ";
        cin >> vj;
        dijkstra(G, vi, vj);
        break;
    case 3:
        cout << "Digite o vértice inicial: ";
        cin >> vi;
        BFS(G, vi);
        break;
    case 4:
        cout << "Digite o vértice inicial: ";
        cin >> vi;
        DFS(G, vi);
        break;
    case 5:
        printComponentsBFS(G);
        for(auto v : G.visited) v.second = false;
        break;
    case 6:
        printComponentsDFS(G);
        for(auto v : G.visited) v.second = false;
        break;
    }
    fflush(stdin);
  } while (p != 0);
}