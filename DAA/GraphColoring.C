#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int numNodes;

bool isSafe(int v, int c) 
{
    for (int i = 0; i < numNodes; i++) 
    {
        if (graph[v][i] && color[i] == c) 
        {
            return false;
        }
    }
    return true;
}

void nextValue(int k) 
{
    while (true) 
    {
        color[k]++;
        if (color[k] > numNodes) 
        {
            color[k] = 0;
            return;
        }
       
        bool safe = true;
        for (int j = 0; j < numNodes; j++) 
        {
            if (graph[k][j] && color[j] == color[k]) 
            {
                safe = false;
                break;
            }
        }
        if (safe) 
        {
            return;
        }
    }
}

void mColoring(int k) 
{
    if (k == numNodes) 
    {
       
        printf("Solution: ");
        for (int i = 0; i < numNodes; i++) 
        {
            printf("%d ", color[i]);
        }
        printf("\n");
        return;
    }

   
    while (true) 
    {
        nextValue(k);
        if (color[k] == 0) 
        {
            return;
        }
        mColoring(k + 1);
    }
}

int minColorsNeeded() 
{
    return numNodes - 1;
}

void main() 
{
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
   
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) 
        {
            graph[i][j] = 0;
        }
        color[i] = 0;
    }
   
    printf("Enter the adjacency matrix (%d x %d):\n", numNodes, numNodes);
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int minColors = minColorsNeeded();
    printf("Minimum number of colors needed: %d\n", minColors);
    mColoring(0);

    getch();
}