int **createMatrix(int rows, int columns);
int **createGraph(int *n);

int **removeEdges(int **matrix, int n);
int **removeVertice(int **matrix, int *n);

void printMatrix(int **matrix, int rows, int columns);
void saveGraph(int **matrix, int n);

void dijkstra(int **matrix, int n, int s, int t);
int getMinIndex(int **tabela, int *temporarios, int n);

void BFS(int **matrix, int n, int s);
void DFS(int **matrix, int n, int s);