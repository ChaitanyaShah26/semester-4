#include <stdio.h>
#include <conio.h>
#include <string.h>

void computePrefix(char *p, int m, int lps[]) 
{
    int l = 0;
    int i = 1;
    lps[0] = 0;


    while (i < m) 
    {
        if (p[i] == p[l]) 
        {
            l++;
            lps[i] = l;
            i++;
        } 
        else 
        {
            if (l != 0) 
            {
                l = lps[l - 1];
            } 
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpPatternSearch(char *p, char *S) 
{
    int m = strlen(p);
    int n = strlen(S);
    int lps[m];

    computePrefix(p, m, lps);

    int i = 0;
    int j = 0;
    while (i < n) 
    {
        if (p[j] == S[i]) 
        {
            i++;
            j++;
        }

        if (j == m) 
        {
            printf("Pattern found at location: %d\n", i - j);
            j = lps[j - 1];
        } 
        else if (i < n && p[j] != S[i]) 
        {
        
            if (j != 0) 
            {
                j = lps[j - 1];
            } 
            else 
            {
                i++;
            }
        }
    }
}

void main() 
{
    char S[1000], p[100];

    printf("Enter the text string: ");
    scanf("%s",S);

    printf("Enter the pattern to search: ");
    scanf("%s",p);

    kmpPatternSearch(p, S);

    getch();
}




// Output:
/*

Enter the text string: ABACABABABACABA
Enter the pattern to search: ABACABA
Pattern found at location: 0
Pattern found at location: 8

*/