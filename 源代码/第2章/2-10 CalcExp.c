#include<stdio.h> 
#include<stdlib.h>
#define SIZE 50
typedef int DATA;
#include "2-11 SeqStack.h"
int IsOperator(char c) //检查字符是否为运算符 
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
int PRI(char oper1,char oper2) //判断两个运算符的优先级
// oper1>oper2返回1 
//oper1<oper2返回-1
//oper1=oper2返回0 
{
    int pri;
    switch(oper2) //判断运算符优先级 
    {
        case '+':
        case '-':
            if(oper1=='('||oper1=='=') //为左括号或表达式开始符号 
                pri=-1; //返回小于 
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
            if(oper1==')') //右括号右侧不能马上出现左括号 
            {
                printf("语法错误!\n");
                exit(0);
            }else
                pri=-1;
            break;
        case')':
            if(oper1=='(')
                pri=0;
            else if (oper1=='=')
            {
                printf("括号不匹配!\n");
                exit(0);
            }else
                pri=1;
            break;
        case '=' :
            if(oper1=='(')
            {
                printf("括号不匹配!\n");
                exit(0);
            }else if(oper1=='=')
                pri=0;
            else
                pri=1;
            break;
    }
    return pri; 
}
int Calc(int a,int oper,int b) //计算两个操作数的结果 
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
                printf("除0溢出!\n");
                exit(0); 
            }  
    }
} 
int CalcExp(char exp[]) //表达式计算函数 
{
    SeqStack *StackOper,*StackData;
    int i=0,flag=0;
    DATA a,b,c,q,x,t,oper;
    
    StackOper=SeqStackInit(); //初始化两个栈 
    StackData=SeqStackInit();

    q=0;
    x='=';
    SeqStackPush(StackOper,x); //首先将等号(=)进入操作符栈 
    x=SeqStackPeek(StackOper); //获取操作符栈的首元素  
    c=exp[i++];
    while(c!='=' || x!='=')
    {
        if(IsOperator(c)) //若输入的是运算符 
        {
            if(flag){
                SeqStackPush(StackData,q);//将操作数入栈 
                q=0;
                flag=0;
            }
            switch(PRI(x,c)) //判断运算符的优先级 
            {
                case -1:
                    SeqStackPush(StackOper,c);//运算符进栈 
                    c=exp[i++];
                    break;
                case 0:
                    c=SeqStackPop(StackOper); //运算符出栈 (抛弃)
                    c=exp[i++];
                    break;
                case 1:
                    oper=SeqStackPop(StackOper); //运算符出栈 
                    b=SeqStackPop(StackData);//两个操作数出栈 
                    a=SeqStackPop(StackData);
                    t=Calc(a,oper,b);
                    SeqStackPush(StackData,t);//将运算结果入栈 
                    break;
            }
        }else if(c>='0'&&c<='9') //若输入字符在0~9之间 
        {
            c-='0';
            q=q*10+c;
            c=exp[i++];
            flag=1;
        }
        else
        {
            printf("输入错误!\n");
            getch();
            exit(0);
        }
        x=SeqStackPeek(StackOper);//获取栈顶的运算符 
    }
    q=SeqStackPop(StackData);
    SeqStackFree(StackOper); 	//释放栈所占用的空间 
    SeqStackFree(StackData);
    return q; //出栈，返回结果 
} 

int main() 
{
    int c;
    char exp[80];
    printf("请输入要计算的表达式(以=结束):"); 
    scanf("%s",exp);
    printf("%s%d\n",exp,CalcExp(exp));
    getch();
    return 0;
}
