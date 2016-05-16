#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
typedef struct
{
    char name[15];
    int age;
}DATA;
#include "2-11 SeqStack.h"
int main()
{
    SeqStack *stack;
    DATA data,data1;    
    stack=SeqStackInit();  //初始化栈
    printf("入栈操作：\n");
    printf("输入姓名 年龄进行入栈操作:"); 
    scanf("%s%d",data.name,&data.age);
    SeqStackPush(stack,data);
    printf("输入姓名 年龄进行入栈操作:"); 
    scanf("%s%d",data.name,&data.age);
    SeqStackPush(stack,data);
    printf("\n出栈操作：\n按任意键进行出栈操作:");
    getch();
    
    data1=SeqStackPop(stack);
    printf("出栈的数据是(%s,%d)\n" ,data1.name,data1.age);        
    printf("再按任意键进行出栈操作:");
    getch();
    
    data1=SeqStackPop(stack);
    printf("出栈的数据是(%s,%d)\n" ,data1.name,data1.age); 
    SeqStackFree(stack); //释放栈所占用的空间 
    getch();
    return 0;
}
