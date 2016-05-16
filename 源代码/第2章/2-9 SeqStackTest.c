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
    stack=SeqStackInit();  //��ʼ��ջ
    printf("��ջ������\n");
    printf("�������� ���������ջ����:"); 
    scanf("%s%d",data.name,&data.age);
    SeqStackPush(stack,data);
    printf("�������� ���������ջ����:"); 
    scanf("%s%d",data.name,&data.age);
    SeqStackPush(stack,data);
    printf("\n��ջ������\n����������г�ջ����:");
    getch();
    
    data1=SeqStackPop(stack);
    printf("��ջ��������(%s,%d)\n" ,data1.name,data1.age);        
    printf("�ٰ���������г�ջ����:");
    getch();
    
    data1=SeqStackPop(stack);
    printf("��ջ��������(%s,%d)\n" ,data1.name,data1.age); 
    SeqStackFree(stack); //�ͷ�ջ��ռ�õĿռ� 
    getch();
    return 0;
}
