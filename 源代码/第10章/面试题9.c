#include "stdio.h"

int DelElem(int Sqlist[],int *len,int i)
{
    int j;
    if(i<1||i>*len)
        return 0;						//�Ƿ�ɾ��
    for(j=i;j<*len;j++)
        Sqlist[j-1]=Sqlist[j];			//����iλ���Ժ��Ԫ������ǰ��
    *len = *len-1;						//����1
    return 1;
}

void DelRepeat(int a[],int *len)
{
   int i=0,j;
   while(i<*len)
   {
        j = i + 1;			//�ӵ�i��Ԫ�ص���һ��Ԫ�ؿ�ʼ���i��Ԫ����һ�Ƚ�
        while(j<*len)
        {
            if(a[i] == a[j])        //�����j��λ�õ�Ԫ���ظ���ɾ��֮
            {
                DelElem(a,len,j+1);
            }
            else
            {
                j++;                //��������Ƚ���һ��Ԫ��
            }
        }
        i++;
   }
}

int main()
{
    int i,a[]={5,6,7,6};
    int len = 4;    
    
    printf("ԭ���������� %d ��Ԫ��:\n",len);
    for(i=0;i<len;i++)
        printf("%3d",a[i]);
    
    DelRepeat(a,&len);
    
    printf("\n���������������� %d ��Ԫ��:\n",len);       
    for(i=0;i<len;i++)
        printf("%3d",a[i]);

    getche();
    return 0;
}