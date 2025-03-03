#include <stdio.h>
#include <conio.h>

#define INT_MAX 1000
#define MAX_NODES 100

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int startNode) 
{
    int distance[MAX_NODES], visited[MAX_NODES], parent[MAX_NODES], path[MAX_NODES];
    int i, j, k, count, v;
    int minDistance, minIndex, pathIndex;
    
    for (i = 0; i < numNodes; i++) 
    {
        distance[i] = INT_MAX; 
        visited[i] = 0;        
        parent[i] = -1;        
    }
    
    distance[startNode] = 0; 

    for (count = 0; count < numNodes - 1; count++) 
    {
        minDistance = INT_MAX; // Reset minDistance for each iteration
        minIndex = -1; // Reset minIndex for each iteration

        // Find the vertex with the minimum distance
        for (v = 0; v < numNodes; v++) 
        {
            if (!visited[v] && distance[v] < minDistance) 
            {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        // If no vertex is found, break the loop
        if (minIndex == -1) 
        {
            break;
        }

        visited[minIndex] = 1;

        // Update the distance of the adjacent vertices
        for (v = 0; v < numNodes; v++) 
        {
            if (!visited[v] && graph[minIndex][v] && distance[minIndex] != INT_MAX && distance[minIndex] + graph[minIndex][v] < distance[v]) 
            {
                distance[v] = distance[minIndex] + graph[minIndex][v];
                parent[v] = minIndex; 
            }
        }
    }

    // Print the results
    printf("Vertex\tDistance from Source\tParent Node\n");
    for (i = 0; i < numNodes; i++) 
    {
        printf("%c\t%d\t\t\t%c\n", 'A' + i, distance[i], parent[i] == -1 ? ' ' : 'A' + parent[i]);
    }

    printf("\nPaths from source node %c:\n", 'A' + startNode);
    for (i = 0; i < numNodes; i++) 
    {
        if (i != startNode) 
        {
            printf("Path to %c: ", 'A' + i);
            j = i;
            if (distance[i] == INT_MAX) 
            {
                printf("No path\n");
            } 
            else 
            {
                pathIndex = 0;
                while (j != -1) 
                {
                    path[pathIndex++] = j;
                    j = parent[j];
                }
                
                for (k = pathIndex - 1; k >= 0; k--) 
                {
                    printf("%c ", 'A' + path[k]);
                }
                printf("(Distance: %d)\n", distance[i]);
            }
        }
    }
}

void main() 
{
    int numNodes;
    int graph[MAX_NODES][MAX_NODES];
    int i, j, startNode;
    char startNodeChar;

    clrscr();

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < numNodes; i++) 
    {
        for (j = 0; j < numNodes; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the starting node (A to %c): ", 'A' + numNodes - 1);
    scanf(" %c", &startNodeChar); 

    startNode = startNodeChar - 'A';

    dijkstra(graph, numNodes, startNode);

    getch();
}




/*  Sample Output   */
/*

Enter the number of nodes: 6
Enter the adjacency matrix (use 0 for no edge):
0 3 5 0 0 0 
0 0 3 4 7 0
0 0 0 2 6 8
9 0 0 0 2 2
0 0 0 0 0 5
0 0 0 0 0 0
Enter the starting node (A to F): A
Vertex  Distance from Source    Parent Node
A       0                        
B       3                       A
C       5                       A
D       7                       B
E       9                       D
F       9                       D

Paths from source node A:
Path to B: A B (Distance: 3)
Path to C: A C (Distance: 5)
Path to D: A B D (Distance: 7)
Path to E: A B D E (Distance: 9)
Path to F: A B D F (Distance: 9)

*/