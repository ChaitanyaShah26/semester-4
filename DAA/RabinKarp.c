#include <stdio.h>
#include <conio.h>
#include <string.h>

#define d 256

void rabinKarp(char pat[], char txt[], int q) 
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
   
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
   
    for (i = 0; i < M; i++) 
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) 
    {     
        if (p == t) 
        {          
            for (j = 0; j < M; j++) 
            {
                if (txt[i + j] != pat[j])
                    break;
            }
           
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }
       
        if (i < N - M) 
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
           
            if (t < 0)
                t = (t + q);
        }
    }
}

void main() 
{
    char txt[100], pat[100];
    int q = 13;
   
    printf("Enter the text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = 0;

    printf("Enter the pattern: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = 0;
   
    rabinKarp(pat, txt, q);

    getch();
}