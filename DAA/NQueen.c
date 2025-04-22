#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 20

int x[MAX];

void NQueen(int k, int n);
bool place(int k, int i);

void main() 
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    printf("The solutions of %d Queen Problem is: \n(Column position in each row)\n",n);
    NQueen(1, n);
    getch();
}

void NQueen(int k, int n) 
{
    int i, m;
    for (i = 1; i <= n; i++) 
    {
        if (place(k, i)) 
        {
            x[k] = i; 
            if (k == n) 
            {
                for (m = 1; m <= n; m++) 
                {
                    printf("%d ", x[m]);
                }
                printf("\n");
            } 
            else 
            {
                NQueen(k + 1, n); 
            }
        }
    }
}

bool place(int k, int i) 
{
    int j;
    for (j = 1; j < k; j++) 
    {
        if (x[j] == i || abs(x[j] - i) == abs(k - j)) 
        {
            return 0; 
        }
    }
    return true; 
}




// Output:
/*

Enter the number of queens: 4
The solutions of 4 Queen Problem is: 
(Column position in each row)
2 4 1 3 
3 1 4 2

*/