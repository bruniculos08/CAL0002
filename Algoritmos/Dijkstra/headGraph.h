#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct vertice{
  char name;
  vector<pair<char, int>> adjacency_list;
};

class Graph{
  public:
    map<char, bool> visited;
    map<char, vertice> V;

    void addVertice(char name);
    void addEdge(char vi, char vj, int weight);
};

Graph createGraph();
void printGraph(Graph G);


void dijkstra(Graph G, char s, char t);
void BFS(Graph G, char s);
void DFS(Graph G, char s);
vector<char> BFS_component(Graph G, char s);
vector<char> DFS_component(Graph G, char s);

void printComponentsBFS(Graph G);
void printComponentsDFS(Graph G);
void printOneComponent(vector<char> component);
bool compareTuple(tuple<char, int> a, tuple<char, int> b);