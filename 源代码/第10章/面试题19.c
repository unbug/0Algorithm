#include <stdio.h>

int SecMax(const int arr[],int n)
{
    int max,secmax,i;
    if(n<2)
    {
        printf("数据数量小于2!\n"); 
        exit(0);
    }
    if(arr[0]>arr[1])
    {
        max = arr[0];
        secmax = arr[1];
    }else{
        max = arr[1];
        secmax = arr[0];
    }
    for(i=2;i<n;i++)
    {
        if(arr[i]>max)
        {
            secmax = max;
            max = arr[i];
        }
        else if(arr[i]<max && arr[i]>secmax)
        {
            secmax = arr[i];
        }
    }
    return secmax;
}

int main()
{
    int i,data[]={12,5,7,4,6,10,18,17,19,13};
    printf("数据列表：");
    for(i=0;i<10;i++)
        printf("%3d",data[i]);
    printf("\n第2大的数为： %d\n",SecMax(data,10));
    getche();
    return 0;
}