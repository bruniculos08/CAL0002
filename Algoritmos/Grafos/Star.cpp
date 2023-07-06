#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Point{
    int x, y;
};

int **createMatrix(int rows, int columns, int filler){

    int **matrix = (int **)malloc(rows*sizeof(int*));

    for(int i=0; i<rows; i++){
        matrix[i] = (int *)malloc(columns*sizeof(int));

        for(int j=0; j<columns; j++) matrix[i][j] = filler;
    }
    return matrix;
}

double **createMatrixDouble(int rows, int columns, double filler){

    double **matrix = (double **)malloc(rows*sizeof(double*));

    for(int i=0; i<rows; i++){
        matrix[i] = (double *)malloc(columns*sizeof(double));

        for(int j=0; j<columns; j++) matrix[i][j] = filler;
    }
    return matrix;
}

Point **createMatrixPoint(int rows, int columns){

    Point filler;
    filler.x = -1;
    filler.x = -1;

    Point **matrix = (Point **)malloc(rows*sizeof(Point*));

    for(int i=0; i<rows; i++){
        matrix[i] = (Point *)malloc(columns*sizeof(Point));

        for(int j=0; j<columns; j++) matrix[i][j] = filler;
    }
    return matrix;
}

int **createGrid(int &n, int &m){
    FILE *filePointer;
    filePointer = fopen("GridInfo.txt", "rt");
    fscanf(filePointer, "%i ", &n);
    fscanf(filePointer, "%i\n", &m);
    
    int **matrix = createMatrix(n, m, 0);

    if(feof(filePointer)) return matrix;

    //cout << n << endl;
    //cout << m << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(feof(filePointer)){
                cout << "Erro" << endl;
                exit(1);
            }

            fscanf(filePointer, "%i ", &matrix[i][j]);
        }
        fscanf(filePointer, "\n");
    }

    fclose(filePointer);
    return matrix;
}

void printMatrix(int **matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) {
            if(matrix[i][j] == 100) cout << "& ";
            else cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printMatrixDouble(double **matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++) printf("%lf ", matrix[i][j]);
        printf("\n");
    }
}

vector<Point> getNeighbors(Point p, int n, int m){
    vector<Point> Neighborhood;
    for(int i = p.y-1; i <= p.y + 1; i++){
        for(int j = p.x-1; j <= p.x + 1; j++){
            if((i != p.y || j != p.x) && (i >= 0 && i <= n-1) && (j >= 0 && j <= m-1)){
                Point v;
                v.x = j;
                v.y = i;
                Neighborhood.push_back(v);
            }
        }
    }
    return Neighborhood;
}

double getDistance(int **Grid, Point current, Point neighboor){
    if(Grid[neighboor.y][neighboor.x] == 1) return DBL_MAX;
    return sqrt( powf( (float) current.x - neighboor.x, 2) + powf( (float) current.y - neighboor.y, 2) );
}

class compareTable{
    public:
        int operator() (tuple<Point, double> p1, tuple<Point, double> p2){
            return get<1>(p1) > get<1>(p2); 
        }
};

Point **Dijkstra(int **Grid, int n, int m, Point start, Point target){
    
    int **Visited = createMatrix(n, m, 0);
    double **Cost = createMatrixDouble(n, m, DBL_MAX);
    Point **Fathers = createMatrixPoint(n, m);
    
    Visited[start.y][start.x] = 1;
    Cost[start.y][start.x] = 0;
    Fathers[start.y][start.x] = start;

    Point current;
    current.x = start.x;
    current.y = start.y;

    // (1) Heap Min de tuplas com ponto e custo:
    priority_queue<tuple<Point, double>, vector<tuple<Point, double>>, compareTable> Next;
    Next.push(make_tuple(start, 0));

    vector<Point> Neighborhood;

    while(Next.size() > 0){

        current = get<0>(Next.top());
        Next.pop();

        Visited[current.y][current.x] = 1;

        if(current.x == target.x && current.y == target.y) break;

        Neighborhood = getNeighbors(current, n, m);
        
        for(Point p : Neighborhood){

            if(Visited[p.y][p.x] == 1) continue;
        
            if(Cost[p.y][p.x] > Cost[current.y][current.x] + getDistance(Grid, current, p)){

                double dist = Cost[current.y][current.x] + getDistance(Grid, current, p);

                Cost[p.y][p.x] = dist;

                Fathers[p.y][p.x] = current;

                Next.push(make_tuple(p, Cost[p.y][p.x]));
            }
        }
    }

    cout << "Visited in Dijkstra:" << endl;
    printMatrix(Visited, n, m);
    cout << "Best Path (Dijkstra) = " << Cost[target.y][target.x] << endl;
    return Fathers;
} 

double manhattanDistance(Point p1, Point p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

Point **Star(int **Grid, int n, int m, Point start, Point target){
    
    int **Visited = createMatrix(n, m, 0);
    double **Cost = createMatrixDouble(n, m, DBL_MAX);
    Point **Fathers = createMatrixPoint(n, m);
    
    Visited[start.y][start.x] = 1;
    Cost[start.y][start.x] = 0;
    Fathers[start.y][start.x] = start;

    Point current;
    current.x = start.x;
    current.y = start.y;

    // (1) Heap Min de tuplas com ponto e custo:
    priority_queue<tuple<Point, double>, vector<tuple<Point, double>>, compareTable> Next;
    Next.push(make_tuple(start, 0));

    vector<Point> Neighborhood;

    while(Next.size() > 0){

        current = get<0>(Next.top());
        Next.pop();

        Visited[current.y][current.x] = 1;

        if(current.x == target.x && current.y == target.y) break;

        Neighborhood = getNeighbors(current, n, m);
        
        for(Point p : Neighborhood){

            if(Visited[p.y][p.x] == 1) continue;
        
            if(Cost[p.y][p.x] > Cost[current.y][current.x] + getDistance(Grid, current, p)){

                double dist = Cost[current.y][current.x] + getDistance(Grid, current, p);

                Cost[p.y][p.x] = dist;

                Fathers[p.y][p.x] = current;

                Next.push(make_tuple(p, Cost[p.y][p.x] +  manhattanDistance(p, target)));
            }
        }
    }

    cout << "Visited in A*:" << endl;
    printMatrix(Visited, n, m);
    cout << "Best Path (A*) = " << Cost[target.y][target.x] << endl;
    return Fathers;
} 

void printPath(int **Grid, Point **Fathers, Point start, Point target){
    vector<Point> Path;
    Point current = target;

    Path.push_back(target);
    while((current.x != -1 || current.y != -1) && (current.x != start.x || current.y != start.y)){
        Grid[current.y][current.x] = 100;
        current = Fathers[current.y][current.x];
        Path.push_back(current);
    }
    Grid[current.y][current.x] = 100;

   // for(int i = Path.size()-1; i >= 0; i--) cout << "(" << Path[i].x << ", " << Path[i].y << ")" << endl;
}

int main(void){

    int n, m;
    int **Grid = createGrid(n, m);
    int **PathGrid;

    Point start, target;
    start.x = 0; start.y = 3;
    target.x = 9; target.y = 0;

    PathGrid = createGrid(n, m);
    Point **Fathers = Dijkstra(Grid, n, m, start, target);
    printPath(PathGrid, Fathers, start, target);
    printMatrix(PathGrid, n, m);
    free(PathGrid);

    cout << endl;

    PathGrid = createGrid(n, m);
    Fathers = Star(Grid, n, m, start, target);
    printPath(PathGrid, Fathers, start, target);
    printMatrix(PathGrid, n, m);
    free(PathGrid);
}