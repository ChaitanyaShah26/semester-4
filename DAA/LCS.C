#include <stdio.h>
#include <string.h>

#define MAX 100

void LCS_Length(char *X, char *Y, int C[MAX][MAX], char B[MAX][MAX]) 
{
    int m = strlen(X);
    int n = strlen(Y);

   
    for (int i = 0; i <= m; i++) 
    {
        C[i][0] = 0; 
    }
    for (int j = 0; j <= n; j++) 
    {
        C[0][j] = 0; 
    }

   
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (X[i - 1] == Y[j - 1]) 
            {
                C[i][j] = C[i - 1][j - 1] + 1; 
                B[i][j] = 'D';
            } 
            else 
            {
                if (C[i - 1][j] >= C[i][j - 1]) 
                {
                    C[i][j] = C[i - 1][j]; 
                    B[i][j] = 'U';
                } 
                else 
                {
                    C[i][j] = C[i][j - 1]; 
                    B[i][j] = 'L';
                }
            }
        }
    }
}

void Print_LCS(char B[MAX][MAX], char *X, int i, int j) 
{
    if (i == 0 || j == 0) 
    {
        return;
    }
    if (B[i][j] == 'D') 
    {
        Print_LCS(B, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } 
    else if (B[i][j] == 'U') 
    {
        Print_LCS(B, X, i - 1, j);
    } 
    else 
    {
        Print_LCS(B, X, i, j - 1);
    }
}

void Print_Table(int C[MAX][MAX], int m, int n) 
{
    printf("\nLCS Length Table:\n    ");
    for (int j = 0; j <= n; j++) 
    {
        printf("%3d ", j);
    }
    printf("\n");
    for (int i = 0; i <= m; i++) 
    {
        printf("%3d ", i);
        for (int j = 0; j <= n; j++) 
        {
            printf("%3d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    char X[MAX], Y[MAX];
    int C[MAX][MAX];
    char B[MAX][MAX];

    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    LCS_Length(X, Y, C, B);

    int m = strlen(X);
    int n = strlen(Y);

    Print_Table(C, m, n);

    printf("\nLength of LCS: %d\n", C[m][n]);
    printf("Longest Common Subsequence: ");
    Print_LCS(B, X, m, n);
    printf("\n");

    return 0;
}