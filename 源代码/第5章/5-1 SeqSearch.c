#include <stdio.h>
#define ARRAYLEN 8
int source[]={69,65,90,37,92,6,28,54};

int SeqSearch(int s[],int n,int key)
{
    int i;
    for(i=0;i<n && s[i]!=key;i++)
        ;
    if(i<n)
        return i;
    else
        return -1;
}

int main()
{
    int key,i,pos;
    printf("������ؼ���:");
    scanf("%d",&key);    
    pos=SeqSearch(source,ARRAYLEN,key);
    printf("ԭ���ݱ�:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)
        printf("���ҳɹ����ùؼ���λ������ĵ�%d��λ�á�\n",pos);
    else
        printf("����ʧ��!\n");
    getch();
    return 0;
}
