#include <stdio.h>
typedef struct card
{
   int Suit;	//��ɫ 
   char Number;	//���� 
}Card;
Card card1[52];	//����ÿ���˿˵Ļ�ɫ������
void ShowCard(); //��ʾ�� 
void Shuffle(); //ϴ��
int main()
{
   int i, suit1, temp;
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
   }
   printf("һ�����Ƶ�����:\n"); 
   ShowCard();	//��ʾ���Ƶ����� 
   Shuffle();	//ϴ�� 
   printf("\nϴ�ƺ������:\n");
   ShowCard();	//��ʾ���Ƶ�����
   getch();
   return 0;
}
void ShowCard() //��ʾ�� 
{
   int i, j;
   for (i = 0, j = 0; i < 52; i++, j++)
   {
	  if (!(j % 13))
		 printf("\n");
	  printf("  %c%c", card1[i].Suit, card1[i].Number);
   }
   printf("\n");
}
void Shuffle() //ϴ��
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
