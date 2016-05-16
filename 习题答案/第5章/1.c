#include <stdio.h>
#define ARRAYLEN 15

int source[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};

int BinarySearch(int s[],int n,int key)
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)        //查找范围含含至少一个元素 
    {
        mid=(low+high)/2;   //计算中间位置序号 
        if(s[mid]==key)      //中间元素与关键字相等 
            return mid;      //返回序号 
        else if(s[mid]>key)  //中间元素大于关键字 
            high=mid-1;     //重定义查找范围 
        else                 //中间元素小于关键字 
            low=mid+1;       //重定义查找范围 
    }
    return -1;               //返回查找失败 
}

int main()
{
    int key,i,pos;
    printf("请输入关键字:");
    scanf("%d",&key); 
    pos=BinarySearch(source,ARRAYLEN,key);
    printf("原数据表:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)
        printf("查找成功，该关键字位于数组的第%d个位置。\n",pos);
    else
        printf("查找失败!\n");
    getch();
    return 0;
}
