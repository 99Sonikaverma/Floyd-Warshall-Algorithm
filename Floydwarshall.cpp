// Floyd-Warshall Algorithm in C++
#include <iostream>
using namespace std;
// defining the number of vertices
#define nVertex 4

#define INFINITY 999

void printMatrix(int matrix[][nVertex]);

// Implementing floyd warshall algorithm
void floydWarshall(int graphs[][nVertex]) {
  int matrix[nVertex][nVertex], i, j, k;

  for (i = 0; i < nVertex; i++)
    for (j = 0; j < nVertex; j++)
      matrix[i][j] = graphs[i][j];

  // Adding vertices individually
  for (k = 0; k < nVertex; k++) {
    for (i = 0; i < nVertex; i++) {
      for (j = 0; j < nVertex; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nVertex]) {
  for (int i = 0; i < nVertex; i++) {
    for (int j = 0; j < nVertex; j++) {
      if (matrix[i][j] == INFINITY)
        printf("%4s", "INFINITY");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graphs[nVertex][nVertex] = {{0, 3, INFINITY, 5},
             {2, 0, INFINITY, 4},
             {INFINITY, 1, 0, INFINITY},
             {INFINITY, INFINITY, 2, 0}};
  floydWarshall(graphs);
}
