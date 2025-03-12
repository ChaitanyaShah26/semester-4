#include <stdio.h>
#include <conio.h>

#define MAX 100
#define INF 1000

int min(int a, int b) 
{
    return (a < b) ? a : b;
}

void printTable(int table[MAX][MAX], int m, int sum, int coins[]) 
{
    int i, j;

    printf("\nTable:\n");
    printf("\t\t\t");

    for (j = 0; j <= sum; j++) 
    {
        printf("%d\t", j);
    }
    printf("\n");
    for (j = 0; j <= sum; j++) 
    {
        if(j==0)
        {
            printf("\t\t----\t----");
        }
        else
        {
            printf("\t----");
        }
    }
    printf("\n");

    for (i = 0; i <= m; i++) 
    {
        if (i == 0) 
        {
            printf("\tindex=%d  |\t",i);
        } 
        else 
        {
            printf("coin=%d  index=%d  |\t", coins[i - 1],i); 
        }
        for (j = 0; j <= sum; j++) 
        {
            if (table[i][j] == INF) 
            {
                printf("INF\t");
            } 
            else 
            {
                printf("%d\t", table[i][j]);
            }
        }
        printf("\n");
    }
}

void findSolution(int table[MAX][MAX], int coins[], int m, int sum) 
{
    int i = m, j = sum, p = 0, k;
    int sol[MAX];

    while (j > 0) 
    {
        if (table[i][j] == table[i - 1][j]) 
        {
            i = i - 1;
        } 
        else 
        {
            sol[p] = coins[i - 1];
            j = j - coins[i - 1];
            p++;
        }
    }

    printf("\nCoins used: %d\n", p);
    printf("\nSolution: ");

    for (k = 0; k < p; k++) 
    {
        printf("%d ", sol[k]);
    }
    printf("\n");
}

void coinChange(int sum, int m, int coins[]) 
{
    int table[MAX][MAX];
    int i, j;


    for (i = 0; i <= m; i++) 
    {
        for (j = 0; j <= sum; j++) 
        {
            if (j == 0) 
            {
                table[i][j] = 0;
            } 
            else if (i == 0) 
            {
                table[i][j] = INF; 
            } 
            else 
            {
                table[i][j] = INF; 
            }
        }
    }

    
    for (i = 1; i <= m; i++) 
    {
        for (j = 1; j <= sum; j++) 
        {
            if (coins[i - 1] > j) 
            {
                table[i][j] = table[i - 1][j];
            } 
            else 
            {
                table[i][j] = min(table[i - 1][j], 1 + table[i][j - coins[i - 1]]);
            }
        }
    }

   
    printTable(table, m, sum, coins);

    findSolution(table, coins, m, sum);
}

void main() 
{
    int sum, m;
    int coins[MAX];
    int i, j, temp;

    clrscr();

    printf("Enter the maximum sum: ");
    scanf("%d", &sum);

    printf("Enter the number of coins: ");
    scanf("%d", &m);

    printf("Enter the coin values:\n");
    for (i = 0; i < m; i++) 
    {
        scanf("%d", &coins[i]);
    }

    for (i = 0; i < m - 1; i++) 
    {
        for (j = i + 1; j < m; j++) 
        {
            if (coins[i] > coins[j]) 
            {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    coinChange(sum, m, coins);

    getch();
}



// Output:
/*

Enter the maximum sum: 10
Enter the number of coins: 4
Enter the coin values:
2
5
3
6

Table:
                        0       1       2       3       4       5       6       7       8       9       10
                ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----    ----
        index=0  |      0       INF     INF     INF     INF     INF     INF     INF     INF     INF     INF
coin=2  index=1  |      0       INF     1       INF     2       INF     3       INF     4       INF     5
coin=3  index=2  |      0       INF     1       1       2       2       2       3       3       3       4
coin=5  index=3  |      0       INF     1       1       2       1       2       2       2       3       2
coin=6  index=4  |      0       INF     1       1       2       1       1       2       2       2       2

Coins used: 2

Solution: 5 5

*/