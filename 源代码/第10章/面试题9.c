#include "stdio.h"

int DelElem(int Sqlist[],int *len,int i)
{
    int j;
    if(i<1||i>*len)
        return 0;						//非法删除
    for(j=i;j<*len;j++)
        Sqlist[j-1]=Sqlist[j];			//将第i位置以后的元素依次前移
    *len = *len-1;						//表长减1
    return 1;
}

void DelRepeat(int a[],int *len)
{
   int i=0,j;
   while(i<*len)
   {
        j = i + 1;			//从第i个元素的下一个元素开始与第i个元素逐一比较
        while(j<*len)
        {
            if(a[i] == a[j])        //如果第j个位置的元素重复，删除之
            {
                DelElem(a,len,j+1);
            }
            else
            {
                j++;                //否则继续比较下一个元素
            }
        }
        i++;
   }
}

int main()
{
    int i,a[]={5,6,7,6};
    int len = 4;    
    
    printf("原数组有以下 %d 个元素:\n",len);
    for(i=0;i<len;i++)
        printf("%3d",a[i]);
    
    DelRepeat(a,&len);
    
    printf("\n处理后的数组有以下 %d 个元素:\n",len);       
    for(i=0;i<len;i++)
        printf("%3d",a[i]);

    getche();
    return 0;
}