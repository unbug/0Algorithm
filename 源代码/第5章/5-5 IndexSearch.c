#include <stdio.h>
#define INDEXTABLE_LEN 3
#define TABLE_LEN 30
typedef struct item
{
    int index;    //����ֵ 
    int start;    //��ʼλ�� 
    int length;   //�ӱ��� 
}INDEXITEM;
//������������ 
long stu[TABLE_LEN]={
     1080101,1080102,1080103,1080104,1080105,1080106,0,0,0,0,
     1080201,1080202,1080203,1080204,0,0,0,0,0,0,
     1080301,1080302,1080303,1080304,0,0,0,0,0,0};
//���������� 
INDEXITEM indextable[INDEXTABLE_LEN]={
    {10801,0,6},
    {10802,10,4},
    {10803,20,4}};
int IndexSearch(int key) //���������� 
{
    int i,index1,start,length;
    index1=key/100;//��������ֵ
    for(i=0;i<INDEXTABLE_LEN;i++) //���������в�������ֵ 
    {
        if(indextable[i].index==index1) //�ҵ�����ֵ 
        {
            start=indextable[i].start; //��ȡ���鿪ʼ��� 
            length=indextable[i].length; //��ȡԪ�س��� 
            break; //����ѭ�� 
        }
    }
    if(i>=INDEXTABLE_LEN)
        return -1;//�������в���ʧ�� 
    for(i=start;i<start+length;i++)
    {
        if(stu[i]==key) //�ҵ��ؼ��� 
            return i; //������� 
    }
    return -1; //����ʧ�ܣ�����-1 
}
int InsertNode(key)
{
    int i,index1,start,length;
    index1=key/100;//��������ֵ
    for(i=0;i<INDEXTABLE_LEN;i++) //���������в�������ֵ 
    {
        if(indextable[i].index==index1) //�ҵ�����ֵ 
        {
            start=indextable[i].start; //��ȡ���鿪ʼ��� 
            length=indextable[i].length; //��ȡԪ�س��� 
            break; //����ѭ�� 
        }
    }
    for(i=0;i<INDEXTABLE_LEN;i++) //���������в�������ֵ 
    {
        if(indextable[i].index==index1) //�ҵ�����ֵ 
        {
            start=indextable[i].start; //��ȡ���鿪ʼ��� 
            length=indextable[i].length; //��ȡԪ�س��� 
            break; //����ѭ�� 
        }
    }
    if(i>=INDEXTABLE_LEN)
        return -1;//�������в���ʧ��     
    stu[start+length]=key;//����ؼ��ֵ����� 
    indextable[i].length++;//�޸��������е��ӱ���
    return 0;    
}

int main()
{
    long key;
    int i,pos;
    printf("ԭ����:"); 
    for(i=0;i<TABLE_LEN;i++)
        printf("%ld ",stu[i]);
    printf("\n");
    printf("������ҹؼ���:");
    scanf("%ld",&key);
    pos=IndexSearch(key);
    if(pos>0)
        printf("���ҳɹ�,�ùؼ���λ������ĵ�%d��λ�á�\n",pos);
    else
        printf("����ʧ��!\n");
    printf("�������ؼ���:");
    scanf("%ld",&key);
    if(InsertNode(key)==-1)
        printf("��������ʧ��!\n");
    else
    {
        for(i=0;i<TABLE_LEN;i++)
            printf("%ld ",stu[i]);
        printf("\n");
    }    
    getch();
    return 0;
}
