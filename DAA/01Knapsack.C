#include <stdio.h>
#include <conio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int knapsack(int n, int W, int weight[], int value[]) 
{
    int V[n + 1][W + 1];

   
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                V[i][w] = 0;
            else if (weight[i] > w)
                V[i][w] = V[i - 1][w];
            else
                V[i][w] = max(V[i - 1][w], value[i] + V[i - 1][w - weight[i]]);
        }
    }

   
    printf("\nDP Table (V[i][w]):\n");
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            printf("%3d ", V[i][w]);
        }
        printf("\n");
    }

   
    return V[n][W];
}

void main() 
{
    int n, W;
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], value[n + 1];

    printf("Enter weights of items:\n");
    for (i = 1; i <= n; i++) 
    {
        printf("Weight of item %d: ", i);
        scanf("%d", &weight[i]);
    }

    printf("Enter values of items:\n");
    for (i = 1; i <= n; i++) 
    {
        printf("Value of item %d: ", i);
        scanf("%d", &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int maxValue = knapsack(n, W, weight, value);
    printf("\nMaximum value that can be put in the knapsack = %d\n", maxValue);

	getch();
}
