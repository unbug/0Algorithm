#include <stdio.h>
#define HASH_LEN 13
#define TABLE_LEN 8
int data[TABLE_LEN]={69,65,90,37,92,6,28,54}; //ԭʼ���� 
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
    int key,i,pos;
    CreateHash(hash,HASH_LEN,data,TABLE_LEN);//���ú���������ϣ�� 
    printf("��ϣ���Ԫ�ص�ֵ:"); 
    for(i=0;i<HASH_LEN;i++)
        printf("%ld ",hash[i]);
    printf("\n");
    printf("������ҹؼ���:");
    scanf("%ld",&key);
    pos=HashSearch(hash,HASH_LEN,key); //���ú����ڹ�ϣ���в��� 
    if(pos>0)
        printf("���ҳɹ�,�ùؼ���λ������ĵ�%d��λ�á�\n",pos);
    else
        printf("����ʧ��!\n");
    getch();
    return 0;
}
