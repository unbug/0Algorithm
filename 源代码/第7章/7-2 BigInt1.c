#include <stdio.h>
#include <string.h>
typedef struct bigint
{
   char *num;					//Ö¸Ïò³¤ÕûÊıÊı×é(ĞòºÅ0ÖĞ±£´æ×Å×îµÍÎ»)
   char minus;					//·ûºÅ(1±íÊ¾ÕıÊı,-1±íÊ¾¸ºÊı) 
   int digit;					//±£´æ¸ÃÊıµÄÎ»Êı(Êµ¼ÊÎ»Êı) 
}BIGINT, *pBIGINT;
void BigIntTrans(pBIGINT num);	//×Ö·û´®×ªÊı×Ö 
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result);	//³Ë·¨º¯Êı 
void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result);	//Í¬ºÅÊıÏà¼Ó 
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result);	//¼Ó·¨º¯Êı 
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result);	//ÒìºÅÏà¼õº¯Êı
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result);	//¼õ·¨º¯Êı 
void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue);	//³ı·¨º¯Êı 
void BigIntPrint(pBIGINT result);	//Êä³ö´óÕûÊı
int BigIntEqual(pBIGINT num1, pBIGINT num2);	//Á½Êı´óĞ¡±È½Ï

void BigIntTrim(pBIGINT num1) //ÕûÀí´óÕûÊı£¬È¥µôÇ°Ãæ¶àÓàµÄ0£¬²¢Ê¹µ÷ÕûÆäÎ»Êı
{
   int i;
   for (i = num1->digit - 1; i >= 0; i--)
   {
	  if (num1->num[i] != 0)
		 break;
   }
   if (i < 0)	//ÈôÓàÊıÈ«²¿Îª0
   {
	  num1->digit = 1;	//ÉèÖÃÓàÊıÎ»ÊıÎª1
	  num1->num[0] = 0;
   } else
	  num1->digit = i + 1;	//ÓàÊıÎ»Êı     
}
void BigIntTrans(pBIGINT num1) //½«×Ö·û´®×ªÎªÊı×Ö±íÊ¾
{
   char *temp;					//ÁÙÊ±Êı×é 
   int i, k, len;
   len = strlen(num1->num);	//×Ö·û´®³¤¶È 
   if (!(temp = (char *) malloc(sizeof(char) * len)))	//·ÖÅäÄÚ´æ 
   {
	  printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
	  exit(0);
   }
   i = 0;
   num1->minus = 1;	//±£´æÎªÕıÊı 
   if (num1->num[0] == '-')	//ÅĞ¶ÏÊÇ·ñÎª¸ºÊı 
   {
	  num1->minus = -1;	//±£´æÎª¸ºÊı 
	  i++;
   }
   k = 0;	//Êı×ÖÎ»Êı¼ÆÊıÆ÷ 
   while (num1->num[i] != '\0')	//×Ö·û´®Î´½áÊø 
   {
	  if (num1->num[i] >= '0' && num1->num[i] <= '9')	//ÎªÊı×Ö0~9 
	  {
		 temp[k] = num1->num[i] - '0';	//½«ASCIIÂë×ª»»Îª¶ÔÓ¦Êı×Ö 
		 k++;
	  }
	  i++;
   }

   for (i = 0; i < num1->digit; i++)	//Çå¿ÕÊı×é¸÷ÔªËØ 
	  num1->num[i] = 0;
   num1->digit = k;	//×ª»»ºóµÄÊı¾İÎ»Êı 
   for (i = 0, k--; k >= 0; k--, i++)	//½«ÁÙÊ±Êı×é¸÷Î»·´ÖÃ±£´æµ½Êı×énumÖĞ 
	  num1->num[i] = temp[k];
   BigIntTrim(num1); //ÕûÀíÊäÈëµÄ´óÕûÊı 
}
void BigIntPrint(pBIGINT result) //Êä³ö´óÕûÊı 
{
   int j;
   if (result->minus == -1)	//ÊÇ¸ºÊı 
	  printf("-");	//Êä³ö¸ºÊı 
   if (result->digit == 1 && result->num[0] == 0)	//Èô´óÕûÊıÎª0
	  printf("0");
   else //²»Îª0 
   {
	  for (j = result->digit - 1; j >= 0; j--) //´Ó¸ßÎ»µ½µÍÎ»Êä³ö 
		 printf("%d", result->num[j]);
   }
}
int BigIntEqual(pBIGINT num1, pBIGINT num2) //±È½Ï¾ø¶ÔÖµ´óĞ¡
{
   int i;
   if (num1->digit > num2->digit)	//num1µÄÎ»Êı´óÓÚnum2 
	  return 1;
   else if (num1->digit < num2->digit)	//num1µÄÎ»ÊıĞ¡ÓÚnum2
	  return -1;
   else	//Á½ÊıÎ»ÊıÏàµÈ 
   {
	  i = num1->digit - 1;	//num1µÄÊı¾İÎ»Êı 
	  while (i >= 0)	//´Ó¸ßÎ»ÏòµÍÎ»±È
	  {
		 if (num1->num[i] > num2->num[i])	//num1¶ÔÓ¦Î»´óÓÚnum2
			return 1;
		 else if (num1->num[i] < num2->num[i])	//num1¶ÔÓ¦Î»Ğ¡ÓÚnum2
			return -1;
		 else
			i--; //±È½ÏÏÂÒ»Î» 
	  }
   }
   return 0;	//ÏàµÈ 
}
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
   int i;
   i = BigIntEqual(num1, num2);	//±È½ÏÁ½Êı¾ø¶ÔÖµ´óĞ¡
   if (i < 0)	//num1¾ø¶ÔÖµĞ¡ÓÚnum2 
   {
     pBIGINT temp;
     temp = num1;	//½»»»Á½Êı 
     num1 = num2;
     num2 = temp;
   }
   if (num1->minus * num2->minus < 0)	//·ûºÅ²»Í¬£¬ÔòÖ´¼õ·¨ 
   {	  
	  if (i == 0)	//Á½ÊıÏàµÈ
	  {
		 result->digit = 1;	//½á¹û³¤¶ÈÎªÒ»Î»Êı£¬¾ÍÊÇÊıÖµ0
		 result->num[0] = 0;	//½á¹ûÖµÎª0
		 result->minus = 1;	//½á¹ûÉèÎªÕıºÅ 
		 return;	//·µ»Ø 
	  } 
	  BigIntSub1(num1, num2, result);	//µ÷ÓÃÏà¼õº¯ÊıÍê³ÉÒìºÅÏà¼ÓµÄÇé¿ö
   } else
	  BigIntAdd1(num1, num2, result);	//µ÷ÓÃÏà¼Óº¯ÊıÍê³ÉÍ¬ºÅÏà¼Ó
}
void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
   int i, carry;
   carry = 0;
   result->minus = num1->minus;	//±£´æ·ûºÅ 
   for (i = 0; i < num1->digit; i++)	//½«±»¼ÓÊı¸´ÖÆµ½½á¹ûÊı×éÖĞ 
	  result->num[i] = num1->num[i];
   for (i = 0; i < num2->digit; i++)	//num2ÖĞµÄÊıĞ¡£¬¿ÉÄÜÎ»ÊıÒ²Ğ¡Ğ©
   {
	  result->num[i] = result->num[i] + num2->num[i] + carry;	//½«¶ÔÓ¦Î»µÄÊıºÍ½øÎ»ÊıÏà¼Ó 
	  carry = result->num[i] / 10;	//¼ÆËã½øÎ»Êı¾İ
	  result->num[i] = result->num[i] % 10;	//±£ÁôÒ»Î»     
   }
   if (carry)	//Èô×îºó»¹ÓĞ½øÎ» 
	  result->num[i] = result->num[i] + carry;
   BigIntTrim(result);	//ÕûÀí½á¹û 
}
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result) //ÒìºÅÏà¼õº¯Êı
{
   int i, borrow;
   result->minus = num1->minus;	//Òònum1¾ø¶ÔÖµ±Ènum2´ó£¬½á¹û·ûºÅÓënum1ÏàÍ¬ 
   borrow = 0;
   for (i = 0; i < num1->digit; i++)	//½«±»¼õÊıµÄÄÚÈİ¸´ÖÆµ½½á¹ûÖĞ 
	  result->num[i] = num1->num[i];
   for (i = 0; i <= num2->digit; i++)
   {
	  result->num[i] = result->num[i] - num2->num[i] - borrow;	//num1¼õÈ¥num2£¬²¢¼õÈ¥µÍÎ»µÄ½èÎ» 
	  if (result->num[i] < 0)	//ÈôÎª¸ºÊı 
	  {
		 result->num[i] = 10 + result->num[i];	//Ïò¸ßÎ»½èÎ» 
		 borrow = 1;	//ÉèÖÃ½èÎ»Öµ 
	  } else
		 borrow = 0;
   }
   if (borrow == 1)
	  result->num[i] = result->num[i] - borrow;
   BigIntTrim(result);
   /*i = num1->digit;
   while (i > 0)
   {
	  if (result->num[i] == 0)
		 i--;
	  else
		 break;
   }
   result->digit = i;	//±£´æ½á¹ûÎ»Êı*/
}
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result) //¼õ·¨º¯Êı 
{
   num2->minus = -1 * num2->minus;	//½«¼õÊıµÄ·ûºÅÈ¡·´ 
   BigIntAdd(num1, num2, result);	//µ÷ÓÃ¼Ó·¨º¯Êı 
}
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
   char carry, temp;
   int i, j, pos;
   for (i = 0; i < num1->digit + num2->digit; i++)	//½á¹ûÊı×éºÍÖĞ¼äÊı×éÇå0 
	  result->num[i] = 0;
   for (i = 0; i < num2->digit; i++)	//ÓÃ³ËÊıµÄÃ¿1Î»³ËÒÔ±»³ËÊı 
   {
	  carry = 0;	//Çå³ı½øÎ»
	  for (j = 0; j < num1->digit; j++)	//±»³ËÊıµÄÃ¿1Î» 
	  {
		 temp = num2->num[i] * num1->num[j] + carry;	//Ïà³Ë²¢¼ÓÉÏ½øÎ»
		 carry = temp / 10;	//¼ÆËã½øÎ»carry
		 temp = temp % 10;	//¼ÆËãµ±Ç°Î»µÄÖµ
		 pos = i + j;
		 result->num[pos] += temp;	//¼ÆËã½á¹ûÀÛ¼Óµ½ÁÙÊ±Êı×éÖĞ 
		 carry = carry + result->num[pos] / 10;	//¼ÆËã½øÎ» 
		 result->num[pos] = result->num[pos] % 10;
	  }
	  if (carry > 0)
	  {
		 result->num[i + j] = carry;	//¼ÓÉÏ×î¸ßÎ»½øÎ»
		 result->digit = i + j + 1;	//±£´æ½á¹ûÎ»Êı 
	  } else
		 result->digit = i + j;	//±£´æ½á¹ûÎ»Êı 
   }
   result->minus = num1->minus * num2->minus;	//½á¹ûµÄ·ûºÅ 
}
void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue) //³ı·¨º¯Êıº¯Êı ¡·´ õÈ¥µÍÎ»µÄ½èÎ» ënum1ÏàÍ¬ Êı
{
   BIGINT quo1, residuo1, quo2;
   int i, j, k, m;				//k±£´æÊÔÉÌ½á¹û,m±£´æÉÌµÄÎ»Êı 
   char t;
   result->minus = num1->minus * num2->minus;	//ÉÌµÄ·ûºÅ
   residue->num = (char *) malloc(sizeof(char) * num2->digit);	//·ÖÅäÓàÊıµÄÄÚ´æ¿Õ¼ä
   residue->digit = num2->digit+1;	//ÉèÖÃÓàÊıµÄ³õÊ¼Î»ÊıÓë³ıÊıÏàÍ¬ 
   for (i = 0; i < residue->digit; i++)	//½«ÓàÊıÈ«²¿Çå0 
	  residue->num[i] = 0;
   m = 0;
   for (i = num1->digit - 1; i >= 0; i--)
   {
	  residue->digit=num2->digit+1; //ÖØĞÂÉèÖÃÓàÊıµÄÎ»Êı±È³ıÊı¶àÒ»Î» 
	  for (j = residue->digit - 1; j > 0; j--)	//ÒÆÓàÊı 
		 residue->num[j] = residue->num[j - 1];	//½«ĞòºÅµÍÎ»µÄÊı¾İÒÆÏò¸ßÎ»(Êµ¼ÊÊÇ½«ÓàÊıÖĞµÄ×î¸ßÎ»È¥³ı) 
	  residue->num[0] = num1->num[i];	//¸´ÖÆ±»³ıÊıÖĞµÄÒ»Î»µ½ÓàÊıµÄ×îµÍÎ»ÖĞ 
	  BigIntTrim(residue);//ÕûÀíÓàÊı 
      k = 0;	//ÊÔÉÌ
	  while (BigIntEqual(residue, num2) >= 0)	//±È½ÏÓàÊıÓë³ıÊıµÄ´óĞ¡
	  {
		 BigIntSub1(residue, num2, residue);	//ÓÃÓàÊı¼õÈ¥³ıÊı£¬²îÖµ±£´æÔÚÓàÊıÖĞ
		 k++;	//ÊÔÉÌ¼Ó1 
	  }
	  result->num[m++] = k;	//±£´æÉÌ    
   }
   result->digit = m;	//±£´æÉÌµÄÎ»Êı 
   for (i = 0; i < m / 2; i++)	//½«ÉÌ¸÷Î»·´×ª(ÔÚ¼ÆËã¹ı³ÌÖĞĞòºÅ0±£´æµÄÊÇÉÌµÄ¸ßÎ») 
   {
	  t = result->num[i];
	  result->num[i] = result->num[m - 1 - i];
	  result->num[m - 1 - i] = t;
   }
   BigIntTrim(result);	//ÕûÀíÉÌ 
   BigIntTrim(residue);	//ÕûÀíÓàÊı 
}
int main()
{
   BIGINT num1, num2, result, residue;	//²ÎÓëÔËËãµÄÊı¡¢½á¹û¡¢ÓàÊı 
   int i = 0, len;
   char op;
   printf("ÊäÈë×î´óÊıµÄÎ»Êı:");
   scanf("%d", &len);
   if (!(num1.num = (char *) malloc(sizeof(char) * (len + 1))))
   {
	  printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
	  exit(0);
   }
   num1.digit = len + 1;
   if (!(num2.num = (char *) malloc(sizeof(char) * (len + 1))))
   {
	  printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
	  exit(0);
   }
   num2.digit = len + 1;
   if (!(result.num = (char *) malloc(sizeof(char) * (2 * len + 1))))
   {
	  printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
	  exit(0);
   }
   result.digit = 2 * len + 1;
   for (i = 0; i < result.digit; i++)	//Çå¿Õ½á¹û¼¯ 
	  result.num[i] = 0;
   printf("Ñ¡Ôñ´óÕûÊıµÄÔËËã(+¡¢-¡¢*¡¢/):");
   fflush(stdin);
   scanf("%c", &op);
   switch (op)
   {
   case '+':
	  printf("\nÊäÈë±»¼ÓÊı:");
	  scanf("%s", num1.num);
	  printf("\nÊäÈë¼ÓÊı:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  BigIntAdd(&num1, &num2, &result);	//¼Ó·¨ 
	  break;
   case '-':
	  printf("\nÊäÈë±»¼õÊı:");
	  scanf("%s", num1.num);
	  printf("\nÊäÈë¼õÊı:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  BigIntSub(&num1, &num2, &result);	//¼õ·¨ 
	  break;
   case '*':
	  printf("\nÊäÈë±»³ËÊı:");
	  scanf("%s", num1.num);
	  printf("\nÊäÈë³ËÊı:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  BigIntMul(&num1, &num2, &result);	//³Ë·¨ 
	  break;
   case '/':
	  printf("\nÊäÈë±»³ıÊı:");
	  scanf("%s", num1.num);
	  printf("\nÊäÈë³ıÊı:");
	  scanf("%s", num2.num);
	  BigIntTrans(&num1);
	  BigIntTrans(&num2);
	  if (num2.digit == 1 && num2.num[0] == 0)	//´óÕûÊıÎª0
		 printf("³ıÊı²»ÄÜÎª0!\n");
	  else
		 BigIntDiv(&num1, &num2, &result, &residue);	//³ı·¨·¨ 
	  break;
   }
   if (op == '/')
   {
	  if (!(num2.digit == 1 && num2.num[0] == 0))	//Îª³ı·¨ÇÒ³ıÊı²»Îª0
	  {
		 printf("ÉÌ:");
		 BigIntPrint(&result);
		 printf("\tÓàÊı:");
		 BigIntPrint(&residue);
	  }
   } else
   {
	  printf("\n½á¹û:");
	  BigIntPrint(&result);
   }

   getch();
   return 0;
}
