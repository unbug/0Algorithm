typedef struct stack
{
    DATA data[SIZE+1]; //����Ԫ�� 
    int top; //ջ�� 
}SeqStack;
SeqStack *SeqStackInit()
{
    SeqStack *p;
    if(p=(SeqStack *)malloc(sizeof(SeqStack))) //����ջ�ڴ� 
    {
        p->top=0; //����ջ��Ϊ0 
        return p;//����ָ��ջ��ָ�� 
    }
    return NULL;
}
int SeqStackIsEmpty(SeqStack *s) //�ж�ջ�Ƿ�Ϊ�� 
{
    return(s->top==0);
}
void SeqStackFree(SeqStack *s) //�ͷ�ջ��ռ�ÿռ� 
{
    if(s)
        free(s);
}
void SeqStackClear(SeqStack *s)  //���ջ 
{
    s->top=0;
} 
int SeqStackIsFull(SeqStack *s) //�ж�ջ�Ƿ�����
{
    return(s->top==SIZE);
} 
int SeqStackPush(SeqStack *s,DATA data) //��ջ���� 
{
     if((s->top+1)>SIZE)
     {
         printf("ջ���!\n"); 
         return 0;
     }
     s->data[++s->top]=data;//��Ԫ����ջ
     return 1; 
}
DATA SeqStackPop(SeqStack *s) //��ջ���� 
{
     if(s->top==0)
     {
         printf("ջΪ�գ�");
         exit(0);
     }
     return (s->data[s->top--]);
}
DATA SeqStackPeek(SeqStack *s) //��ջ������
{
     if(s->top==0)
     {
         printf("ջΪ�գ�");
         exit(0);
     }
     return (s->data[s->top]);
} 
