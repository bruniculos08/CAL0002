#include <bits/stdc++.h>
#include "headGraph.h"

using namespace std;

void Graph::addVertice(char name){
  visited.insert(pair<char, bool>(name, false));
  vertice u;
  u.name = name;
  V.insert(pair<char, vertice>(name, u));
}

void Graph::addEdge(char vi, char vj, int weight){
  
  if(V.find(vi) == V.end() || V.find(vj) == V.end()){
    cout << "Vértices inválidos" << endl;
    return;
  }

  V[vi].adjacency_list.push_back(make_pair(vj, weight));
  V[vj].adjacency_list.push_back(make_pair(vi, weight));
}

bool compareTuple(tuple<char, int> a, tuple<char, int> b){
  return get<1>(a) < get<1>(b); 
}

class comparePair
{
public:
    int operator() (pair<char, int> a, pair<char, int> b)
    {
        return a.second > a.second; 
    }
};


// (1) Função para criar um grafo:
Graph createGraph(){
    FILE *filePointer;
    filePointer = fopen("GraphInfo.txt", "rt");
    
    Graph G;
    if(feof(filePointer)) return G;

    // (1.1) Número de vértices:
    int n;
    fscanf(filePointer, "%i\n", &n);

    // (1.2) Lendo lista de vértices:
    char vi, vj; 
    for(int i = 0; i < n-1; i++){
      fscanf(filePointer, "%c ", &vi);
      G.addVertice(vi);
    }
    // (1.3) Lendo último vértice a ser colocado na lista de vértices:
    fscanf(filePointer, "%c\n", &vi);
    G.addVertice(vi);

    // (1.4) Lendo lista de arestas:
    int weight;
    do
    {
      fscanf(filePointer, "%c %c %i\n", &vi, &vj, &weight);
      G.addVertice(vi);
      G.addVertice(vj);
      G.addEdge(vi, vj, weight);
      
    } while (!feof(filePointer));
    
    fclose(filePointer);

    return G;
}

void printGraph(Graph G){
  for(auto v : G.V){
    cout << "vertice " << v.first << " -> ";
    vector<pair<char, int>> adj_list = v.second.adjacency_list;
    for(auto edge : adj_list){
      cout << "(" << edge.first << ":" << edge.second << ") ";
    }
    cout << "\n";
  }
}

// (2) Função para executar o Dijkstra:
void dijkstra(Graph G, char s, char t){
  int inf = __INT32_MAX__;

  // A tabela usada no algoritmo deve conter uma coluna para cada um dos vértices:
  map<char, pair<int, char>> table;

  // A tabela temporário marca se um vértice não precisa mais ser visitado (não é mais temporário):
  // - já está na classe Graph;

  // Se um vértice ainda é temporário, segundo a prova de corretude do algoritmo de Dijkstra, este vértice...
  // ... ainda não tem em sua marca de distância o menor caminho, porém quando se torna permanente (não temporário)...
  // ... a distância computada (salva na tabela) até este vértice será a mínima;

  // A distância até s é 0 o mesmo não tem pai pois é o vértice inicial:
  table.insert(make_pair(s, make_pair(0, '#')));
  // O vértice s é visitado pois é o vértice inicial:
  G.visited[s] = true;

  for(auto v : G.V){
    if(v.first != s) table.insert(make_pair(v.first, make_pair(inf, '#')));
  }

  // A variável z guardará o vértice atual a ser analisado pelo algoritmo:
  char z;
  // Variável auxiliar para guardar distâncias:
  int dist;

  priority_queue<pair<char, int>, vector<pair<char, int>>, comparePair> next;
  next.push(make_pair(s, 0));


  // Enquanto o vetor atual a ser analisado não for o final:
  while(next.size() != 0){
    z = next.top().first;
    next.pop();
    
    for(auto v : G.V[z].adjacency_list){
      // Se a marca do vetor é permanente não se deve analisar o vetor novamente:
      if(G.visited[v.first] == true) continue;

      // Verificando se marca(v) > marca(z) + dist(z,v):
      if(table[v.first].first > table[z].first + v.second){
        dist = table[z].first + v.second;
        // Se a condição for válida muda marca(v) para marca(z) + dist(z,v):
        table[v.first].first = dist;
        // Coloca z como pai de v:
        table[v.first].second = z;

        next.push(make_pair(v.first, dist));
        // printf("alterando pai de '%c' para '%c' e dist(%c) = %i\n", v.first, z, v.first, table[z].first + v.second);
      }
    }
  }

  
  if(table[t].second == '#') cout << "Não há caminho de " << s << " até " << t << "\n";
  else{
    cout << "Printando caminho: "; 
    stack<char> path;
    while(t != '#'){
      path.push(t);
      t = table[t].second;
    }


    while(path.empty() != true){
      cout << path.top() << " ";
      path.pop();
    }
    cout << "\n";
  }


  // Resetando visited:
  for(auto v : G.visited) v.second = false;
}

// (3) Função de busca em largura (que printa o grafo em níveis a partir de um grafo inicial):
void BFS(Graph G, char s){
  std::queue<char> fila;

  char z;
  fila.push(s);
  do{
    z = fila.front();
    fila.pop();
    G.visited[z] = true;
    std::cout << "Vértice " << z << " visitado\n";
    
    for(auto v : G.V[z].adjacency_list){
      if(G.visited[v.first] == false){
        G.visited[v.first] = true;
        fila.push(v.first);     
      }
    }
  } while(fila.empty() == false);

  // Resetando visited:
  for(auto v : G.visited) v.second = false;
}

// (4) Função de busca em profundidade não recursiva:
void DFS(Graph G, char s){
  std::stack<int> pilha;

  char z;
  pilha.push(s);
  do{
    z = pilha.top();
    pilha.pop();
    G.visited[z] = true;
    for(auto v : G.V[z].adjacency_list){
      if(G.visited[v.first] == false){
        G.visited[v.first] = true;
        pilha.push(v.first);
      }
    }
    std::cout << "Vértice " << z << " visitado;" << std::endl;
  } while(pilha.empty() == false);

  // Resetando visited:
  for(auto v : G.visited) v.second = false;
}

// (5) BFS para retornar componete conexa:
vector<char> BFS_component(Graph *G, char s){
  std::queue<char> fila;
  std::vector<char> component;

  char z;
  fila.push(s);
  do{
    z = fila.front();
    fila.pop();
    (*G).visited[z] = true;
    component.push_back(z);
    
    for(auto v : (*G).V[z].adjacency_list){
      if((*G).visited[v.first] == false){
        (*G).visited[v.first] = true;
        fila.push(v.first);     
      }
    }
  } while(fila.empty() == false);

  return component;
}

// (6) DFS para determinar componenete conexa:
vector<char> DFS_component(Graph G, char s){
  std::stack<int> pilha;

  char z;
  pilha.push(s);
  do{
    z = pilha.top();
    pilha.pop();
    G.visited[z] = true;
    for(auto v : G.V[z].adjacency_list){
      if(G.visited[v.first] == false){
        G.visited[v.first] = true;
        pilha.push(v.first);
      }
    }
    std::cout << "Vértice " << z << " visitado;" << std::endl;
  } while(pilha.empty() == false);

  // Resetando visited:
  for(auto v : G.visited) v.second = false;
}

void printOneComponent(vector<char> component){
  cout << "Componente Conexo: ";
  for(char v : component) cout << v << " ";
  cout << "\n";
}

void printComponents(Graph *G){
  for(auto v : (*G).visited){
    if(v.second == false) printOneComponent(BFS_component(G, v.first)); 
  }

  for(auto v : (*G).visited) v.second = false;
}
