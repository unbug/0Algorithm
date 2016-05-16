#include <stdio.h>
typedef struct
{
    char key[15];  //���Ĺؼ��� 
    char name[20];
    int age;
} DATA;    //���������ͣ��ɶ���Ϊ�����ͣ�Ҳ�ɶ���Ϊ�ṹ
#include "2-1 SeqList.h"
#include "2-2 SeqList.c"
int SeqListAll(SeqListType *SL)  //����˳����еĽ�� 
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
        printf("(%s,%s,%d)\n",SL->ListData[i].key,SL->ListData[i].name,SL->ListData[i].age);
}
int main()
{
	int i;
    SeqListType SL;         //����˳������ 
    DATA data,*data1;       //�����㱣���������ͱ�����ָ����� 
    char key[15];           //����ؼ��� 

    SeqListInit(&SL);       //��ʼ��˳��� 

    do {                    //ѭ����ӽ������ 
        printf("������ӵĽ��(ѧ�� ���� ����)��"); 
        fflush(stdin);              //������뻺���� 
        scanf("%s%s%d",&data.key,&data.name,&data.age); 
        if(data.age)                                    //�����䲻Ϊ0 
        {
            if(!SeqListAdd(&SL,data))                   //����ӽ��ʧ�� 
                break;                                  //�˳���ѭ�� 
        }else   //������Ϊ0 
            break;          //�˳���ѭ�� 
    }while(1);
    printf("\n˳����еĽ��˳��Ϊ��\n");
    SeqListAll(&SL);                     //��ʾ���н������ 
    
    fflush(stdin);                       //������뻺���� 
    printf("\nҪȡ��������ţ�");
    scanf("%d",&i);                 //�����ռ�����    
    data1=SeqListFindByNum(&SL,i);  //����Ų��ҽ�� 
    if(data1)                       //�����صĽ��ָ�벻ΪNULL 
        printf("��%d�����Ϊ��(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);
    
    fflush(stdin);                                                             //������뻺���� 
    printf("\nҪ���ҽ��Ĺؼ��֣�");
    scanf("%s",key);  //����ؼ���     
    i=SeqListFindByCont(&SL,key);      //���ؼ��ֲ��� �����ؽ����� 
    data1=SeqListFindByNum(&SL,i);     //����Ų�ѯ�����ؽ��ָ�� 
    if(data1)                          //�����ָ�벻ΪNULL 
        printf("��%d�����Ϊ��(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);           
  	getch();
	return 0;
}

