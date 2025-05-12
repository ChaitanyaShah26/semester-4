#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int key[MAX];       
int parent[MAX];    
int visited[MAX];   

int minKey(int n) 
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) 
    {
        if (!visited[v] && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int n) 
{
    int totalCost = 0;

    for (int i = 0; i < n; i++) 
    {
        key[i] = INT_MAX;
        visited[i] = 0;  
        parent[i] = -1;  
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) 
    {
        int u = minKey(n);

        visited[u] = 1;

       
        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

   
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) 
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Minimum Cost of MST: %d\n", totalCost);
}

void main() 
{
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(n);

    getch();
}