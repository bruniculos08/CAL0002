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

  // (2.1) A tabela usada no algoritmo deve conter uma coluna para cada um dos vértices:
  map<char, pair<int, char>> table;
  // Complexidade O(1) 

  // A tabela visited marca se um vértice não precisa mais ser visitado (não é mais temporário) e já está na classe Graph;

  // Se um vértice ainda é temporário, segundo a prova de corretude do algoritmo de Dijkstra, este vértice...
  // ... ainda não tem em sua marca de distância o menor caminho, porém quando se torna permanente (não temporário)...
  // ... a distância computada (salva na tabela) até este vértice será a mínima;

  // (2.2) A distância até s é 0 o mesmo não tem pai pois é o vértice inicial:
  table.insert(make_pair(s, make_pair(0, '#')));
  // Complexidade O(log|V|)

  // (2.3) O vértice s é visitado pois é o vértice inicial:
  G.visited[s] = true;
  // Complexidade O(log|V|)

  // (2.4) Inserindo os vértices em table:
  for(auto v : G.V){
    if(v.first != s) table.insert(make_pair(v.first, make_pair(inf, '#')));
    // Complexidade O(log|V|)
  }
  // Complexidade O(|V|.log|V|)

  // A variável z guardará o vértice atual a ser analisado pelo algoritmo:
  char z;
  // Variável auxiliar para guardar distâncias:
  int dist;

  // (2.5) Criando a Heap:
  priority_queue<pair<char, int>, vector<pair<char, int>>, comparePair> next;
  next.push(make_pair(s, 0));
  // Complexidade O(log|V|)

  // (2.6) Enquanto o vetor atual a ser analisado não for o final:
  while(next.size() != 0){
  // Complexidade da verificação O(1) e do "while", no pior caso, passaremos por todos os vértices...
  // ... portanto é O(|V|)

    z = next.top().first;
    // Complexidade O(1)
    next.pop();
    // Complexidade O(log|V|)
    
    // (2.6.1) Verificando todos os vizinhos de z:
    for(auto v : G.V[z].adjacency_list){
    // Complexidade do acesso á V[z] é O(log|V|)

      // (2.6.1.1) Se a marca do vetor é permanente não se deve analisar o vetor novamente:
      if(G.visited[v.first] == true) continue;
      // Complexidade O(log|V|)

      // (2.6.1.2) Verificando se marca(v) > marca(z) + dist(z,v):
      if(table[v.first].first > table[z].first + v.second){
        // Complexidade O(log|V|)

        dist = table[z].first + v.second;
        // Complexidade O(log|V|)
        
        // Se a condição for válida muda marca(v) para marca(z) + dist(z,v):
        table[v.first].first = dist;
        // Complexidade O(log|V|)
        
        // Coloca z como pai de v:
        table[v.first].second = z;
        // Complexidade O(log|V|)

        next.push(make_pair(v.first, dist));
        // Complexidade O(log|V|)
      }
    }
    // Como para cada vértice z o número de rodadas deste for-loop é d(z), isto é, o grau do vértice z, se passarmos por...
    // ... todos os vértices teremos como custo a soma dos graus de todos os vértices, o que pelo teorema do aperto de...
    // ...  mãos resulta em 2|E|, mas como em cada rodada há um número constante de acessos a um estrtura map, o que tem...
    // ... custo O(log|V|) a complexidade deste for-loop é então O(|E|.log|V|)
  }
  // A complexidade deste while-loop é O(|E|.log|V| + |V|.log|V|) pois O(|E|.log|V|) é o custo de rodadas do for-loop e...
  // ... O(|V|.log|V|) é o custo das rodadas do while-loop pois este tem O(|V|) rodadas e a cada rodada há um número constante...
  // ... de acessos a estruturas map cuja complexidade de acesso é O(log|V|)

  
  // (2.7) Verifica se o caminho foi encontrado e impreme:
  if(table[t].second == '#') cout << "Não há caminho de " << s << " até " << t << "\n";
  // Complexidade O(log|V|)
  else{
    cout << "Printando caminho: "; 
    stack<char> path;
    // (2.7.1) Coloca o caminho na pilha:
    while(t != '#'){
      path.push(t);
      // Complexidade O(1)
      t = table[t].second;
      // Complexidade O(log|V|)
    }
    // Complexidade O(log|V|)

    // (2.8) Imprimindo o caminho:
    while(path.empty() != true){
      cout << path.top() << " ";
      path.pop();
    }
    // Complexidade O(|V|)
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
    // Complexidade O(log|V|)

    std::cout << "Vértice " << z << " visitado\n";
    
    for(auto v : G.V[z].adjacency_list){
    // Complexidade para acesso O(log|V|)
      if(G.visited[v.first] == false){
        G.visited[v.first] = true;
        fila.push(v.first);     
      }
    }
    // Complexidade (justificativa semelhante a do Dijkstra) O(|E|.log|V|)
  } while(fila.empty() == false);
  // Complexidade O(|V|.log|V| + |E|.log|V|)


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
    // Complexidade O(log|V|)

    // Complexidade O(log|V|)
    for(auto v : G.V[z].adjacency_list){
      if(G.visited[v.first] == false){
        G.visited[v.first] = true;
        pilha.push(v.first);
      }
    }
    std::cout << "Vértice " << z << " visitado;" << std::endl;
    // Complexidade O(|E|.log|V|)
  } while(pilha.empty() == false);
  // Complexidade O(|V|.log|V| + |E|.log|V|)

  // Resetando visited:
  for(auto v : G.visited) v.second = false;
  // Complexidade O(|V|)
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
vector<char> DFS_component(Graph *G, char s){
  std::stack<char> pilha;
  std::vector<char> component;

  char z;
  pilha.push(s);
  do{
    z = pilha.top();
    pilha.pop();
    (*G).visited[z] = true;
    for(auto v : (*G).V[z].adjacency_list){
      if((*G).visited[v.first] == false){
        (*G).visited[v.first] = true;
        pilha.push(v.first);
      }
    }
    component.push_back(z);
  } while(pilha.empty() == false);

  return component;
}

void printOneComponent(vector<char> component){
  cout << "Componente Conexo: ";
  for(char v : component) cout << v << " ";
  cout << "\n";
}

void printComponentsBFS(Graph G){
  for(auto v : (G).visited){
    if(v.second == false) printOneComponent(BFS_component(&G, v.first)); 
  }

  for(auto v : (G).visited) v.second = false;
}

void printComponentsDFS(Graph G){
  for(auto v : (G).visited){
    if(v.second == false) printOneComponent(DFS_component(&G, v.first)); 
  }

  for(auto v : (G).visited) v.second = false;
}
