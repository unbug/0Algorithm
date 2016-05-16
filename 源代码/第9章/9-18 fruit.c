#include <stdio.h>
#define MAXN 10000
int Queue1[MAXN], Queue2[MAXN];
void Insert(int n, int data)	//������������� 
{
   int i, mid, left, right;
   left = 0;
   right = n - 1;
   if (n == 0 || data >= Queue1[right])	//���
   {
	  Queue1[n] = data;
	  return;
   }
   else if (data < Queue1[left])	//��С
   {
	  for (i = right; i >= 0; i--)
	  {
		 Queue1[i + 1] = Queue1[i];
	  }
	  Queue1[0] = data;
	  return;
   }
   while (left <= right)
   {
	  mid = (left + right) / 2;
	  if (Queue1[mid] <= data)
	  {
		 left = mid + 1;
	  } else if (Queue1[mid] > data)
	  {
		 right = mid - 1;
	  }
   }
   if (Queue1[mid] < data)
	  mid++;
   for (i = n - 1; i >= mid; i--)	//���뵽a[mid]֮ǰ
   {
	  Queue1[i + 1] = Queue1[i];
   }
   Queue1[mid] = data;
}
int Calc(int a[], int n)	//�������������
{
   int i, frontOld, frontNew, rearNew;
   long long sum = 0;
   if (n == 1)
	  return a[0];
   if (n == 2)
	  return a[0] + a[1];
   for (i = 0; i < n; i++)	//�������������
	  Insert(i, a[i]);
   //�ȼ���ǰ���� 
   frontOld = frontNew = rearNew = 0;
   Queue2[rearNew++] = Queue1[frontOld] + Queue1[frontOld + 1];
   frontOld += 2;
   while (frontOld < n)	//�ϲ�Queue1������Ԫ�� 
   {
	  if (Queue1[frontOld] > Queue2[frontNew])
		 sum = Queue2[frontNew++];
	  else
		 sum = Queue1[frontOld++];

	  if (frontNew < rearNew && frontOld < n)
	  {
		 if (Queue1[frontOld] > Queue2[frontNew])
			sum += Queue2[frontNew++];
		 else
			sum += Queue1[frontOld++];
	  }
      else if (frontNew < rearNew)
		 sum += Queue2[frontNew++];
	  else if (frontOld < n)
		 sum += Queue1[frontOld++];
	  Queue2[rearNew++] = sum;
   }
   while (frontNew < rearNew - 1)	//���Queue2��Ԫ��û�кϲ��� 
   {
	  Queue2[rearNew++] = Queue2[frontNew] + Queue2[frontNew + 1];
	  frontNew += 2;
   }
   sum = 0;
   for (i = 0; i < rearNew; i++)
	  sum += Queue2[i];
   return sum;
}
int main()
{
   int n, i, sum;
   int a[MAXN] = { 0 };
   FILE *fp1, *fp2;
   if ((fp1 = fopen("fruit.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n); //���������� 
   for (i = 0; i < n; i++) //������ӵ����� 
	  fscanf(fp1, "%d", &a[i]);
   fclose(fp1);
   sum = Calc(a, n);
   if ((fp2 = fopen("fruit.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }   
   printf("%d\n", sum);
   fprintf(fp1, "%d\n", sum);
   fclose(fp2);
   getch();
   return 0;
}
