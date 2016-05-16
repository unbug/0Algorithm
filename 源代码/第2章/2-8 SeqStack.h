typedef struct stack
{
    DATA data[SIZE+1]; //数据元素 
    int top; //栈顶 
}SeqStack;
SeqStack *SeqStackInit()
{
    SeqStack *p;
    if(p=(SeqStack *)malloc(sizeof(SeqStack))) //申请栈内存 
    {
        p->top=0; //设置栈顶为0 
        return p;//返回指向栈的指针 
    }
    return NULL;
}
int SeqStackIsEmpty(SeqStack *s) //判断栈是否为空 
{
    return(s->top==0);
}
void SeqStackFree(SeqStack *s) //释放栈所占用空间 
{
    if(s)
        free(s);
}
void SeqStackClear(SeqStack *s)  //清空栈 
{
    s->top=0;
} 
int SeqStackIsFull(SeqStack *s) //判断栈是否已满
{
    return(s->top==SIZE);
} 
int SeqStackPush(SeqStack *s,DATA data) //入栈操作 
{
     if((s->top+1)>SIZE)
     {
         printf("栈溢出!\n"); 
         return 0;
     }
     s->data[++s->top]=data;//将元素入栈
     return 1; 
}
DATA SeqStackPop(SeqStack *s) //出栈操作 
{
     if(s->top==0)
     {
         printf("栈为空！");
         exit(0);
     }
     return (s->data[s->top--]);
}
DATA SeqStackPeek(SeqStack *s) //读栈顶数据
{
     if(s->top==0)
     {
         printf("栈为空！");
         exit(0);
     }
     return (s->data[s->top]);
} 
