#include<stdio.h>
#include<conio.h>

// Simple Iterative Min-Max
void simpleMinMax(int arr[], int size, int *min, int *max) 
{
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < *min) 
        {
            *min = arr[i];
        }
        if (arr[i] > *max) 
        {
            *max = arr[i];
        }
    }
}

// Divide and Conquer Min-Max
void MinMax_dc(int arr[], int i, int j, int *min, int *max) 
{
    int mid;
    int min1, max1, min2, max2;
    
    if (i == j) 
    {
        *min = arr[i];
        *max = arr[i];
    } 
    else if (i==j-1) 
    {
        if (arr[i] < arr[j]) 
        {
            *min = arr[i];
            *max = arr[j];
        } 
        else 
        {
            *min = arr[j];
            *max = arr[i];
        }
    } 
    else 
    {
        mid = (i + j) / 2;

        MinMax_dc(arr, i, mid, &min1, &max1);
        MinMax_dc(arr, mid + 1, j, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

void main() 
{
    int size;
    int simpleMin, simpleMax;
    int divideConquerMin, divideConquerMax;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Taking input for the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Simple Min-Max
    simpleMinMax(arr, size, &simpleMin, &simpleMax);
    printf("\nSimple Min-Max:\n");
    printf("Minimum: %d\nMaximum: %d\n", simpleMin, simpleMax);

    // Divide and Conquer Min-Max
    MinMax_dc(arr, 0, size - 1, &divideConquerMin, &divideConquerMax);
    printf("\nDivide and Conquer Min-Max:\n");
    printf("Minimum: %d\nMaximum: %d\n", divideConquerMin, divideConquerMax);

    getch();
}