#include <stdio.h>
unsigned int *heap; //�������ʯ�ӵ����� 
int num;
void Output() //��ʾ����ʯ�ӵ�״̬ 
{
   int i;
   printf("����ʣ�µ�ʯ������:\n");
   for (i = 1; i <= num; i++)
	  printf("��%2d��ʣ��: %u \n", i, heap[i]);
}
unsigned int remain() //ͳ��ʣ�µ�ʯ������ 
{
   unsigned int s;
   int i;
   s = 0;
   for (i = 1; i <= num; i++)
	  s += heap[i];
   return s;
}
unsigned int xorall() //��λ���Ľ�� 
{
   unsigned int s;
   int i;
   s = 0;
   for (i = 1; i <= num; i++)
	  s ^= heap[i];
   return s;
}
int main()
{
   unsigned int t;
   int i, s, h;
   printf("����ʯ�ӵĶ���:");
   scanf("%d", &num);
   if(num<2)
   {
       printf("����Ӧ����2��ʯ��!\n");
       exit(0);
   }
   if(!(heap=(unsigned int *)malloc(sizeof(unsigned int)*num)))
   {
       printf("�ڴ����ʧ��!\n");
       exit(0); 
   }   
   for (i = 1; i <= num; i++)
   {
	  printf("�����%d��ʯ�ӵ�����:", i);
	  scanf("%d", &heap[i]);
   }
   while (remain()) //ʣ��ʯ��������0 
   {
	  if (xorall() == 0) //�����Ľ��Ϊ0 
	  {
		 for (i = 1; i <= num; i++) //��һ��ʯ����ȡһ�� 
		 {
			if (heap[i] > 0)
			{
			   printf("\n������ӵ�%2d������1����\n", i);
			   heap[i]--;
			   break;
			}
        }
	  }
      else
      {
		 for (i = 1; i <= num; i++)
		 {
			s = heap[i] - (xorall() ^ heap[i]); //����Ҫȡ��ʯ������ 
			if (s > 0)
			{
			   printf("\n������ӵ�%2d������%u����\n", i, s);
			   heap[i] ^= xorall();
			   break;
			}
		 }
      }
	  if (remain() == 0)
	  {
		 printf("\n�����ʤ!");
		 break;
	  }
	  Output(); //��ʾʣ���ʯ����� 
	  while (1)
	  {
		 printf("\n�������ѡ��(�� ����):");
		 scanf("%d %u", &h, &t);
		 if ((h >= 1) && (h <= num) && (heap[h] >= t))
		 {
			heap[h] -= t;
			break;
		 } else
			printf("\n�������ݳ�����������!\n");
	  }
	  if (remain() == 0)
	  {
		 printf("\n��ϲ���ʤ!");
		 break;
	  }
   }
   getch();
   return 0;
}
