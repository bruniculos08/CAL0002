int **createMatrix(int rows, int columns);
int **createGraph(int *n);

int degree(int i, int **matrix, int n);
int **removeEdges(int **matrix, int n);
int **removeVertice(int **matrix, int *n);

void loops(int **matrix, int n);
void multipleEdges(int **matrix, int n);
void isolatedVertices(int **matrix, int n);

void maximumOfEdges(int **matrix, int n);
void numberOfEdges(int **matrix, int n);
void degreeSum(int **matrix, int n);
void handShake(int **matrix,int n);

void tour(int **matrix, int n, int c);
void regularGraph(int **matrix,int n);
void simpleGraph(int **matrix,int n);
void completeGraph(int **matrix,int n);

void printMatrix(int **matrix, int rows, int columns);
void saveGraph(int **matrix, int n);

void dijkstra(int **matrix, int n, int s, int t);
int getMinIndex(int **tabela, int *temporarios, int n);