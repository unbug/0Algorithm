#include <stdio.h>
#define HASH_LEN 18
#define TABLE_LEN 15

int data[TABLE_LEN]={75, 85, 7, 13, 9, 10, 19,91, 21, 37, 56, 64, 80, 33, 88}; //ԭʼ���� 
int hash[HASH_LEN]={0};//��ϣ����ʼ��Ϊ0 

void InsertHash(int hash[],int m,int data) //���ؼ���data�����ϣ��hash�� 
{
    int i;
    i=data % 13;//�����ϣ��ַ 
    while(hash[i]) //Ԫ��λ���ѱ�ռ��
        i=(++i) % m; //����̽�ⷨ�����ͻ
    hash[i]=data;
}
void CreateHash(int hash[],int m,int data[],int n)
{
    int i;
    for(i=0;i<n;i++) //ѭ����ԭʼ���ݱ��浽��ϣ���� 
        InsertHash(hash,m,data[i]); 
}
int HashSearch(int hash[],int m,int key)
{
    int i;
    i=key % 13;//�����ϣ��ַ 
    while(hash[i] && hash[i]!=key) //�ж��Ƿ��ͻ 
        i=(++i) % m; //����̽�ⷨ�����ͻ
    if(hash[i]==0) //���ҵ����ŵ�Ԫ����ʾ����ʧ�� 
        return -1;//����ʧ��ֵ 
    else//���ҳɹ� 
        return i;//���ض�ӦԪ�ص��±� 
}
int main()
{
    int i;
    CreateHash(hash,HASH_LEN,data,TABLE_LEN);//���ú���������ϣ�� 
    printf("��ϣ���Ԫ�ص�ֵ:"); 
    for(i=0;i<HASH_LEN;i++)
        printf("%ld ",hash[i]);

    getch();
    return 0;
}