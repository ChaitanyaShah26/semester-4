#include <stdio.h>
#include <conio.h>
#include <limits.h>


void matrixChainOrder(int p[], int n) 
{
    int i, j, k, l, q;
    int m[10][10], s[10][10];
    
    for (i = 1; i <= n; i++) 
    {
        m[i][i] = 0;
        for (j = 1; j <= n; j++) 
        {
            s[i][j] = 0;
        }
    }

    for (l = 2; l <= n; l++) 
    {
        for (i = 1; i <= n - l + 1; i++) 
        {
            j = i + l - 1;
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) 
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    
    printf("\nM table:\n");
    printf("     ");
    for (j = 1; j <= n; j++) 
    {
        printf("M%d  ", j);
    }
    printf("\n");

    for (i = 1; i <= n; i++) 
    {
        printf("M%d  ", i);
        for (j = 1; j <= n; j++) 
        {
            if (i == j) 
            {
                printf("  0 ");
            } 
            else if (j > i) 
            {
                printf("%3d ", m[i][j]);
            } 
            else 
            {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("\nK table:\n");
    printf("     ");
    for (j = 1; j <= n; j++) 
    {
        printf("K%d  ", j);
    }
    printf("\n");

    for (i = 1; i <= n; i++) 
    {
        printf("K%d  ", i);
        for (j = 1; j <= n; j++) 
        {
            if (i == j) 
            {
                printf("  0 ");
            } 
            else if (j > i) 
            {
                printf("  %d ", s[i][j]); 
            } 
            else 
            {
                printf("    "); 
            }
        }
        printf("\n");
    }
}

void main() 
{
    int n, i;
    int p[10];

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the dimensions (p[0] to p[%d]):\n", n);
    for (i = 0; i <= n; i++) 
    {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n);
    getch();
}
