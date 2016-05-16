#include <stdio.h>
typedef struct card
{
   int Suit;	//花色 
   char Number;	//牌数 
}Card;
Card card1[52];	//保存每张扑克的花色、数字
void ShowCard(); //显示牌 
void Shuffle(); //洗牌
int main()
{
   int i, suit1, temp;
   suit1 = 2;
   for (i = 0; i < 52; i++)	//生成52张牌 
   {
	  if (i % 13 == 0)
		 suit1++;	//改变花色 
	  card1[i].Suit = suit1;	//保存花色 
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
   printf("一付新牌的排列:\n"); 
   ShowCard();	//显示新牌的排列 
   Shuffle();	//洗牌 
   printf("\n洗牌后的排列:\n");
   ShowCard();	//显示新牌的排列
   getch();
   return 0;
}
void ShowCard() //显示牌 
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
void Shuffle() //洗牌
{
   int i, j;
   Card tempcard;
   srand((int) time(0));
   for (i = 0; i < 52; i++)
   {
	  j = rand() % 52;	//随机换牌，将牌的顺序打乱,达到洗牌的效果 
	  tempcard = card1[j];
	  card1[j] = card1[i];
	  card1[i] = tempcard;
   }
}
