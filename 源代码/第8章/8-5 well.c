#include <stdio.h>
int main()
{
    int len1,len2,len3,len4,len5,len,flag;
    flag=1; //ѭ����־���� 
    len5=0;
    while(flag)
    {
        len5+=4; //len5Ϊ4�ı���
        len1=0;
        while(flag)
        {
            len1+=5;//len1Ϊ5�ı��� 
            len4=len5+len1/5;//���Ҿ������� 
            len3=len4+len5/4;//���Ҿ������� 
            if(len3%2) //�����ܱ�2���� 
                continue; 
            if(len4%3)  //�����ܱ�3���� 
                continue;
            len2=len3+len4/3;
            if(len2+len3/2<len1) //���������� 
                break;
            if(len2+len3/2==len1) //�������� 
                flag=0;
        }
    }
    len=2*len1+len2; //����� 
    printf("���Ҿ������ȷֱ�Ϊ:\n");
    printf("��:%d\n",len1);
    printf("��:%d\n",len2);
    printf("��:%d\n",len3);
    printf("��:%d\n",len4);
    printf("��:%d\n",len5);
    printf("����:%d\n",len);
    getch();
    return 0;
}
