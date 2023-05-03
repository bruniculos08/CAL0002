#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include "headGraph.h"

// (0) Função para criar uma matriz qualquer:
int **createMatrix(int rows, int columns){

    // (1) Alocando os ponteiros para as linhas da matriz:
    // - o ponteiro de ponteiro aponta para um espaço a partir de onde há um número rows de ponteiros para int's
    int **matrix = (int **)malloc(rows*sizeof(int*));

    // (2) Alocando os ponteiros para as colunas da matriz:
    // - cada ponteiro para int aponta para um espaço a partir de onde há um número columns de int's
    for(int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(columns*sizeof(int));

        // (2.1) Setando os elementos da matriz iguais à zero para inserção (por meio de adição) das arestas na função createGraph:
        for(int j=0; j<columns; j++) matrix[i][j] = -1;
    }
    return matrix;
}

// (1) Função para criar um grafo (utilizando a função "createMatrix"):
int **createGraph(int *n){
    FILE *filePointer;
    filePointer = fopen("GraphInfo.txt", "rt");
    fscanf(filePointer, "%i \n", n); 
    
    // (1.1) Criando a matriz de adjacência do grafo:
    int **matrix = createMatrix(*n, *n);

    if(feof(filePointer)) return matrix;

    // (1.2) Loop de acordo para inserir as arestas:
    int i, j, weight;
    do
    {
      // (1.2.1) Ler linha de aresta e pular para a próxima linha do arquivo:
      fscanf(filePointer, "%i %i %i\n", &i, &j, &weight);

      // (1.2.2) Há a adição nos elementos simétricos da matriz (tendo em vista que a matriz é simétrica):
      if(i != j){
          matrix[i-1][j-1] = weight;
          matrix[j-1][i-1] = weight;
      }
      else matrix[i-1][j-1] = weight;
      
    } while (!feof(filePointer));
    fclose(filePointer);
    return matrix;
}

// (2) Função para salvar o grafo (atualmente sendo executado pelo programa) em um arquivo de texto:
void saveGraph(int **matrix, int n){
    remove("GraphInfo.txt");
    FILE *filePointer;
    filePointer = fopen("GraphInfo.txt", "w+");
    fprintf(filePointer, "%i", n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = 0; k < matrix[i][j]; k++){
                fprintf(filePointer, "\n%i %i", i+1, j+1);
            }
        }
    }
    fclose(filePointer);
}

// (3) Função para imprimir a matriz:
void printMatrix(int **matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) printf("%i ", matrix[i][j]);
        printf("\n");
    }
}


// (4) Função para remover um vértice (e por consequência todas as arestas ligadas ao mesmo) de um grafo:
// - Pode se dizer que o grafo é transformado em um subgrafo induzido pelos vértices existentes anteriormente, exceto pelo vértice removido.
int **removeVertice(int **matrix, int *n){
    int m = (*n) - 1;
    int indice;
    printf("Digite o número do vértice que se deseja remover: ");
    scanf("%i", &indice);
    int **newMatrix = createGraph(&m);
    for(int i = 0, k = 0; i < *n && k < m-1; i++){
        if(i == indice-1) i++;
        for(int j = 0, l = 0; j < *n && l < m-1; j++){
            if(j == indice-1) j++;
            newMatrix[k][l] = matrix[i][j];
            l++;
        }
        k++;
    }
    return newMatrix;
}

// (5) Função para remover uma aresta do grafo:
int **removeEdges(int **matrix, int n){
    int r, i, j;
    printf("Digite o número de arestas a serem removidas: ");
    scanf("%i", &r);
    for(int k = 0; k < r; k++){
        printf("Digite uma aresta a ser removida: ");
        do {
            scanf("%i %i", &i, &j);
        } while(i > n || j > n);
        if(matrix[i-1][j-1] > 0) matrix[i-1][j-1] --;
        matrix[j-1][i-1] = matrix[i-1][j-1];
    }
    return matrix;
}

// (6) Função para executar o Dijkstra:
void dijkstra(int **matrix, int n, int s, int t){
  int inf = __INT32_MAX__;
    
  printf("Running Dijkstra...\n");
  // Obs.: como meu código inteiro está utilizando a numeração dos vetores como iniciando em 1 esta parte...
  // ... do código está seguindo o mesmo padrão;

  // A tabela usada no algoritmo deve conter uma coluna para cada um dos vértices:
  int **tabela;
  tabela = (int**)malloc(sizeof(int*)*n);

  // A tabela temporário marca se um vértice não precisa mais ser visitado (não é mais temporário):
  int *temporarios;
  temporarios = (int*)malloc(sizeof(int)*n);
  // Se um vértice ainda é temporário, segundo a prova de corretude do algoritmo de Dijkstra, este vértice...
  // ... ainda não tem em sua marca de distância o menor caminho, porém quando se torna permanente (não temporário)...
  // ... a distância computada (salva na tabela) até este vértice será a mínima;
  
  // Este loop é O(V):
  for(int i = 0; i < n; i++){
    // Para cada vértice na tabela há 2 items (1 descreve a distância até o vértice e outro...
    // ... descreve o pai deste vértice):
    tabela[i] = (int*)malloc(sizeof(int)*2);
    
    // Se não estamos no vértice inicial:
    if(i != s-1){
      // A distância até o vértice vi é inicialmente infinita (vértice não alcançado): 
      tabela[i][0] = inf;
      // O pai do vértice ainda não alcançado não existe:
      tabela[i][1] = -1;
      // Marca todos os vértices como temporários (1 == TRUE, 0 == FALSE):
      temporarios[i] = 1;
    }
  }

  // A distância até s é 0 pois s é o vértice inicial:
  tabela[0][0] = 0;
  // O vértice s não tem pai pois ele é o vértice inicial:
  tabela[0][1] = -1;
  // O vértice s é visitado pois é o vértice inicial:
  temporarios[s-1] = 0;

  // A variável z guardará o vetor atual a ser analisado pelo algoritmo:
  int z = s;
  // Variável auxiliar para guardar o número de um vértice (apenas por organização):
  int v;

  // Enquanto o vetor atual a ser analisado não for o final:
  while(z != t && z != -1){
    printf("Running Dijkstra (z = %i)...\n", z);
    for(int i = 0; i < n; i++){
      // Se a marca do vetor é permanente não se deve analisar o vetor novamente:
      if(temporarios[i] == 0) continue;
      
      v = i+1;
      
      // Verificando se marca(v) > marca(z) + dist(z,v):
      if(matrix[z-1][v-1] != -1 && tabela[v-1][0] > tabela[z-1][0] + matrix[z-1][v-1]){
        // Se a condição for válida muda marca(z) para marca(z) + dist(z,v):
        tabela[v-1][0] = tabela[z-1][0] + matrix[z-1][v-1];
        // Coloca z como pai de v:
        tabela[v-1][1] = z;
      }
    }
    // Troca z para o vértice com menor marca (menor distância a partir de s computada):
    z = getMinIndex(tabela, temporarios, n) + 1;
    // Tira este vértice do temporários pois o mesmo será analisado na próxima iteração do loop: 
    temporarios[z-1] = 0;
  }

  // Imprimindo caminho na ordem inversa:
  printf("Printando caminho (ordem inversa): ");
  while(t != -1){
    printf("%i ", t);
    t = tabela[t-1][1];
  }
  printf("\n");
  
}

// (7) Função para buscar o vértice com menor marca da lista da tabela do algoritmo de Dijkstra:
int getMinIndex(int **tabela, int *temporarios, int n){
    int minIndex = -1;
    for(int i = 0; i < n; i++){
      if((minIndex == -1 || tabela[minIndex][0] > tabela[i][0]) && temporarios[i] == 1) 
        minIndex = i;
    }
    return minIndex;
}

// (8) Função de busca em largura (que printa o grafo em níveis a partir de um grafo inicial):
void BFS(int **matrix, int n, int s){
  std::stack<int> pilha;
  std::vector<bool> visitados(n);
  for(int i = 0; i < n; i++){
    visitados[i] = false;
  }

  int z = s;
  do{
    visitados[z-1] = true;
    pilha.pop();
    for(int i = 0; i < n; i++){
      if(visitados[i] == false && matrix[z-1][i] >= 0){
        std::cout << "Vértice " << i+1 << " visitado;" << std::endl;
        visitados[i] = true;
        pilha.push(i+1);     
      }
    }
    z = pilha.top();
  } while(pilha.size() != -1);
}

// (9) Função de busca em profundidade não recursiva:
void DFS(int **matrix, int n, int s){
  std::stack<int> pilha;
  std::vector<bool> visitados(n);
  for(int i = 0; i < n; i++){
    visitados[i] = false;
  }

  int z = s;
  do{
    pilha.pop();
    visitados[z-1] = true;
    for(int i = 0; i < n; i++){
      if(visitados[i] == false && matrix[z-1][i] >= 0){
        //std::cout << "Vértice " << i+1 << " visitado;" << std::endl;
        visitados[i] = true;
        pilha.push(z);
        z = i+1;
        i = 0;     
      }
    }
    std::cout << "Vértice " << z << " visitado;" << std::endl;
    z = pilha.top();
  } while(pilha.size() != -1);

}