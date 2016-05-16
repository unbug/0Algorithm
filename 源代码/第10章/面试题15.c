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
    printf("�����е����ݣ�\n");
    for(i=0;i<len;i++)
        printf("%d ",A[i]);
    printf("\n����Ҫ������������");
    scanf("%d",&n);	
    addr = bin_search(A,len,n);
    if(0 != addr)
        printf("%d λ������ĵ� %d ������\n ",n,addr+1);
    else
        printf("δ������ %d \n",n);
    getche();
    return 0;
}