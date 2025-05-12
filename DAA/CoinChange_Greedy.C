#include <stdio.h>
#include <conio.h>

#define MAX_COINS 100
#define MAX_COST 1000

void main() 
{
    int cost, coins, index = 0;
    int coins_value[MAX_COINS];
    int coins_list[MAX_COST];   

    printf("Enter total value: ");
    scanf("%d", &cost);

    printf("Enter the number of coins: ");
    scanf("%d", &coins);

   
    if (coins > MAX_COINS) 
    {
        printf("Error: Number of coins exceeds the maximum limit of %d.\n", MAX_COINS);
        return 1;
    }

    printf("\nEnter the coin values:\n");
    for (int i = 0; i < coins; i++) 
    {
        scanf("%d", &coins_value[i]);
    }

   
    for (int i = coins - 1; i >= 0; i--) 
    {
        while (cost >= coins_value[i]) 
        {
            cost -= coins_value[i];
            coins_list[index++] = coins_value[i];
        }
    }

   
    printf("\nThe selected coins for the original cost are: ");
    for (int i = 0; i < index; i++) 
    {
        printf("%d ", coins_list[i]);
    }
    printf("\n");

   
    if (cost > 0) 
    {
        printf("Remaining amount that could not be fulfilled: %d\n", cost);
    }

    getch();
}