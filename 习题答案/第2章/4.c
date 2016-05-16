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

int main()
{
    int new1;
    char select='N',*other,str[80]; //符号
    unsigned long num10; //保存10进制数 
    char array[32];
    do{
        printf("输入10进制数:");
        scanf("%d",&num10); //保存字符串 
        printf("需转换的进制:");
        scanf("%d",&new1);
        other=DecToOther(num10,new1);
        printf("将 10进制数 %d 转换为 %d进制数:%s\n",num10,new1,other);
        printf("\n继续(Y/N)?");
        select=getch();
    }while(select=='y' || select =='Y');
    getch();
    return 0;
}
