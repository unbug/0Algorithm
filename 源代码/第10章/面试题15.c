#include "stdio.h"

int bin_search(int A[],int n,int key)
{
    int low,high,mid;
    low = 0;
    high = n;
    while(low<=high)
    {
        mid = (low + high)/2;
        if(A[mid]==key)
            return mid;
        if(A[mid]<key){
            low = mid + 1;
        }
        if(A[mid]>key){
            high = mid - 1;
        }
    }
    return 0;
}
int main()
{
    int A[] = {1,3,5,7,10,12,15,19,21,50};
    int i,n ,addr,len=10;
    printf("数组中的内容：\n");
    for(i=0;i<len;i++)
        printf("%d ",A[i]);
    printf("\n输入要搜索的整数：");
    scanf("%d",&n);	
    addr = bin_search(A,len,n);
    if(0 != addr)
        printf("%d 位于数组的第 %d 个数。\n ",n,addr+1);
    else
        printf("未搜索到 %d \n",n);
    getche();
    return 0;
}