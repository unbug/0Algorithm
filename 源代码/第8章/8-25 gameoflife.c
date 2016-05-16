#include <stdio.h>
#define MAXROW 10 //������� 
#define MAXCOL 10 //������� 
#define DEAD 0 //��ϸ�� 
#define ALIVE 1 //��ϸ�� 
int cell[MAXROW][MAXCOL], tempcell[MAXROW][MAXCOL]; //��ǰ����ϸ����״̬��һ�������жϵ�ǰ��ϸ������һ��״̬
void init(); //��ʼ��ϸ������ 
int BorderSum(int, int); //ͳ�Ƶ�ǰϸ�����ܵ�ϸ���� 
void Output(); //���ϸ��״̬ 
int main()
{
   int row, col,sum1;
   char again;
   init(); //��ʼ��������ϸ����λ�� 
   Output();   //���ϸ����ʼ״̬ 
   printf("�����������ת����\n");
   getch(); 
   while (1)
   {	  
	  for (row = 0; row < MAXROW; row++)
	  {
		 for (col = 0; col < MAXCOL; col++)
		 {
			switch (BorderSum(row, col)) //(row,col)��Ԫ�����ܵ���ϸ������ 
			{
			case 0:
			case 1:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			   tempcell[row][col] = DEAD; //��ԭϸ����Ϊ��ϸ�� 
			   break;
			case 2:
			   tempcell[row][col] = cell[row][col]; //����ϸ��ԭ�� 
			   break;
			case 3:
			   tempcell[row][col] = ALIVE; //��ϸ����Ϊ��ϸ�� 
			   break;
			}
		 }
	  }
      for (row = 0; row < MAXROW; row++)//������ʱ���鵽map����
    	  for (col = 0; col < MAXCOL; col++)
    		 cell[row][col] = tempcell[row][col];
      sum1=AliveSum();
      if(sum1==0) //����ϸ������Ϊ0 
          break;//����ѭ�� 
      Output(); //���ת�����ϸ��״̬ 
      printf("����%d����ϸ����\n",sum1); 
      printf("\n����������һ��ϸ����״̬(n�˳�)��");
	  again = getch();
	  if (again == 'N' || again == 'n')
		 break;
   }
   getch();
   return 0;
}
void init() //��ʼ�� 
{
   int row, col;
   for (row = 0; row < MAXROW; row++) //��ȫ����ʼ��Ϊ��״̬ 
	  for (col = 0; col < MAXCOL; col++)
		 cell[row][col] = DEAD;
   printf("������Ϸ\n");
   printf("�����ϸ��������λ�ã�����(-1 -1)����:\n");
   while (1)
   {
	  scanf("%d %d", &row, &col); //������������ 
	  if (0 <= row && row < MAXROW && 0 <= col && col < MAXCOL)
		 cell[row][col] = ALIVE; //������ϸ�� 
	  else if (row == -1 || col == -1)
		 break;
	  else
		 printf("�������곬����Χ��\n"); 
   }
}
int BorderSum(int row, int col) //ͳ������ϸ������ 
{
   int count = 0, c, r;
   for (r = row - 1; r <= row + 1; r++)
   {
	  for (c = col - 1; c <= col + 1; c++)
	  {
		 if (r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL) //����������� 
			continue; //������һ����Ԫ�� 
		 if (cell[r][c] == ALIVE) //��Ϊ��ϸ�� 
			count++; //���ӻ�ϸ�������� 
	  }
   }
   if (cell[row][col] == ALIVE) //����ǰ��Ԫ��Ϊ��ϸ�� 
	  count--; //��ϸ��������1 
   return count; //�������ܻ�ϸ������ 
}
void Output() //���ϸ��״̬ 
{
   int row, col;
   printf("\nϸ��״̬\n");
   printf("��");	//�������� 
   for (col = 0; col < MAXCOL -1; col++)	//���һ�� 
	  printf("����");
   printf("����\n");
   for (row = 0; row < MAXROW; row++)
   {
	  printf("��");	//����к�
	  for (col = 0; col < MAXCOL; col++)	//������̸���Ԫ�������ӵ�״̬ 
	  {
		 if (cell[row][col] == ALIVE  )	//��ϸ�� 
			printf("��");
		 else 	//��ϸ�� 
			printf("��");
	  }
	  printf("\n");

	  if (row < MAXROW - 1)
	  {
		 printf("��");	//��������� 
		 for (col = 0; col < MAXCOL - 1; col++)	//���һ�� 
			printf("����");
		 printf("����\n");
	  }
   }
   printf("��");
   for (col = 0; col < MAXCOL - 1; col++)	//���һ�еĺ��� 
	  printf("����");
   printf("����\n");   
}
int AliveSum() //ͳ����ϸ�������� 
{
   int row,col,count=0;
   for (row = 0; row < MAXROW; row++)
   {
	  for (col = 0; col < MAXCOL; col++)
	  {
		 if(cell[row][col] == ALIVE) //���ǻ�ϸ�� 
             count++; //�ۼ����� 
      }
   }
   return count;
}
