#include<stdio.h>
typedef struct card
{
   int Suit;	//��ɫ 
   char Number;	//���� 
   float Num;	//��Ϸ�еĵ��� 
}Card;
Card card1[52];	//����ÿ���˿˵Ļ�ɫ�����֡����� 
void ShowCard();	//��ʾ��
void Shuffle();	//ϴ�� 
void Deal();	//��˳���� 
int main()
{
   int i, suit1, temp;
   char again;
   suit1 = 2;
   for (i = 0; i < 52; i++)	//����52���� 
   {
	  if (i % 13 == 0)
		 suit1++;	//�ı仨ɫ 
	  card1[i].Suit = suit1;	//���滨ɫ 
	  temp = i % 13;
	  if (temp == 0)
		 card1[i].Number = 'A';
	  else if (temp == 9)
		 card1[i].Number = '0';
	  else if (temp == 10)
		 card1[i].Number = 'J';
	  else if (temp == 11)
		 card1[i].Number = 'Q';
	  else if (temp == 12)
		 card1[i].Number = 'K';
	  else
		 card1[i].Number = temp + '1';
	  if (temp >= 10)
		 card1[i].Num = 0.5;
	  else
		 card1[i].Num = temp + 1;
   }
   do
   {
	  ShowCard();	//��ʾ52���Ƹ���Ϸ�߼�� 
	  Shuffle();	//ϴ�� 
	  Deal();	//����
	  printf("\n������(y/n)��");
	  fflush(stdin);
	  scanf("%c", &again);
   }while (again == 'y' || again == 'Y');
   getchar();
   return 0;
}
void ShowCard() //��ʾ�� ��Ƹ���Ϸ�߼�� ֡�����
{
   int i, j;
   printf("���б�:");	//��ʾ�����Ƹ���Ϸ�߼�� 
   for (i = 0, j = 0; i < 52; i++, j++)
   {
	  if (!(j % 13))
		 printf("\n");
	  printf("  %c%c", card1[i].Suit, card1[i].Number);
   }
}
void Shuffle() //ϴ�������Ƹ���Ϸ�߼�� ֡�����
{
   int i, j;
   Card tempcard;
   srand((int) time(0));
   for (i = 0; i < 52; i++)
   {
	  j = rand() % 52;	//������ƣ����Ƶ�˳�����,�ﵽϴ�Ƶ�Ч�� 
	  tempcard = card1[j];
	  card1[j] = card1[i];
	  card1[i] = tempcard;
   }
}
void Deal() //��˳���� ��Ƶ�˳�����,�ﵽϴ�Ƶ�Ч��
{
   int i, iCount = 0, iMan = 0, iComputer = 0, flag = 1, flag1 = 1;	//iCountΪ�Ƶļ�����,iManΪ��Ϸ���Ƶ�����,iComputerΪ������Ƶ����� 
   char continue1;
   float TotalM = 0, TotalC = 0;	//ͳ����Ϸ�ߺͼ�������ܵ��� 
   Card Man[18], Computer[18];	//������Ϸ�ߺͼ�������е��� 
   while (flag == 1 && iCount < 52)	//������ 
   {
	  //��Ϸ��ȡ�� 
	  Man[iMan++] = card1[iCount++];	//��һ���Ƹ���Ϸ�� 
	  TotalM += Man[iMan - 1].Num;	//�ۼ���Ϸ�����Ƶ��ܵ��� 
	  //����Ϊ�ɼ����ȡ��
	  if (iCount >= 52)	//����ȡ�� 
		 flag = 0;
	  else if (TotalM > 10.5)	//��Ϸ�߱���,����Ҫ����
		 flag1 = 0; //���������Ҫ�� 
	  else
	  {
		 if ((TotalC < 10.5 && TotalC < TotalM) ||
             TotalC < 7)	//����ǰ����С��10.5,��С����Ϸ�ߵĵ��� 
		 {
			Computer[iComputer++] = card1[iCount++];	//�����ȡһ���� 
			TotalC += Computer[iComputer - 1].Num;	//�ۼƼ����ȡ���Ƶ��ܵ��� 
		 }
	  }
	  printf("\n");
	  printf("�����:");
	  for (i = 0; i < iMan; i++)
		 printf("  %c%c", Man[i].Suit, Man[i].Number);
	  printf("\n�ܵ���Ϊ:%.1f\n", TotalM);
	  printf("���Ե���Ϊ:");
	  for (i = 0; i < iComputer; i++)
		 printf("  %c%c", Computer[i].Suit, Computer[i].Number);
	  printf("\n�ܵ���Ϊ:%.1f\n", TotalC);
	  if (TotalM < 10.5)	//����Ϸ�ߵ���С��10.5,�ɼ���Ҫ�� 
	  {
		 do
		 {
			printf("��Ҫ����(y/n)?");
			fflush(stdin);
			scanf("%c", &continue1);
		 }while (continue1 != 'y' && continue1 != 'Y' && continue1 != 'n' && continue1 != 'N');
		 if (continue1 == 'y' || continue1 == 'Y')
			flag = 1;
		 else
			flag = 0;
		 if (iCount == 52)
		 {
			printf("���Ѿ������ˣ�\n");
			getch();
			break;
		 }
	  }
      else
		 break;
   }
   while (flag1==1 && iCount < 52)	//��Ϸ�߲�Ҫ���Ժ󣬼����������Ҫ�ɼ���Ҫ�� 
   {
	  if (TotalM > 10.5)	//��Ϸ�߱���,����Ҫ����
		 break;
	  else
	  {
		 if (TotalC < 10.5 && TotalC < TotalM)	//����ǰ����С��10.5,��С����Ϸ�ߵĵ��� 
		 {
			Computer[iComputer++] = card1[iCount++];	//�����ȡһ���� 
			TotalC += Computer[iComputer - 1].Num;	//�ۼƼ����ȡ���Ƶ��ܵ��� 
		 }
		 else
		     break;
	  }
   }
   printf("\n�����:");
   for (i = 0; i < iMan; i++)
	  printf("  %c%c", Man[i].Suit, Man[i].Number);
   printf("\n����ܵ���:%.1f\n", TotalM);
   printf("���������Ϊ:");
   for (i = 0; i < iComputer; i++)
	  printf("  %c%c", Computer[i].Suit, Computer[i].Number);
   printf("\n��������ܵ���Ϊ:%.1f\n", TotalC);
   if (TotalM > 10.5)	//��Ϸ�߱��� 
	  if (TotalC > 10.5)	//���������
		 printf("\n��Ӯ�ˣ�\n");
	  else
		 printf("\n������!\n");
   else if (TotalM == 10.5)
	  if (TotalC == 10.5)
		 printf("\n��ͼ���������ƽ��!\n");
	  else
		 printf("\n��Ӯ�ˣ�\n");
   else if (TotalC > 10.5)
	  printf("\n��Ӯ�ˣ�\n");
   else if (TotalC > TotalM)
	  printf("\n�����Ӯ�ˣ�\n");
   else if (TotalC == TotalM)
	  printf("\n��ͼ���������ƽ�֣�\n");
   else
	  printf("\n��Ӯ�ˣ�\n");
}
