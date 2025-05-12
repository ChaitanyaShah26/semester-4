#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 100

void naive_string(char *text, char *pattern) 
{
    int n = strlen(text);
    int m = strlen(pattern);
    int j;

    for (int i = 0; i <= n - m; i++) 
    {
        for (j = 0; j < m; j++) 
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) 
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}

void main() 
{
    char text[MAX];  
    char pattern[MAX];

    printf("Enter the text string: ");
    scanf("%99s", text);
    printf("Enter the pattern string: ");
    scanf("%99s", pattern);

    naive_string(text, pattern);

    getch();
}