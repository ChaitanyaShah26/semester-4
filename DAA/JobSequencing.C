#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define MAX_JOBS 100

void print_schedule(int schedule[], int jobs, int profit[]) 
{
    int total_profit = 0;
    for (int i = 0; i < jobs; i++) 
    {
        if (schedule[i] != -1) 
        {
            printf("J%d -> ", schedule[i]);
            total_profit += profit[schedule[i] - 1];
        }
    }
    printf("NULL\n");
    printf("Maximum Profit: %d\n", total_profit);
}

void job_sequencing(int deadline[], int index[], int profit[], int jobs) 
{
    int schedule[MAX_JOBS];

   
    for (int i = 0; i < jobs; i++) 
    {
        schedule[i] = -1;
    }

   
    for (int i = 0; i < jobs; i++) 
    {
        int j = deadline[i];

       
        while (j > 0 && schedule[j] != -1) 
        {
            j--;
        }
        if (j > 0) 
        {
            schedule[j] = index[i];
        }
    }

    print_schedule(schedule, jobs, profit);
}

void main() 
{
    int jobs, temp;

    printf("Enter the number of jobs (max %d): ", MAX_JOBS);
    scanf("%d", &jobs);

   
    if (jobs > MAX_JOBS) 
    {
        printf("Error: Number of jobs exceeds the maximum limit of %d.\n", MAX_JOBS);
        return 1;
    }

    int deadline[MAX_JOBS];
    int profit[MAX_JOBS];
    int index[MAX_JOBS];

   
    for (int i = 0; i < jobs; i++) 
    {
        printf("Enter deadline and profit for J%d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);
        index[i] = i + 1;
    }

   
    for (int i = 0; i < jobs; i++) 
    {
        for (int j = 0; j < jobs - i - 1; j++) 
        {
            if (profit[j] < profit[j + 1]) 
            {
               
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

               
                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

               
                temp = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp;
            }
        }
    }

   
    job_sequencing(deadline, index, profit, jobs);

    getch();
}
