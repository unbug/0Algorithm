#include <stdio.h>
#include "4-1 CreateData.c"	//生成随机数的函数
#define ARRAYLEN 10	//需要排序的数据元素数量
void ShellSort(int a[],int n)//希尔排序 
{
    int d,i,j,x;
    d=n/2;
    while(d>=1) //循环至增量为1时结束 
    {
        for(i=d;i<n;i++)
        {
            x=a[i]; //获取序列中的下一个数据 
            j=i-d; //序列中前一个数据的序号 
            while(j>=0 && a[j]>x) //下一个数大于前一个数 
            {
                a[j+d]=a[j]; //将后一个数向前移动 
                j=j-d; //修改序号，继续向前比较 
            }
            a[j+d]=x; //保存数据 
        }
        d/=2;  //缩小增量 
    }
}
int main()
{
    int i,a[ARRAYLEN];	//定义数组
    for(i=0;i<ARRAYLEN;i++)	//清空数组
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))	//判断生成随机数是否成功
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 	//输出生成的随机数
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    ShellSort(a,ARRAYLEN);	//调用希尔排序函数
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)	//输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
