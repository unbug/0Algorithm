#include<stdio.h> 
#include<stdlib.h>
#define SIZE 50
typedef int DATA;
#include "2-11 SeqStack.h"
int IsOperator(char c) //����ַ��Ƿ�Ϊ����� 
{
    switch(c)
    {
        case'+':
        case'-':
        case'*':
        case'/':
        case'(':
        case')':
        case'=':
            return 1;
            break;
        default:
            return 0;
            break;
    } 
} 
int PRI(char oper1,char oper2) //�ж���������������ȼ�
// oper1>oper2����1 
//oper1<oper2����-1
//oper1=oper2����0 
{
    int pri;
    switch(oper2) //�ж���������ȼ� 
    {
        case '+':
        case '-':
            if(oper1=='('||oper1=='=') //Ϊ�����Ż���ʽ��ʼ���� 
                pri=-1; //����С�� 
            else 
                pri=1;
            break;
        case '*':
        case '/':
            if(oper1=='*'||oper1=='/'||oper1==')')
                pri=1;
            else
                pri=-1;
            break;
        case '(':
            if(oper1==')') //�������Ҳ಻�����ϳ��������� 
            {
                printf("�﷨����!\n");
                exit(0);
            }else
                pri=-1;
            break;
        case')':
            if(oper1=='(')
                pri=0;
            else if (oper1=='=')
            {
                printf("���Ų�ƥ��!\n");
                exit(0);
            }else
                pri=1;
            break;
        case '=' :
            if(oper1=='(')
            {
                printf("���Ų�ƥ��!\n");
                exit(0);
            }else if(oper1=='=')
                pri=0;
            else
                pri=1;
            break;
    }
    return pri; 
}
int Calc(int a,int oper,int b) //���������������Ľ�� 
{
    switch(oper)
    {
        case'+':return a+b;
        case'-':return a-b;
        case'*':return a*b;
        case'/':
            if(b!=0)
               return a/b;
            else
            {
                printf("��0���!\n");
                exit(0); 
            }  
    }
} 
int CalcExp(char exp[]) //���ʽ���㺯�� 
{
    SeqStack *StackOper,*StackData;
    int i=0,flag=0;
    DATA a,b,c,q,x,t,oper;
    
    StackOper=SeqStackInit(); //��ʼ������ջ 
    StackData=SeqStackInit();

    q=0;
    x='=';
    SeqStackPush(StackOper,x); //���Ƚ��Ⱥ�(=)���������ջ 
    x=SeqStackPeek(StackOper); //��ȡ������ջ����Ԫ��  
    c=exp[i++];
    while(c!='=' || x!='=')
    {
        if(IsOperator(c)) //�������������� 
        {
            if(flag){
                SeqStackPush(StackData,q);//����������ջ 
                q=0;
                flag=0;
            }
            switch(PRI(x,c)) //�ж�����������ȼ� 
            {
                case -1:
                    SeqStackPush(StackOper,c);//�������ջ 
                    c=exp[i++];
                    break;
                case 0:
                    c=SeqStackPop(StackOper); //�������ջ (����)
                    c=exp[i++];
                    break;
                case 1:
                    oper=SeqStackPop(StackOper); //�������ջ 
                    b=SeqStackPop(StackData);//������������ջ 
                    a=SeqStackPop(StackData);
                    t=Calc(a,oper,b);
                    SeqStackPush(StackData,t);//����������ջ 
                    break;
            }
        }else if(c>='0'&&c<='9') //�������ַ���0~9֮�� 
        {
            c-='0';
            q=q*10+c;
            c=exp[i++];
            flag=1;
        }
        else
        {
            printf("�������!\n");
            getch();
            exit(0);
        }
        x=SeqStackPeek(StackOper);//��ȡջ��������� 
    }
    q=SeqStackPop(StackData);
    SeqStackFree(StackOper); 	//�ͷ�ջ��ռ�õĿռ� 
    SeqStackFree(StackData);
    return q; //��ջ�����ؽ�� 
} 

int main() 
{
    int c;
    char exp[80];
    printf("������Ҫ����ı��ʽ(��=����):"); 
    scanf("%s",exp);
    printf("%s%d\n",exp,CalcExp(exp));
    getch();
    return 0;
}
