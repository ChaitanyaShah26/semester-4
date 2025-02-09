// Quick Sort

#include<stdio.h>
#include<conio.h>
#define MAX 100
int partition(int a[],int lb,int ub);
void quickSort(int a[],int lb,int ub);

void main()
{
    int n,i,a[MAX],lb,ub;
    clrscr();
    printf("Enter Number of Element to be Sort: ");
    scanf("%d",&n);
    printf("\n Enter %d Elements in Array to Sort: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Array Before Sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    lb=0;
    ub=n-1;
    quickSort(a,lb,ub);
    printf("\n Array After Sorting:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    getch();
}

void quickSort(int a[],int lb,int ub)
{       int loc;
    if(lb<ub)
    {
        loc=partition(a,lb,ub);
        quickSort(a,lb,loc-1);
        quickSort(a,loc+1,ub);
    }


}

int partition(int a[],int lb, int ub)
{
    int pivot,start,end,temp;
    pivot=a[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
        {
            temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
     }
     temp=a[lb];
     a[lb]=a[end];
     a[end]=temp;
     return end;
}