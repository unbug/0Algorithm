#include <stdio.h>
#define MAX 15

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
    int a[]={7, 9, 10, 13, 19, 21,33, 37, 56, 64, 75, 80,85, 88,91};
    int i;
    
    ShellSort(a,MAX);	//调用希尔排序函数
    printf("排序结果:"); 
    for(i=0;i<MAX;i++)	//输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}