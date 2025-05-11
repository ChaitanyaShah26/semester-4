#include <stdio.h>
#include <limits.h>
#include <conio.h>

void merge(int A[], int p, int q, int r) 
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    int i, j, k;

    for (i = 0; i < n1; i++) 
    {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) 
    {
        R[j] = A[q + 1 + j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++) 
    {
        if (L[i] <= R[j]) 
        {
            A[k] = L[i];
            i++;
        } 
        else 
        {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int A[], int p, int r) 
{
    int q;
    if (p < r) 
    {
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void main() 
{
    int n,i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    getch();
}