#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE  100
#define SIZE_INCREMENT  5
typedef struct //栈结构 
{
    int *base; //栈底 
    int *top; //栈顶 
    int stacksize; //栈大小 
}SqStack,*SQSTACK;
int StackInit(SQSTACK s) //初始化栈 
{
    s->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!(s->base))
        exit(0);
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
    return 1;
}
int PUSH(SQSTACK s,int e) //入栈 
{
    if(s->base+s->stacksize==s->top)
    {
        s->base=(int *)realloc(s->base,(SIZE_INCREMENT+s->stacksize)*sizeof(int));
        s->top=s->base+s->stacksize;
        s->stacksize+=SIZE_INCREMENT;
    }
    *(s->top)=e;
     s->top+=1;
     return 1;
}
int POP(SQSTACK s,int *p) //出栈 
{
    if(s->base==s->top) //空栈 
        return 0;
     *p=*(s->top-1);
     s->top--;
     return 1;
}
int StackLength(SQSTACK s) //栈的长度(元素数量) 
{
    return (s->top-s->base);
}
int StackFree(SQSTACK s) //释放栈 
{
    free(s->base);
    s->top=s->base=NULL;
    return 1;
}
char *DecToOther(unsigned long num,int sys) //10进制转换为其他进制，返回一个字符串 
{//num需转换的数据,sys为需转换的进制 
    SqStack s;
    int rem,i,length,num1,inc=1;
    char *out,*p; //控制输出字符串 
    if(!StackInit(&s)) //初始化栈失败 
        exit(0);//退出
    do{
        if(num<sys) //被除数小于进制 
        {
            rem=num;
            PUSH(&s,rem); //进接将被除数入栈 
            break;//退出循环 
        }
        else
        {
            rem=num % sys; //除进制数取余数 
            PUSH(&s,rem); //将余数入栈 
            num=(num-rem)/sys; //商
        }
    }while(num); //dividend不为0
    if(sys==16) //16进制有两个字符的前缀 
        inc++;
    length=StackLength(&s); //获取栈的长度(需输出元素的个数) 
    if(!(out=(char *)malloc(sizeof(char)*(length+inc))))//若分配内存失败
    {
        printf("内存分配失败!\n");
        exit(0);
    } 
    p=out; //指针p指向分配内存首地址 
    *p++='0';//添加前缀    
    if(sys==16) //16进制的前缀 
        *p++='x';
    for(i=1;i<=length;i++)
    {
        POP(&s,&num1); //从栈中弹出一个数 
        if(num1<10) //若小于10
            *p++=num1+'0'; //保存数字的ASCII字符 
        else //大于10，输出A~F 
            *p++=num1+'A'-10;//输出A~F之间的字母 
    }
    StackFree(&s); //释放栈所占用空间 
    *p='\0';
    return (out);//返回字符串 
}
int OtherToDec(int sys,char *in_str) //其他进制转换为10进制(输入数)
{ //sys进制,arrat_char需处理的字符串 
    int i,j,length,start=0;
    unsigned long sum=0,pow;
    int *in_bit;
       
    length=strlen(in_str); //字符串的长度 
    if(!(in_bit=(int *)malloc(sizeof(int)*length)))
    {
        printf("内存分配失败!\n");
        exit(0); 
    }
    if(in_str[0]=='-') //为负数，跳过符号 
        start++;
    j=0;
    for(i=length-1;i>=start;i--)
    {
        if(in_str[i]>='0' && in_str[i]<='9') //为数字0~9 
            in_bit[j]=in_str[i]-'0'; //将字符转换为整数 
        else if(in_str[i]>='A' && in_str[i]<='F') //大写字母 A~F
            in_bit[j]=in_str[i]-'A'+10;
        else if(in_str[i]>='a' && in_str[i]<='f') //小写字母 a~f
            in_bit[j]=in_str[i]-'a'+10;
        else
            exit(0);
        j++;
    }
    length-=start; 
    for(i=0;i<length;i++)
    {
        if(in_bit[i]>=sys) //若某个数超过了进制 
        {
            printf("输入的数据不符合%d进制数据的规则!",sys); //显示错误 
            exit(0);
        }
        for(j=1,pow=1;j<=i;j++)
            pow*=sys;
        sum+=in_bit[i]*pow;
    }
    return sum;
}

int main()
{
    int old,new1;
    char select='N',*other,str[80]; //符号
    unsigned long num10; //保存10进制数 
    char array[32];
    do{
        printf("\n原数据进制:");
        scanf("%d",&old);
        printf("输入%d进制数:",old);
        scanf("%s",str); //保存字符串 
        num10=OtherToDec(old,str); //将其他进制转换为10进制 
        printf("需转换的进制:");
        scanf("%d",&new1);
        if(10==new1) //若是转换为10进制 
        {
            printf("\n将%d进制数%s\n转换为10进制数:%d\n",old,str,num10); 
        }
        else
        {
            other=DecToOther(num10,new1);
            printf("将%d进制数%s\n转换为%d进制数:%s\n",old,str,new1,other);
        }
        printf("\n继续(Y/N)?");
        select=getch();
    }while(select=='y' || select =='Y');
    getch();
    return 0;
}
