#include "stdio.h"

void reverse(int a[],int low,int high)
{
    int temp;
    while(low<high)
    {
        temp = a[low];              //����Ԫ��
        a[low] = a[high];
        a[high] = temp;
        low++;
        high--;
    }
}

int main()
{
    int i,a[]={1,2,3,4,5};
    int len=5;
    printf("ԭ����:\n");
    for(i=0;i<len;i++)
        printf("%3d",a[i]);
    reverse(a,0,len-1);
    printf("\n���ú������:\n");
    for(i=0;i<len;i++)
        printf("%3d",a[i]);
    getche();
    return 0;
}