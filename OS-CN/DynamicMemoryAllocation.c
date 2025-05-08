#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define MAX 100


void firstFit(int memory[], bool block_used[], int blocks, int process[], int allocation[], int processes) 
{
    int i,j;
    
    for(i = 0; i < processes; i++) 
    {
        for(j = 0; j < blocks; j++) 
        {
            if(!block_used[j] && memory[j] >= process[i]) 
            {
                allocation[i] = j;    
                block_used[j] = true;   
                break;
            }
        }
    }
}


void bestFit(int memory[], bool block_used[], int blocks, int process[], int allocation[], int processes) 
{
    int bestIndex, minDiff, diff;
    int i, j;
    
    for(i = 0; i < processes; i++) 
    {
        bestIndex = -1;
        minDiff = 10000;  
        for(j = 0; j < blocks; j++) 
        {
            if(!block_used[j] && memory[j] >= process[i]) 
            {
                diff = memory[j] - process[i];
                if(diff < minDiff) 
                {
                    minDiff = diff;
                    bestIndex = j;
                }
            }
        }
        if(bestIndex != -1) 
        {
            allocation[i] = bestIndex;
            block_used[bestIndex] = true;
        } 
        else 
        {
            allocation[i] = -1; 
        }
    }
}


void worstFit(int memory[], bool block_used[], int blocks, int process[], int allocation[], int processes) 
{
    int worstIndex, maxDiff, diff;
    int i, j;
    
    for(i = 0; i < processes; i++) 
    {
        worstIndex = -1;
        maxDiff = -1;
        for(j = 0; j < blocks; j++) 
        {
            if(!block_used[j] && memory[j] >= process[i]) 
            {
                diff = memory[j] - process[i];
                if(diff > maxDiff) 
                {
                    maxDiff = diff;
                    worstIndex = j;
                }
            }
        }
        if(worstIndex != -1) 
        {
            allocation[i] = worstIndex;
            block_used[worstIndex] = true;
        } 
        else 
        {
            allocation[i] = -1; 
        }
    }
}

void main() 
{
    int memory[MAX], process[MAX], allocation[MAX];
    bool block_used[MAX]; 
    int blocks, processes, i, j;
    
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blocks);
    
    printf("\nEnter the size of each memory block:\n");
    for(i = 0; i < blocks; i++) 
    {
        printf("Block %d Size -> ", i + 1);
        scanf("%d", &memory[i]);
        block_used[i] = false;  
    }
    
    printf("\nEnter the number of processes: ");
    scanf("%d", &processes);
    
    printf("Enter the size of each process:\n");
    for(i = 0; i < processes; i++) 
    {
        printf("Process %d Size -> ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1;  
    }

    
    firstFit(memory, block_used, blocks, process, allocation, processes);
    printf("\nFirst Fit Allocation: \n");
    printf("Process Size\tMemory Block\n");
    for(i = 0; i < processes; i++) 
    {
        printf("%d\t\t", process[i]);
        if(allocation[i] != -1) 
        {
            printf("%d\n", memory[allocation[i]]);
        } 
        else 
        {
            printf("Not Allocated\n");
        }
    }
    
    for(i = 0; i < blocks; i++) 
    {
        block_used[i] = false;
    }
    
    bestFit(memory, block_used, blocks, process, allocation, processes);
    printf("\nBest Fit Allocation: \n");
    printf("Process Size\tMemory Block\n");
    for(i = 0; i < processes; i++) 
    {
        printf("%d\t\t", process[i]);
        if(allocation[i] != -1) 
        {
            printf("%d\n", memory[allocation[i]]);
        } 
        else 
        {
            printf("Not Allocated\n");
        }
    }
    
    for(i = 0; i < blocks; i++) 
    {
        block_used[i] = false;
    }
    
    worstFit(memory, block_used, blocks, process, allocation, processes);
    printf("\nWorst Fit Allocation: \n");
    printf("Process Size\tMemory Block\n");
    for(i = 0; i < processes; i++) 
    {
        printf("%d\t\t", process[i]);
        if(allocation[i] != -1) 
        {
            printf("%d\n", memory[allocation[i]]);
        } 
        else 
        {
            printf("Not Allocated\n");
        }
    }

    getch();
}