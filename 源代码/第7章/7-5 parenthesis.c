#include <stdio.h>
#define MAXLENGTH 80   //����ַ������� 
#define STACK_INIT_SIZE  100
#define SIZE_INCREMENT  5
typedef struct //ջ�ṹ 
{
    int *base; //ջ�� 
    int *top; //ջ�� 
    int stacksize; //ջ��С 
}SqStack,*SQSTACK;
int StackInit(SQSTACK s) //��ʼ��ջ 
{
    s->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!(s->base))
        exit(0);
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
    return 1;
}
int PUSH(SQSTACK s,int e) //��ջ 
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
int POP(SQSTACK s,int *p) //��ջ 
{
    if(s->base==s->top) //��ջ 
        return 0;
     *p=*(s->top-1);
     s->top--;
     return 1;
}
int StackLength(SQSTACK s) //ջ�ĳ���(Ԫ������) 
{
    return (s->top-s->base);
}
int StackFree(SQSTACK s) //�ͷ�ջ 
{
    free(s->base);
    s->top=s->base=NULL;
    return 1;
}

void ParenthesisMatch(char *expr)
{
    SqStack s;
    int i,len,no;
    if(!StackInit(&s)) //��ʼ��ջʧ�� 
        exit(0);//�˳�
    len=strlen(expr); //ȡ�ַ�������
    for(i=1;i<=len;i++)
    {
        if(expr[i-1]=='(')
            PUSH(&s,i); //����λ�������ջ 
        else if(expr[i-1]==')')
        {
            if(POP(&s,&no))
                printf("�������:%d -- %d\n", no,i);
            else
                printf("û����������λ�ڵ�%d��λ�õ��Ҳ�����!\n",i); 
        } 
    }
    while(StackLength(&s)>0) //��ջ�л������ݣ���ʾ����������û��� 
    {
        POP(&s,&no);
        printf("λ�ڵ�%dλ�õ�������û����Ե�������!\n", no);           
    }
    StackFree(&s);                                        //�ͷ�ջ        
}
int main()
{
    char expr[MAXLENGTH];
    printf("����һ�������ŵı��ʽ(���Ȳ�����%d���ַ�):\n",MAXLENGTH); 
    scanf("%s",expr);
    ParenthesisMatch(expr);
    
    getch();
    return 0;
}
