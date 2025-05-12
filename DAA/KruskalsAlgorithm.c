#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

typedef struct 
{
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX], rank[MAX];
int numEdges, numVertices;

int find(int i) 
{
    if (parent[i] != i) 
    {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void unionSets(int u, int v) 
{
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU != rootV) 
    {
        if (rank[rootU] > rank[rootV]) 
        {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) 
        {
            parent[rootU] = rootV;
        } else 
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int compare(const void *a, const void *b) 
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal() 
{
    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    
    for (int i = 0; i < numEdges; i++) 
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(u) != find(v)) 
        {
            unionSets(u, v);
            printf("%d -- %d == %d\n", u, v, weight);
            minCost += weight;
        }
    }
    
    printf("Minimum Cost of Spanning Tree: %d\n", minCost);
}

void main() 
{
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    
    for (int i = 0; i < numEdges; i++) 
    {
        printf("Enter edge (u, v) and weight: ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

   
    for (int i = 0; i < numVertices; i++) 
    {
        parent[i] = i;
        rank[i] = 0;
    }

   
    qsort(edges, numEdges, sizeof(edges[0]), compare);

   
    kruskal();

    getch();
}