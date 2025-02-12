#include <stdio.h>
#include <conio.h>

typedef struct 
{
    int index;
    double profit;
    double weight;
    double ratio;
} Item;

void swap(Item *a, Item *b) 
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(Item items[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (items[j].ratio < items[j + 1].ratio) 
            {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

double fractionalKnapsack(int profit[], int weight[], int n, int capacity) 
{
    Item items[n];
    for (int i = 0; i < n; i++) 
    {
        items[i].index = i;
        items[i].profit = profit[i];
        items[i].weight = weight[i];
        items[i].ratio = (double)profit[i] / weight[i];
    }

    sortItems(items, n);

    double totalProfit = 0.0;
    printf("\n| Index | Profit | Weight | Profit/Weight Ratio | Capacity | Selection |\n");
    printf("|-------|--------|--------|---------------------|----------|-----------|\n");

    for (int i = 0; i < n; i++) 
    {
        if (capacity <= 0) break;

        if (items[i].weight <= capacity) 
        {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
            printf("| %5d | %6.2f | %6.2f | %19.2f | %8.2f | %9.2f |\n",
                   items[i].index, items[i].profit, items[i].weight, items[i].ratio, items[i].weight, 1.0);
        } else 
        {
            double fraction = (double)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("| %5d | %6.2f | %6.2f | %19.2f | %8.2f | %9.2f |\n",
                   items[i].index, items[i].profit, items[i].weight, items[i].ratio, (double)capacity, fraction);
            capacity = 0; // Knapsack is full
        }
    }

    return totalProfit;
}

void main() 
{
    int n, capacity;

    clrscr();

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter the profits of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Profit of item %d: ", i + 1);
        scanf("%d", &profit[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(profit, weight, n, capacity);
    printf("\nMaximum profit in the knapsack: %.2f\n", maxProfit);

    getch();
}