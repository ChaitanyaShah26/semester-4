#include <stdio.h>
#include <conio.h>

#define MAX_NODES 100
#define INF 1000  

int min(int a, int b) 
{
    return a < b ? a : b;
}

void printMatrix(int dist[MAX_NODES][MAX_NODES], int n) 
{
    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (dist[i][j] == INF) 
            {
                printf("INF\t");
            } 
            else 
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[MAX_NODES][MAX_NODES], int n) 
{
    int dist[MAX_NODES][MAX_NODES];
    int i, j, k;

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (i == j) 
            {
                dist[i][j] = 0;
            } 
            else if (graph[i][j] != INF) 
            {
                dist[i][j] = graph[i][j];
            } 
            else 
            {
                dist[i][j] = INF;
            }
        }
    }

    for (k = 0; k < n; k++) 
    {
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n; j++) 
            {
                if (dist[i][k] != INF && dist[k][j] != INF) 
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    printMatrix(dist, n);
}

void main() 
{
    int n, i, j;
    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for self-loops and 99 for no edge):\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
            if (i != j && graph[i][j] == 99) 
            {
                graph[i][j] = INF;
            }
        }
    }

    floydWarshall(graph, n);

    getch();
}
