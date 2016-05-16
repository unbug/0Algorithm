#include <stdio.h>
int main()
{
    int len,i;//len小数长度 
    int numerator=1,denominator=3,result,carry;
    int flag=1,count=0; //继续迭代的标志及迭代的次数 
    char *pi,*temp; //指向保存pi值和临时计算结果的数据 
    printf("输入小数位数:");
    scanf("%d",&len);
    len+=2; //增加2位 
    if(!(pi=(char *)malloc(sizeof(char)*len))) //分配保存pi值的内存
    {
        printf("分配内存失败!\n");
        exit(0); 
    }
    if(!(temp=(char *)malloc(sizeof(char)*len))) //分配保存临时值的内存
    {
        printf("分配内存失败!\n");
        exit(0); 
    } 
    for(i=0;i<len;i++)//初始化数组 
        pi[i]=temp[i]=0;
    pi[1]=2; //置初值 
    temp[1]=2;
    while(flag && (++count<2147483647)) //int的最大值是2147483647
    {
        carry=0;
        for(i=len-1;i>0;i--)//从低位到高位相乘 
        {
            result=temp[i]*numerator+carry; //用每一位去乘 
            temp[i]=result%10; //保存个数 
            carry=result/10; //进位 
        }
        carry=0;
        for(i=0;i<len;i++) //由高到低进行除法运算 
        {
            result=temp[i]+carry*10; //当前位加上前一位的余数 
            temp[i]=result/denominator; //当前位的整数部分 
            carry=result%denominator; //当前位的余数，累加到下一位的运算 
        }
        flag=0; //清除标志 
        for(i=len-1;i>0;i--) //由低位到高位，将计算结果累加 
        {
            result=pi[i]+temp[i]; //将计算结果累加到x中 
            pi[i]=result%10; //保留一位数 
            pi[i-1]+=result/10; //向高位进位 
            flag|=temp[i];//若temp中的数全部为0，退出循环 
        }
        numerator++; //累加分子 
        denominator+=2; //累加分母 
    }
    printf("\n计算了%d次\n",count); //输出迭代次数 
    printf("\t---第1-1000位小数---\n");
    printf("PI=%d.",pi[1]);//输出整数部分 
    for(i=2;i<len;i++)
    {
        if((i>2) && (i-2)%10==0) //每10位小数间加一个空格 
            printf(" ");
        if((i>2) && (i-2)%50==0) //每50位小数换行 
            printf("\n");
        if(i>2 && (i-2) % 1000 ==0)//第1000位小数显示一个提示
        {             
            printf("\t---按任意键显示第%d-%d位小数---\n",(i-2)/1000*1000+1,((i-2)/1000+1)*1000);
            getch();
        }
        printf("%d",(int)pi[i]);
    } 
    getch();
    return 0;
}
