#include <stdio.h >
int iCount = 0;//��¼�����ŵ�ȫ�ֱ���
int Queens[8];//��¼�ʺ��ڸ����ϵķ���λ�õ�ȫ������
void Output()//���һ���⣬��һ��û�г�ͻ�ķ��÷���
{
   int i,j,flag=1;
   printf("��%2d�ַ���(���ʾ�ʺ�):\n", ++iCount);//�����š� 
   printf("  ");
   for(i=1;i<=8;i++)
       printf("�x");
   printf("\n");
   for (i = 0; i < 8; i++)
   {
       printf("��");
       for (j = 0; j < 8; j++)
       {
           if(Queens[i]-1 == j)
               printf("��");
           else
           {
               if (flag<0)
                   printf("  ");
               else
                   printf("��");               
           }
           flag=-1*flag;
       }
       printf("��\n");
       flag=-1*flag;
   }
   printf("  ");
   for(i=1;i<=8;i++)
       printf("��");
   printf("\n");  
   getch();
}
int IsValid(int n)//�ϵ�n���ʺ��Ƿ���ǰ��ʺ��гɹ���
{
   int i;
   for (i = 0; i < n; i++)//��n���ʺ���ǰ��n��1���ʺ�Ƚ� 
   {
 	  if (Queens[i] == Queens[n])//�����ʺ���ͬһ���ϣ�����0��
		 return 0;
 	  if (abs(Queens[i] - Queens[n]) == (n - i))//�����ʺ���ͬһ�Խ����ϣ�����0��
		 return 0;
   }
   return 1;//û�г�ͻ������1��
}
void Queen(int n)//�ڵ�n�з��ûʺ�
{
   int i;
   if (n == 8)//��8���ʺ��ѷ������
   {
	  Output(); //��� 
	  return;
   }
   for (i = 1; i <= 8; i++)//�ڵ�n�еĸ�������������̽
   { 
	  Queens[n] = i;//�ڸ��еĵ�i���Ϸ��ûʺ� 
	  if (IsValid(n))//û�г�ͻ���Ϳ�ʼ��һ�е���̽
		 Queen(n + 1); //�ݹ���ý�����һ�� 
   }
}
int main()
{ 
   printf("�˻ʺ����з���:\n"); 
   Queen(0);//�ӵ�0�п�ʼ�ݹ���̽ 
   getch();
   return 0;
}
