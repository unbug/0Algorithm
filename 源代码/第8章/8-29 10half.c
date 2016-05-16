#include<stdio.h>
typedef struct card
{
   int Suit;	//»¨É« 
   char Number;	//ÅÆÊı 
   float Num;	//ÓÎÏ·ÖĞµÄµãÊı 
}Card;
Card card1[52];	//±£´æÃ¿ÕÅÆË¿ËµÄ»¨É«¡¢Êı×Ö¡¢µãÊı 
void ShowCard();	//ÏÔÊ¾ÅÆ
void Shuffle();	//Ï´ÅÆ 
void Deal();	//°´Ë³Ğò·¢ÅÆ 
int main()
{
   int i, suit1, temp;
   char again;
   suit1 = 2;
   for (i = 0; i < 52; i++)	//Éú³É52ÕÅÅÆ 
   {
	  if (i % 13 == 0)
		 suit1++;	//¸Ä±ä»¨É« 
	  card1[i].Suit = suit1;	//±£´æ»¨É« 
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
	  ShowCard();	//ÏÔÊ¾52ÕÅÅÆ¸øÓÎÏ·Õß¼ì²é 
	  Shuffle();	//Ï´ÅÆ 
	  Deal();	//·¢ÅÆ
	  printf("\n¼ÌĞøÍæ(y/n)£¿");
	  fflush(stdin);
	  scanf("%c", &again);
   }while (again == 'y' || again == 'Y');
   getchar();
   return 0;
}
void ShowCard() //ÏÔÊ¾ÅÆ ÅÅÆ¸øÓÎÏ·Õß¼ì²é Ö¡¢µãÊı
{
   int i, j;
   printf("ÅÆÁĞ±í:");	//ÏÔÊ¾Õû¸±ÅÆ¸øÓÎÏ·Õß¼ì²é 
   for (i = 0, j = 0; i < 52; i++, j++)
   {
	  if (!(j % 13))
		 printf("\n");
	  printf("  %c%c", card1[i].Suit, card1[i].Number);
   }
}
void Shuffle() //Ï´ÅÆÕû¸±ÅÆ¸øÓÎÏ·Õß¼ì²é Ö¡¢µãÊı
{
   int i, j;
   Card tempcard;
   srand((int) time(0));
   for (i = 0; i < 52; i++)
   {
	  j = rand() % 52;	//Ëæ»ú»»ÅÆ£¬½«ÅÆµÄË³Ğò´òÂÒ,´ïµ½Ï´ÅÆµÄĞ§¹û 
	  tempcard = card1[j];
	  card1[j] = card1[i];
	  card1[i] = tempcard;
   }
}
void Deal() //°´Ë³Ğò·¢ÅÆ «ÅÆµÄË³Ğò´òÂÒ,´ïµ½Ï´ÅÆµÄĞ§¹û
{
   int i, iCount = 0, iMan = 0, iComputer = 0, flag = 1, flag1 = 1;	//iCountÎªÅÆµÄ¼ÆÊıÆ÷,iManÎªÓÎÏ·ÕßÅÆµÄÊıÁ¿,iComputerÎª¼ÆËã»úÅÆµÄÊıÁ¿ 
   char continue1;
   float TotalM = 0, TotalC = 0;	//Í³¼ÆÓÎÏ·ÕßºÍ¼ÆËã»úµÄ×ÜµãÊı 
   Card Man[18], Computer[18];	//±£´æÓÎÏ·ÕßºÍ¼ÆËã»úÊÖÖĞµÄÅÆ 
   while (flag == 1 && iCount < 52)	//»¹ÓĞÅÆ 
   {
	  //ÓÎÏ·ÕßÈ¡ÅÆ 
	  Man[iMan++] = card1[iCount++];	//·¢Ò»ÕÅÅÆ¸øÓÎÏ·Õß 
	  TotalM += Man[iMan - 1].Num;	//ÀÛ¼ÓÓÎÏ·ÕßÄÃÅÆµÄ×ÜµãÊı 
	  //½ÓÏÂÎªÓÉ¼ÆËã»úÈ¡ÅÆ
	  if (iCount >= 52)	//ÅÆÒÑÈ¡Íê 
		 flag = 0;
	  else if (TotalM > 10.5)	//ÓÎÏ·Õß±¬ÁË,Ôò²»ÔÙÒªÅÆÁË
		 flag1 = 0; //¼ÆËã»ú²»ÔÙÒªÅÆ 
	  else
	  {
		 if ((TotalC < 10.5 && TotalC < TotalM) ||
             TotalC < 7)	//Èôµ±Ç°µãÊıĞ¡ÓÚ10.5,ÇÒĞ¡ÓÚÓÎÏ·ÕßµÄµãÊı 
		 {
			Computer[iComputer++] = card1[iCount++];	//¼ÆËã»úÈ¡Ò»ÕÅÅÆ 
			TotalC += Computer[iComputer - 1].Num;	//ÀÛ¼Æ¼ÆËã»úÈ¡µÃÅÆµÄ×ÜµãÊı 
		 }
	  }
	  printf("\n");
	  printf("ÄãµÄÅÆ:");
	  for (i = 0; i < iMan; i++)
		 printf("  %c%c", Man[i].Suit, Man[i].Number);
	  printf("\n×ÜµãÊıÎª:%.1f\n", TotalM);
	  printf("µçÄÔµÄÅÆÎª:");
	  for (i = 0; i < iComputer; i++)
		 printf("  %c%c", Computer[i].Suit, Computer[i].Number);
	  printf("\n×ÜµãÊıÎª:%.1f\n", TotalC);
	  if (TotalM < 10.5)	//ÈôÓÎÏ·ÕßµãÊıĞ¡ÓÚ10.5,¿É¼ÌĞøÒªÅÆ 
	  {
		 do
		 {
			printf("»¹ÒªÅÆÂğ(y/n)?");
			fflush(stdin);
			scanf("%c", &continue1);
		 }while (continue1 != 'y' && continue1 != 'Y' && continue1 != 'n' && continue1 != 'N');
		 if (continue1 == 'y' || continue1 == 'Y')
			flag = 1;
		 else
			flag = 0;
		 if (iCount == 52)
		 {
			printf("ÅÆÒÑ¾­·¢ÍêÁË£¡\n");
			getch();
			break;
		 }
	  }
      else
		 break;
   }
   while (flag1==1 && iCount < 52)	//ÓÎÏ·Õß²»ÒªÅÆÒÔºó£¬¼ÆËã»ú¸ù¾İĞèÒª¿É¼ÌĞøÒªÅÆ 
   {
	  if (TotalM > 10.5)	//ÓÎÏ·Õß±¬ÁË,Ôò²»ÔÙÒªÅÆÁË
		 break;
	  else
	  {
		 if (TotalC < 10.5 && TotalC < TotalM)	//Èôµ±Ç°µãÊıĞ¡ÓÚ10.5,ÇÒĞ¡ÓÚÓÎÏ·ÕßµÄµãÊı 
		 {
			Computer[iComputer++] = card1[iCount++];	//¼ÆËã»úÈ¡Ò»ÕÅÅÆ 
			TotalC += Computer[iComputer - 1].Num;	//ÀÛ¼Æ¼ÆËã»úÈ¡µÃÅÆµÄ×ÜµãÊı 
		 }
		 else
		     break;
	  }
   }
   printf("\nÄãµÄÅÆ:");
   for (i = 0; i < iMan; i++)
	  printf("  %c%c", Man[i].Suit, Man[i].Number);
   printf("\nÄãµÄ×ÜµãÊı:%.1f\n", TotalM);
   printf("¼ÆËã»úµÄÅÆÎª:");
   for (i = 0; i < iComputer; i++)
	  printf("  %c%c", Computer[i].Suit, Computer[i].Number);
   printf("\n¼ÆËã»úµÄ×ÜµãÊıÎª:%.1f\n", TotalC);
   if (TotalM > 10.5)	//ÓÎÏ·Õß±¬ÁË 
	  if (TotalC > 10.5)	//¼ÆËã»ú±¬ÁË
		 printf("\nÄãÓ®ÁË£¡\n");
	  else
		 printf("\nÄãÊäÁË!\n");
   else if (TotalM == 10.5)
	  if (TotalC == 10.5)
		 printf("\nÄãºÍ¼ÆËã»ú´ò³ÉÁËÆ½ÊÖ!\n");
	  else
		 printf("\nÄãÓ®ÁË£¡\n");
   else if (TotalC > 10.5)
	  printf("\nÄãÓ®ÁË£¡\n");
   else if (TotalC > TotalM)
	  printf("\n¼ÆËã»úÓ®ÁË£¡\n");
   else if (TotalC == TotalM)
	  printf("\nÄãºÍ¼ÆËã»ú´ò³ÉÁËÆ½ÊÖ£¡\n");
   else
	  printf("\nÄãÓ®ÁË£¡\n");
}
