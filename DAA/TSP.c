#include<stdio.h>
#include<conio.h>
#include<limits.h>

#define MAX 100

int dist[MAX][MAX];
int visited[MAX];
int dp[MAX][MAX];
int path[MAX];
int bestPath[MAX];
int n;
int minCost = INT_MAX;

int tsp(int pos, int count) 
{
	int ans, city, cost, i;

    if (count == n) 
    {
        return dist[pos][0];
    }

    if (dp[pos][count] != -1) 
    {
        return dp[pos][count];
    }

    ans = INT_MAX;

    for (city = 0; city < n; city++) 
    {
        if (!visited[city]) 
        {
            visited[city] = 1;
            path[count] = city;

            cost = dist[pos][city] + tsp(city, count + 1);

            if (count == 1 && cost < minCost) 
            {
                minCost = cost;
                for (i = 0; i < n; i++) 
                {
                    bestPath[i] = path[i];
                }
                bestPath[n] = 0;
            }

            ans = (cost < ans) ? cost : ans;
            visited[city] = 0; // backtrack
        }
    }

    dp[pos][count] = ans;
    return ans;
}

void main() 
{
	int i, j, result;
	
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (i = 0; i < n; i++) visited[i] = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dp[i][j] = -1;

    visited[0] = 1;
    path[0] = 0;

    result = tsp(0, 1);

    printf("\nMinimum cost: %d\n", result);
    printf("Optimal Path: ");
    for (i = 0; i <= n; i++)
        printf("%d ", bestPath[i]);
    printf("\n");

    getch();
}

// output : Min cost : 35 , Optimal Path : 0 1 3 2 0 


// Output:
/*

Enter number of cities: 4
Enter distance matrix:
0 16 11 6
8 0 13 16
4 7 0 9
5 12 2 0

Minimum cost: 22
Optimal Path: 0 3 2 3 0


*/