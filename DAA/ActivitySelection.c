#include <stdio.h>
#include <conio.h>

typedef struct 
{
    int start;
    int finish;
    int activity;
} Time;

void swap(Time *a, Time *b) 
{
    Time temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Time time[], int n) 
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (time[j].finish > time[j + 1].finish) 
            { 
                swap(&time[j], &time[j + 1]);
            }
        }
    }
}

void ActivitySelection(int start[], int finish[], int activity[], int n) 
{
    int i,j;
    Time time[100];
    for (i = 0; i < n; i++) 
    {
        time[i].start = start[i];
        time[i].finish = finish[i];
        time[i].activity = activity[i];
    }

    bubbleSort(time, n);

    j = 0;
    printf("\nSelected activities: %d\t", time[j].activity); 

    for (i = 1; i < n; i++) 
    {
        if (time[i].start >= time[j].finish) 
        {
            printf("%d\t", time[i].activity); 
            j = i; 
        }
    }
}

void main() 
{
    int n, start[100], finish[100];
    int activity[100];

    clrscr();

    printf("\nEnter number of elements in both arrays: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        activity[i] = (i + 1);
    }

    printf("\nEnter Start Time array: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("Enter index %d element of Start Time Array: ", (i + 1));
        scanf("%d", &start[i]);
    }

    printf("\nEnter Finish Time array: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("Enter index %d element of Finish Time Array: ", (i + 1));
        scanf("%d", &finish[i]);
    }

    ActivitySelection(start, finish, activity, n);

    getch();
}