#include <stdio.h>
#define MAXN 50
#define MAXK 3
typedef struct VERTEX
{
   int x, y;	//������� 
}VERTEX;
typedef struct rect
{
   VERTEX lt;	//���Ͻ�����
   VERTEX rb;	//���½����� 
}RECT;
RECT rect[MAXK]; 
VERTEX v[MAXK][MAXN];	//���涥����  
int n, k;
int intersect(RECT rect1, RECT rect2) //�ж��������Ƿ��й�����(�Ƿ񽻲�)
{
   if (rect2.lt.x > rect1.rb.x || rect1.lt.x > rect2.rb.x)	//����2��ߴ��ھ���1���ұ� /�����1��ߴ��ھ���2���ұ� 
	  return 0;
   if (rect2.lt.y > rect1.rb.y || rect1.lt.y > rect2.rb.y)	//����2�ϱߴ��ھ���1�ĵױ� /�����1���ϱߴ��ھ���2�ĵױ�
	  return 0;
   return 1;
}
int area(RECT rect) //����������ھ���1�ĵױ� /�����1���ϱߴ��ھ���2�ĵױ�
{
   int height, s;
   height = rect.rb.y - rect.lt.y;	//�߶� 
   s = height * (rect.rb.x - rect.lt.x);
   return s;	//�������    
}
void insert(VERTEX v, RECT * rect) //���������Σ�����������������ε����� ���ھ���2�ĵױ�
{
   if (v.x < rect->lt.x)	//���x����С�ھ���������� 
	  rect->lt.x = v.x;	//��������������� 
   if (v.x > rect->rb.x)
	  rect->rb.x = v.x;
   if (v.y < rect->lt.y)
	  rect->lt.y = v.y;
   if (v.y > rect->rb.y)
	  rect->rb.y = v.y;
}
int calc() //��̽��������ε���� ���� �����ε����� ���ھ���2�ĵױ�
{
   VERTEX v0;	//��ʱ����ʹ�� 
   int i, j, m, s, temp, min;
   min = 2147483647;	//����һ�����ֵ 
   switch (k)	//���ݾ��θ������в�ͬ���� 
   {
   case 1:	//k=1�����
      rect[0].lt.x=v[0][1].x; //�����������������xֵ 
      rect[0].lt.y=v[1][1].y; //�����������������yֵ 
      rect[0].rb.x=v[0][n].x; //�����������������yֵ 
      rect[0].rb.y=v[1][n].y;//�����������������yֵ 
	  min = area(rect[0]);	//������� 
	  break;
   case 2:	//k=2����� 
	  for (s = 0; s <= 1; s++)
	  {
		 rect[0].lt = rect[1].rb = v[s][1];	//��1������
		 for (i = 2; i <= n; i++)	//���������ŷ����2������ 
		 {
			insert(v[s][i - 1], &rect[0]);	//����i-1��������1
			rect[1].lt = rect[2].rb = v[s][i];	//���õ�2�����εĳ�ʼֵ 
			for (m = i + 1; m <= n; m++)	//��ʣ�����ӵ�����2 
			   insert(v[s][m], &rect[1]);
			if (!intersect(rect[0], rect[1]))	//�������β��ཻ 
			{
			   temp = 0;
			   for (m = 0; m < k; m++)	//������������� 
				  temp += area(rect[m]);
			   if (temp < min)	//�����������С��min 
				  min = temp;	//�����С����� 
			}
		 }
	  }
	  break;
   case 3:
	  //flag=0,1�����
	  for (s = 0; s <= 1; s++)
	  {
		 rect[0].lt = rect[0].rb = v[s][1];	//��1������ 
		 for (i = 2; i <= n - 1; i++)	//���������ŷ����2������ 
		 {
			insert(v[s][i - 1], &rect[0]);	//����i-1��������1
			rect[1].lt = rect[1].rb = v[s][i];	//���õ�2�����εĳ�ʼֵ 
			if (intersect(rect[0], rect[1]))	//�����������ཻ 
			   continue;	//����������һ������ 
			for (j = i + 1; j <= n; j++)	//���������ŷ����2������ 
			{
			   insert(v[s][j - 1], &rect[1]);	//����i-1��������1
			   rect[2].lt = rect[2].rb = v[s][j];	//���õ�3�����εĳ�ʼֵ 
			   for (m = j + 1; m <= n; m++)	//��ʣ�����ӵ�����3 
				  insert(v[s][m], &rect[2]);
			   if (intersect(rect[1], rect[2]))	//������2�����3�ཻ 
				  continue;	//����������һ������ 
			   temp = 0;
			   for (m = 0; m < k; m++)	//������������ 
				  temp += area(rect[m]);
			   if (temp < min)
				  min = temp;
			}
		 }
	  }
	  //flag=2�����:����ֱ���ִ���Σ������Ҿ�����ˮƽ����
	  rect[0].lt = rect[0].rb = v[0][1];	//��1�����γ�ʼֵ 
	  for (i = 2; i <= n - 1; i++)
	  {
		 for (m = 1; m <= n; m++)	//v[2][i]������������� 
			v[2][m] = v[0][m];
		 for (m = i; m <= n - 1; m++)	//��v[2][i]���������������� 
		 {
			for (s = m + 1; s <= n; s++)
			{
			   if (v[2][m].y > v[2][s].y)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 insert(v[2][i - 1], &rect[0]);	//����i-1��������1
		 rect[1].lt = rect[1].rb = v[2][i];	//���õ�2�����γ�ʼֵ
		 if (intersect(rect[0], rect[1]))	//����1�����2�ཻ 
			continue;
		 for (j = i + 1; j <= n; j++)
		 {
			insert(v[2][j - 1], &rect[1]);	//����j-1��������2
			rect[2].lt = rect[2].rb = v[2][j];	//���õ�3�����γ�ʼֵ 
			for (m = j + 1; m <= n; m++)	//����������������3
			   insert(v[2][m], &rect[2]);
			if (intersect(rect[1], rect[2]))	//������2�����3�ཻ 
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)	//��������ε���� 
			   temp += area(rect[m]);
			if (temp < min)	//���������Сֵ 
			   min = temp;
		 }
	  }
	  //flag=3����� 
	  for (j = 3; j <= n; j++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[0][m];
		 for (m = 1; m <= j - 2; m++)	//������������ 
		 {
			for (s = m + 1; s <= j - 1; s++)
			{
			   if (v[2][m].y > v[2][s].y)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 rect[2].lt = rect[2].rb = v[2][j];	//��ʼ����3������ 
		 for (m = j + 1; m <= n; m++)	//�������ӵ���3������ 
			insert(v[2][m], &rect[2]);
		 for (i = 2; i <= j - 1; i++)
		 {
			rect[1].lt = rect[1].rb = v[2][i];	//���õ�2�����γ�ʼֵ 
			for (m = i + 1; m <= j - 1; m++)	//������ӵ���2������ 
			   insert(v[2][m], &rect[1]);
			rect[0].lt = rect[0].rb = v[2][1];	//���õ�1�����γ�ʼֵ 
			for (m = 2; m <= i - 1; m++)	//�������ӵ�1������ 
			   insert(v[2][m], &rect[0]);
			if (intersect(rect[0], rect[1]) || intersect(rect[1], rect[2])
			   || intersect(rect[0], rect[2]))	//��3���������ཻ���� 
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)	//������������ 
			   temp += area(rect[m]);
			if (temp < min)	//������С��� 
			   min = temp;
		 }
	  }
	  //flag=4����� 
	  for (j = 3; j <= n; j++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[1][m];
		 for (m = 1; m <= j - 2; m++)
		 {
			for (s = m + 1; s <= j - 1; s++)
			{
			   if (v[2][m].x > v[2][s].x)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 rect[2].lt = rect[2].rb = v[2][j];
		 for (m = j + 1; m <= n; m++)
			insert(v[2][m], &rect[2]);
		 for (i = 2; i <= j - 1; i++)
		 {
			rect[1].lt = rect[1].rb = v[2][i];
			for (m = i + 1; m <= j - 1; m++)
			   insert(v[2][m], &rect[1]);
			rect[0].lt = rect[0].rb = v[2][1];
			for (m = 2; m <= i - 1; m++)
			   insert(v[2][m], &rect[0]);
			if (intersect(rect[0], rect[1]) || intersect(rect[1], rect[2])
			   || intersect(rect[0], rect[2]))
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)
			   temp += area(rect[m]);
			if (temp < min)
			   min = temp;
		 }
	  }
	  //flag=5����� 
	  rect[0].lt = rect[0].rb = v[1][1];	//��1�����γ�ʼֵ 
	  for (i = 2; i <= n - 1; i++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[1][m];
		 for (m = i; m <= n - 1; m++)
		 {
			for (s = m + 1; s <= n; s++)
			{
			   if (v[2][m].x > v[2][s].x)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 insert(v[2][i - 1], &rect[0]);
		 rect[1].lt = rect[1].rb = v[2][i];
		 if (intersect(rect[0], rect[1]))
			continue;
		 for (j = i + 1; j <= n; j++)
		 {
			insert(v[2][j - 1], &rect[1]);
			rect[2].lt = rect[2].rb = v[2][j];
			for (m = j + 1; m <= n; m++)
			   insert(v[2][m], &rect[2]);
			if (intersect(rect[1], rect[2]))
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)
			   temp += area(rect[m]);
			if (temp < min)
			   min = temp;
		 }
	  }
	  break;
   }
   return min;
}
int main()
{
   VERTEX v0;	//��ʱ�����ö��� 
   int i, j, value;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("rectang.in", "r")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d\n", &n, &k);	//�������n�;�����k
   for (i = 1; i <= n; i++)	//������������ 
   {
	  fscanf(fp1, "%d%d\n", &v[0][i].x, &v[0][i].y);
	  v[1][i] = v[0][i];
   }
   fclose(fp1);
   for (i = 1; i <= n - 1; i++)	//���������������и��㣬����v[0][i]
   {
	  for (j = i + 1; j <= n; j++)
	  {
		 if (v[0][i].x > v[0][j].x)
		 {
			v0 = v[0][i];
			v[0][i] = v[0][j];
			v[0][j] = v0;
		 }
	  }
   }
   for (i = 1; i <= n - 1; i++)	//���������������У�����v[i][1] 
   {
	  for (j = i + 1; j <= n; j++)
	  {
		 if (v[1][i].y > v[1][j].y)
		 {
			v0 = v[1][i];
			v[1][i] = v[1][j];
			v[1][j] = v0;
		 }
	  }
   }
   value = calc();
   if ((fp2 = fopen("rectang.out", "w")) == NULL)
   {
	  printf("���ܴ��ļ�!\n");
	  exit(1);
   }
   printf("%d\n", value);
   fprintf(fp2, "%d\n", value);
   fclose(fp2);
   getch();
   return 0;
}
