#include <stdio.h>
#define MAX 64 //���64��Բ�� 
int main()
{
   int n, target, source, i, array[(MAX+1)*3+1], stick[3],height;
   long count=0;//Բ���ƶ��Ĵ��� 
   printf("�����뺺ŵ��Բ�̵�����:");
   scanf("%d", &n); //������������ 
   height=n+1;//���ĸ߶�(�����ָ�����) 
   for (i = 1; i <= n; i++)	//�����ӷ����1������ 
	  array[i] = height - i; //���ִ�ı�ʾ������ 
   for (i = 0; i <= 2 * height; i += height)	//��ÿ�����ĵײ�����Ϊһ��������� 
	  array[i] = 1000;
   if (n % 2 == 0) //��Բ�������ż�� 
   {
	  target = 1; //Ŀ��ΪB�� 
	  stick[2] = 0;
	  stick[1] = 1;
	  array[height + 1] = array[n]; //�ƶ���1��Բ�̵���2���� 
   }
   else //��Բ�����Ϊ���� 
   {
	  target = 2; //Ŀ��ΪC�� 
	  stick[1] = 0;
	  stick[2] = 1;
	  array[2 * height + 1] = array[n]; //�ƶ���1��Բ�̵���3���� 
   }
   printf("��%d��,A��-->%c��\n",++count,'A'-1+target+1);  //����ƶ����� 
   stick[0] = n - 1; //A���м�ȥһ��Բ�� 
   while(stick[0] + stick[1])	//��1���͵�2����Ϊ��,��ѭ���ƶ�
   {
	  if (target == 0) //��Ŀ�����A 
	  {
          if (array[height + stick[1]] < array[2 * height + stick[2]])//�Ƚ�B��C���Ľ�Сֵ��Ϊ��һ���ƶ��� 
              source = 1;
          else
              source = 2;
      }
	  if (target == 1)//��Ŀ�����B
	  {
          if(array[stick[0]] < array[2 * height + stick[2]]) //�Ƚ�A��C���Ľ�Сֵ 
              source = 0;
          else
              source = 2;
	  }
	  if (target == 2)//��Ŀ�����C
	  {
          if(array[stick[0]] < array[height + stick[1]]) //�Ƚ�A��B���Ľ�Сֵ 
              source= 0;
          else
              source= 1;
      }
// ��source������Բ���Ƶ���һ�ϴ��Ϊż���İ� 
	  if ((array[source * height + stick[source]]) > (array[target * height + stick[target]])
		 || ((array[target * height + stick[target]] - array[source * height + stick[source]]) % 2 ==0))
		 target = 3 - source - target;  
      printf("��%d��,%c��-->%c��\n",++count,'A'-1+source+1,'A'-1+target+1);  //����ƶ�����	  
	  stick[source] = stick[source] - 1;
	  stick[target] = stick[target] + 1;	//��source���ƶ�target��
	  array[target * height + stick[target]] = array[source * height + stick[source] + 1];
   }
   getch();
   return 0;
}
