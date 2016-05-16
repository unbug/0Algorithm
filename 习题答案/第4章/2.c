#include <stdio.h>
#define MAX 15

void SelectSort(int a[],int n)
{
    int i,j,t,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(a[k]<a[j]) k=j;
        t=a[i];
        a[i]=a[k];
        a[k]=t;    
    }
}
int main()
{
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    SelectSort(a,MAX);
    printf("ÅÅÐò½á¹û:"); 
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}