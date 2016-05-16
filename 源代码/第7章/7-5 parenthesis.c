#include <stdio.h>
#define MAXLENGTH 80   //最大字符串长度 
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

void ParenthesisMatch(char *expr)
{
    SqStack s;
    int i,len,no;
    if(!StackInit(&s)) //初始化栈失败 
        exit(0);//退出
    len=strlen(expr); //取字符串长度
    for(i=1;i<=len;i++)
    {
        if(expr[i-1]=='(')
            PUSH(&s,i); //左插号位置序号入栈 
        else if(expr[i-1]==')')
        {
            if(POP(&s,&no))
                printf("括号配对:%d -- %d\n", no,i);
            else
                printf("没有左括号与位于第%d个位置的右侧号配对!\n",i); 
        } 
    }
    while(StackLength(&s)>0) //若栈中还有数据，表示还有左括号没配对 
    {
        POP(&s,&no);
        printf("位于第%d位置的左括号没有配对的右括号!\n", no);           
    }
    StackFree(&s);                                        //释放栈        
}
int main()
{
    char expr[MAXLENGTH];
    printf("输入一个带括号的表达式(长度不超过%d个字符):\n",MAXLENGTH); 
    scanf("%s",expr);
    ParenthesisMatch(expr);
    
    getch();
    return 0;
}
