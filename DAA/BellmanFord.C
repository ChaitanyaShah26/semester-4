#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define MAX_VERTICES 20
#define INF INT_MAX

void main() 
{
    int V;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    char vertices[MAX_VERTICES];
    char source;
    
   
    printf("Enter the number of nodes: ");
    scanf("%d", &V);
    if(V < 1 || V > MAX_VERTICES) 
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }
   
    for (int i = 0; i < V; i++) 
    {
        vertices[i] = 'A' + i;
    }
   
    printf("Enter the adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            int w;
            scanf("%d", &w);
            if(i == j) 
            {
                adjMatrix[i][j] = 0;
            } 
            else if (w == 0) 
            {
                adjMatrix[i][j] = INF;
            }
            else 
            {
                adjMatrix[i][j] = w;
            }
        }
    }

    printf("Enter the starting node (A to %c): ", vertices[V-1]);
    scanf(" %c", &source);

    int sourceIndex = source - 'A';
    if(sourceIndex < 0 || sourceIndex >= V) 
    {
        printf("Invalid source node.\n");
        return 1;
    }
   
    for (int i = 0; i < V; i++) 
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[sourceIndex] = 0;

    for (int i = 1; i <= V - 1; i++) 
    {
        for (int u = 0; u < V; u++) 
        {
            for (int v = 0; v < V; v++) 
            {
                if (adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }
   
    for (int u = 0; u < V; u++) 
    {
        for (int v = 0; v < V; v++) 
        {
            if (adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v]) 
            {
                printf("Graph contains a negative weight cycle.\n");
                return 1;
            }
        }
    }

    printf("Vertex\tDistance from Source\tParent Node\n");
    for (int i = 0; i < V; i++) 
    {
        if (dist[i] == INF)
            printf("%c\t\tINF\t\t\t-\n", vertices[i]);
        else
            printf("%c\t\t%d\t\t\t%c\n", vertices[i], dist[i], parent[i] == -1 ? '-' : vertices[parent[i]]);
    }

    printf("\nPaths from source node %c:\n", source);
    for (int i = 0; i < V; i++) 
    {
        if (i == sourceIndex) continue;
        if (dist[i] == INF) 
        {
            printf("Path to %c: No path\n", vertices[i]);
            continue;
        }
        
        printf("Path to %c: ", vertices[i]);
       
        int path[MAX_VERTICES];
        int count = 0;
        int current = i;
        while (current != -1) 
        {
            path[count++] = current;
            current = parent[current];
        }
        for (int j = count - 1; j >= 0; j--) 
        {
            printf("%c ", vertices[path[j]]);
        }
        printf("(Distance: %d)\n", dist[i]);
    }

    getch();
}