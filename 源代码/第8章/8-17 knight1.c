#include <stdio.h>
typedef struct coord
{
   int x;
   int y;
}Coordinate;	//�����ϵ����� 
int chessboard[8][8] = { 0 };	//���̳�ʼ״̬
int main()
{
   Coordinate start;	//��ʼ���� 
   int i, j;
   printf("���������ʼλ������:");
   scanf("%d %d", &start.x, &start.y);
   if(start.x< 1  || start.y < 1 
       || start.x > 8 || start.y > 8) //���� 
   {
       printf("��������������������룡\n");
       exit(0);
   }
   start.x -= 1;
   start.y -= 1;
   if (travel(start))
   {
	  printf("\n������˳����:\n");
      for (i = 0; i < 8; i++)	//��������˳�� 
       {
    	  for (j = 0; j < 8; j++)
    	  {
    		 printf("%2d ", chessboard[i][j]);
    	  }
    	  printf("\n");
       }
   }
   else
   {
	  printf("����ʧ�ܣ�\n");
   }
   getch();
   return 0;
}
int travel(Coordinate start)
{   
   Coordinate move[8] ={ {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
                       {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };//����ߵİ˸�����
   Coordinate next[8] = { 0 };	//��һ���ĳ�·
   int ways[8] = { 0 };	//��¼ÿ�������·������
   Coordinate curpos, tmp; //��ǰ���� ����ʱ���� 
   int i, j, n, m;//ѭ������ 
   int count, count1, min, tmp1; //�������� 
   curpos = start;	//����ʼλ�ÿ�ʼ 
   chessboard[curpos.x][curpos.y] = 1;	//��ǵ�1��
   for (n= 2; n <= 64; n++) //ѭ��2~64��λ�� 
   {
	  for (m = 0; m < 8; m++)
	  {
		 ways[m] = 0;	//��ո�λ�õĳ�·��Ϊ0 
	  }
	  count1 = 0;	//��һ������λ�����        
	  for (j = 0; j < 8; j++)	//��̽�˸����� 
	  {
		 tmp.x = curpos.x + move[j].x;	//��һ���������
		 tmp.y = curpos.y + move[j].y;
		 if (tmp.x < 0 || tmp.y < 0 || tmp.x > 7 || tmp.y > 7)	//����һ����Խ����
			continue;	//������̽��������             
		 if (chessboard[tmp.x][tmp.y] == 0)	//����λ�û�δ�߹�
		 {
			next[count1] = tmp;	//������һ�������� 
			count1++;	//���ӿ��߷������� 
		 }
	  }
	  count = count1;	//������߷��������        
	  if (count == 0)	//�����߷���Ϊ0���򷵻ر���ʧ�� 
	  {
		 return 0; //����ʧ��,����0 
	  }
      else if (count == 1)	//�����߷���ֻ��1����ֱ��Ϊ���ٳ�·�ķ���
	  {
		 min = 0;
	  }
      else	// ����һ��λ�õĿɳ�·��
	  {
		 for (m = 0; m < count; m++)	//ǰ���ҵ��ĸ��������һ���� 
		 {
			for (j = 0; j < 8; j++)	//��̽�˸����� 
			{
			   tmp.x = next[m].x + move[j].x;	//��һ���������
			   tmp.y = next[m].y + move[j].y;
			   if (tmp.x < 0 || tmp.y < 0 || tmp.x > 7 || tmp.y > 7)	//Խ�� 
			   {
				  continue;	//���� 
			   }
			   if (chessboard[tmp.x][tmp.y] == 0)	//���÷���δ�� 
				  ways[m]++;	//���ӳ�·�� 
			}
		 }
		 tmp1 = ways[0];	//��1��λ�õĿ��߳�·�� 
		 min = 0;
		 for (m = 1; m < count; m++)	//�ӿ��ߵ�λ���в������ٳ�·�ķ���
		 {
			if (ways[m] < tmp1)
			{
			   tmp1 = ways[m];
			   min = m;	//�ҳ����ٳ�·�ķ��� 
			}
		 }
	  }
	  curpos = next[min];
	  chessboard[curpos.x][curpos.y] = n;	//��¼����
   }
   return 1;	//�����ɹ�������1 
}
