#include <stdio.h>
#define MAXN 10000
int Queue1[MAXN], Queue2[MAXN];
void Insert(int n, int data)	//按增序插入数组 
{
   int i, mid, left, right;
   left = 0;
   right = n - 1;
   if (n == 0 || data >= Queue1[right])	//最大
   {
	  Queue1[n] = data;
	  return;
   }
   else if (data < Queue1[left])	//最小
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
   for (i = n - 1; i >= mid; i--)	//插入到a[mid]之前
   {
	  Queue1[i + 1] = Queue1[i];
   }
   Queue1[mid] = data;
}
int Calc(int a[], int n)	//按增序插入数组
{
   int i, frontOld, frontNew, rearNew;
   long long sum = 0;
   if (n == 1)
	  return a[0];
   if (n == 2)
	  return a[0] + a[1];
   for (i = 0; i < n; i++)	//按增序插入数组
	  Insert(i, a[i]);
   //先加上前两个 
   frontOld = frontNew = rearNew = 0;
   Queue2[rearNew++] = Queue1[frontOld] + Queue1[frontOld + 1];
   frontOld += 2;
   while (frontOld < n)	//合并Queue1的所有元素 
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
   while (frontNew < rearNew - 1)	//如果Queue2的元素没有合并完 
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
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d\n", &n); //果子种类数 
   for (i = 0; i < n; i++) //各类果子的数量 
	  fscanf(fp1, "%d", &a[i]);
   fclose(fp1);
   sum = Calc(a, n);
   if ((fp2 = fopen("fruit.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }   
   printf("%d\n", sum);
   fprintf(fp1, "%d\n", sum);
   fclose(fp2);
   getch();
   return 0;
}
