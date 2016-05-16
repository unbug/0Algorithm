#include <stdio.h>
#define MAXN 100  //最大变量数量 
int arr[MAXN][MAXN]; //保存增广矩阵 
int result[MAXN]; //保存方程的解
int unuse_result[MAXN];//判断是否是不确定的变元
int unuse_num;
void swap(int *a,int *b) //交换两数 
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int gcd(int a,int b) //返回最大公约数 
{
    int t;
    while(b!= 0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int lcm(int a,int b) //返回最小公倍数 
{
    return a*b/gcd(a,b);
}
void debug(int equ,int var)
{
     int i,j;
     for(i=0;i<equ;i++)
     {
         for(j=0;j<var+1;j++)
            printf("%d ",arr[i][j]);
         printf("\n");
     }
     printf("\n");
}
int Gauss(int equ,int var)
{
    int i,j,k,col;
    int max_r,ta,tb,lcm1;
    int temp,unuse_x_num,unuse_index;
    col=0; //设当前处理列的值为0，表示从第1列开始处理 
    for(k=0;k<equ && col<var;k++,col++) //循环处理矩阵中的行
    {    
        max_r=k; //绝对值最大行 
        for(i=k+1;i<equ;i++)
            if(abs(arr[i][col])>abs(arr[max_r][col]))
                max_r=i; //保存绝对值最大的行号 
        if(max_r!=k) //最大行不是当前行，则与第k行交换
            for(j=k;j<var+1;j++)
                swap(&arr[k][j], &arr[max_r][j]); //交换矩阵右上角数据 
        if(arr[k][col]==0) //说明col列第k行以下全是0了，则处理当前行的下一列
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++) //查找要删除的行
        {
            if(arr[i][col]!=0) //左列不为0，进行消元运算 
            {
                lcm1=lcm(abs(arr[i][col]),abs(arr[k][col])); //求最小公倍数 
                ta=lcm1/abs(arr[i][col]);
                tb=lcm1/abs(arr[k][col]);
                if(arr[i][col]*arr[k][col]<0) //相乘为负，表示两数符号不同 
                    tb=-tb; //异号的情况是两个数相加
                for(j=col;j<var+1;j++)                
                    arr[i][j]=arr[i][j]*ta-arr[k][j]*tb;
            }
        }
    }
    for(i=k;i<equ;i++)//判断最后一行最后一列，若不为0，表示无解
        if(arr[i][col]!=0) 
            return -1; //返回无解
     if(k<var)//自由变元有var-k个，即不确定的变元至少有var-k个.
    {
        for(i=k-1;i>=0;i--)
        {
            unuse_x_num=0; //判断该行中不确定变量数量，若超过1个，则无法求解
            for(j=0;j<var;j++)
            {
                if(arr[i][j]!=0 && unuse_result[j])
                {
                    unuse_x_num++;
                    unuse_index=j;
                }
            }
            if(unuse_x_num>1)
                continue; // 无法求解出确定的解 
            temp=arr[i][var];
            for(j=0;j<var;j++)
            {
                if(arr[i][j]!=0 && j!=unuse_index)
                    temp-=arr[i][j]*result[j];
            }
            result[unuse_index]=temp/arr[i][unuse_index]; // 求出该变元.
            unuse_result[unuse_index]=0; //该变元是确定的
        }
        return var-k; //自由变元有var-k个
    }
    for(i=var-1;i>=0;i--) //回代求解 
    {
        temp=arr[i][var];
        for(j=i+1;j<var;j++)
        {
            if(arr[i][j]!=0)
                temp-=arr[i][j]*result[j];
        }
        if(temp % arr[i][i]!=0) //若不能整除 
            return -2; //返回有浮点数解，但无整数解
        result[i]=temp/arr[i][i];
    }
    return 0;
}
int main()
{
    int i,j;
    int equ, var;
    printf("方程数:");
    scanf("%d",&equ); //输入方程数量
    printf("变量数:");
    scanf("%d",&var);  //输入变量数量 
    for(i=0;i<equ;i++) //循环输入各方程的系数 
    {
        printf("第%d个方程的系数:",i+1); 
        for(j=0;j<var+1;j++) //循环输入一个方程的系数 
        {
            scanf("%d", &arr[i][j]);
        }
    }
    unuse_num=Gauss(equ,var); //调用高斯函数 
    if(unuse_num==-1) //无解 
        printf("无解!\n");
    else if(unuse_num==-2) //只有浮点数解 
        printf("有浮点数解，无整数解!\n");
    else if(unuse_num>0) //无穷多解 
    {
         printf("无穷多解! 自由变量数量为%d\n",unuse_num);
         for(i=0;i<var;i++)
         {
             if(unuse_result[i])
                 printf("x%d 是不确定的\n",i+1);
             else
                 printf("x%d: %d\n",i+1,result[i]);
         }
    }
    else
    {
        for(i=0;i<var;i++) //输出解 
        {
            printf("x%d=%d\n",i+1,result[i]);
        }
    }
    printf("\n");
    getch();
    return 0;
}
