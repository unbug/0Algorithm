#include <stdio.h>
int main()
{
     int oldprice,price=0,i=0;
     printf("������������Ʒ����ʵ�۸�:");
     scanf("%d",&oldprice);
     system("cls");
     printf("�������Բµļ۸�:\n");
     while(oldprice!=price)
     {
        i++;
        printf("������:"); 
        scanf("%d",&price);
        printf("������:") ;
        if(price>oldprice)
        {
            printf("����\n");                  
        }
        else if(price<oldprice)
        {
            printf("����\n");
        }
        else
        {
            printf("��ϲ�㣬����ˣ�����Ʒ��������!\n\n��һ���Բ���%d��.\n",i);
        }
     }
     getch();
     return 0;    
}
