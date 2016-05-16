#include <stdio.h>
#define MAXN 50
#define MAXK 3
typedef struct VERTEX
{
   int x, y;	//µãµÄ×ø±ê 
}VERTEX;
typedef struct rect
{
   VERTEX lt;	//×óÉÏ½Ç×ø±ê
   VERTEX rb;	//ÓÒÏÂ½Ç×ø±ê 
}RECT;
RECT rect[MAXK]; 
VERTEX v[MAXK][MAXN];	//±£´æ¶¥µãÊı  
int n, k;
int intersect(RECT rect1, RECT rect2) //ÅĞ¶ÏÁ½¾ØĞÎÊÇ·ñÓĞ¹«¹²µã(ÊÇ·ñ½»²æ)
{
   if (rect2.lt.x > rect1.rb.x || rect1.lt.x > rect2.rb.x)	//¾ØĞÎ2×ó±ß´óÓÚ¾ØĞÎ1µÄÓÒ±ß /»ò¾ØĞÎ1×ó±ß´óÓÚ¾ØĞÎ2µÄÓÒ±ß 
	  return 0;
   if (rect2.lt.y > rect1.rb.y || rect1.lt.y > rect2.rb.y)	//¾ØĞÎ2ÉÏ±ß´óÓÚ¾ØĞÎ1µÄµ×±ß /»ò¾ØĞÎ1µÄÉÏ±ß´óÓÚ¾ØĞÎ2µÄµ×±ß
	  return 0;
   return 1;
}
int area(RECT rect) //Çó¾ØĞÎÃæ»ıóÓÚ¾ØĞÎ1µÄµ×±ß /»ò¾ØĞÎ1µÄÉÏ±ß´óÓÚ¾ØĞÎ2µÄµ×±ß
{
   int height, s;
   height = rect.rb.y - rect.lt.y;	//¸ß¶È 
   s = height * (rect.rb.x - rect.lt.x);
   return s;	//·µ»ØÃæ»ı    
}
void insert(VERTEX v, RECT * rect) //½«µã·ÅÈë¾ØĞÎ£¬²¢¸ù¾İÇé¿öµ÷Õû¾ØĞÎµÄ×ø±ê ´óÓÚ¾ØĞÎ2µÄµ×±ß
{
   if (v.x < rect->lt.x)	//µãµÄx×ø±êĞ¡ÓÚ¾ØĞÎ×ó²à×ø±ê 
	  rect->lt.x = v.x;	//µ÷Õû¾ØĞÎ×ó²à×ø±ê 
   if (v.x > rect->rb.x)
	  rect->rb.x = v.x;
   if (v.y < rect->lt.y)
	  rect->lt.y = v.y;
   if (v.y > rect->rb.y)
	  rect->rb.y = v.y;
}
int calc() //ÊÔÌ½¼ÆËã¸÷¾ØĞÎµÄÃæ»ı ×ø±ê Õû¾ØĞÎµÄ×ø±ê ´óÓÚ¾ØĞÎ2µÄµ×±ß
{
   VERTEX v0;	//ÁÙÊ±½»»»Ê¹ÓÃ 
   int i, j, m, s, temp, min;
   min = 2147483647;	//±£´æÒ»¸ö×î´óÖµ 
   switch (k)	//¸ù¾İ¾ØĞÎ¸öÊı½øĞĞ²»Í¬´¦Àí 
   {
   case 1:	//k=1µÄÇé¿ö
      rect[0].lt.x=v[0][1].x; //ºáÏòÉıĞòÅÅÁĞ×ø±êµÄxÖµ 
      rect[0].lt.y=v[1][1].y; //×İÏòÉıĞòÅÅÁĞ×ø±êµÄyÖµ 
      rect[0].rb.x=v[0][n].x; //ºáÏòÉıĞòÅÅÁĞ×ø±êµÄyÖµ 
      rect[0].rb.y=v[1][n].y;//×İÏòÉıĞòÅÅÁĞ×ø±êµÄyÖµ 
	  min = area(rect[0]);	//¼ÆËãÃæ»ı 
	  break;
   case 2:	//k=2µÄÇé¿ö 
	  for (s = 0; s <= 1; s++)
	  {
		 rect[0].lt = rect[1].rb = v[s][1];	//µÚ1¸ö¾ØĞÎ
		 for (i = 2; i <= n; i++)	//½«¸÷µãÊÔ×Å·ÅÈëµÚ2¸ö¾ØĞÎ 
		 {
			insert(v[s][i - 1], &rect[0]);	//½«µÚi-1µã·ÅÈë¾ØĞÎ1
			rect[1].lt = rect[2].rb = v[s][i];	//ÉèÖÃµÚ2¸ö¾ØĞÎµÄ³õÊ¼Öµ 
			for (m = i + 1; m <= n; m++)	//½«Ê£ÓàµãÌí¼Óµ½¾ØĞÎ2 
			   insert(v[s][m], &rect[1]);
			if (!intersect(rect[0], rect[1]))	//ÈôÁ½¾ØĞÎ²»Ïà½» 
			{
			   temp = 0;
			   for (m = 0; m < k; m++)	//¼ÆËãÁ½¾ØĞÎÃæ»ı 
				  temp += area(rect[m]);
			   if (temp < min)	//ÈôÁ½¾ØĞÎÃæ»ıĞ¡ÓÚmin 
				  min = temp;	//±£´æ½ÏĞ¡µÄÃæ»ı 
			}
		 }
	  }
	  break;
   case 3:
	  //flag=0,1µÄÇé¿ö
	  for (s = 0; s <= 1; s++)
	  {
		 rect[0].lt = rect[0].rb = v[s][1];	//µÚ1¸ö¾ØĞÎ 
		 for (i = 2; i <= n - 1; i++)	//½«¸÷µãÊÔ×Å·ÅÈëµÚ2¸ö¾ØĞÎ 
		 {
			insert(v[s][i - 1], &rect[0]);	//½«µÚi-1µã·ÅÈë¾ØĞÎ1
			rect[1].lt = rect[1].rb = v[s][i];	//ÉèÖÃµÚ2¸ö¾ØĞÎµÄ³õÊ¼Öµ 
			if (intersect(rect[0], rect[1]))	//ÈôÁ½¸ö¾ØĞÎÏà½» 
			   continue;	//¼ÌĞø´¦ÀíÏÂÒ»¸ö¾ØĞÎ 
			for (j = i + 1; j <= n; j++)	//½«¸÷µãÊÔ×Å·ÅÈëµÚ2¸ö¾ØĞÎ 
			{
			   insert(v[s][j - 1], &rect[1]);	//½«µÚi-1µã·ÅÈë¾ØĞÎ1
			   rect[2].lt = rect[2].rb = v[s][j];	//ÉèÖÃµÚ3¸ö¾ØĞÎµÄ³õÊ¼Öµ 
			   for (m = j + 1; m <= n; m++)	//½«Ê£ÓàµãÌí¼Óµ½¾ØĞÎ3 
				  insert(v[s][m], &rect[2]);
			   if (intersect(rect[1], rect[2]))	//Èô¾ØĞÎ2Óë¾ØĞÎ3Ïà½» 
				  continue;	//¼ÌĞø´¦ÀíÏÂÒ»¸ö¾ØĞÎ 
			   temp = 0;
			   for (m = 0; m < k; m++)	//¼ÆËã¸÷¾ØĞÎÃæ»ı 
				  temp += area(rect[m]);
			   if (temp < min)
				  min = temp;
			}
		 }
	  }
	  //flag=2µÄÇé¿ö:ÏÈÊúÖ±»®·Ö´ó¾ØĞÎ£»ÔÙÔÚÓÒ¾ØĞÎÖĞË®Æ½»®·Ö
	  rect[0].lt = rect[0].rb = v[0][1];	//µÚ1¸ö¾ØĞÎ³õÊ¼Öµ 
	  for (i = 2; i <= n - 1; i++)
	  {
		 for (m = 1; m <= n; m++)	//v[2][i]±£´æºá×ø±ê×ø±ê 
			v[2][m] = v[0][m];
		 for (m = i; m <= n - 1; m++)	//½«v[2][i]°´×ø×ø±êÉıĞòÅÅĞò 
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
		 insert(v[2][i - 1], &rect[0]);	//½«µÚi-1µã·ÅÈë¾ØĞÎ1
		 rect[1].lt = rect[1].rb = v[2][i];	//ÉèÖÃµÚ2¸ö¾ØĞÎ³õÊ¼Öµ
		 if (intersect(rect[0], rect[1]))	//¾ØĞÎ1Óë¾ØĞÎ2Ïà½» 
			continue;
		 for (j = i + 1; j <= n; j++)
		 {
			insert(v[2][j - 1], &rect[1]);	//½«µÚj-1µã·ÅÈë¾ØĞÎ2
			rect[2].lt = rect[2].rb = v[2][j];	//ÉèÖÃµÚ3¸ö¾ØĞÎ³õÊ¼Öµ 
			for (m = j + 1; m <= n; m++)	//½«ºóĞø¶¥µã·ÅÈë¾ØĞÎ3
			   insert(v[2][m], &rect[2]);
			if (intersect(rect[1], rect[2]))	//Èô¾ØĞÎ2Óë¾ØĞÎ3Ïà½» 
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)	//¼ÆËã¸÷¾ØĞÎµÄÃæ»ı 
			   temp += area(rect[m]);
			if (temp < min)	//±£´æÃæ»ı×îĞ¡Öµ 
			   min = temp;
		 }
	  }
	  //flag=3µÄÇé¿ö 
	  for (j = 3; j <= n; j++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[0][m];
		 for (m = 1; m <= j - 2; m++)	//°´×İ×ø±êÅÅĞò 
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
		 rect[2].lt = rect[2].rb = v[2][j];	//³õÊ¼»¯µÚ3¸ö¾ØĞÎ 
		 for (m = j + 1; m <= n; m++)	//½«µãÔö¼Óµ½µÚ3¸ö¾ØĞÎ 
			insert(v[2][m], &rect[2]);
		 for (i = 2; i <= j - 1; i++)
		 {
			rect[1].lt = rect[1].rb = v[2][i];	//ÉèÖÃµÚ2¸ö¾ØĞÎ³õÊ¼Öµ 
			for (m = i + 1; m <= j - 1; m++)	//½«µãÌí¼Óµ½µÚ2¸ö¾ØĞÎ 
			   insert(v[2][m], &rect[1]);
			rect[0].lt = rect[0].rb = v[2][1];	//ÉèÖÃµÚ1¸ö¾ØĞÎ³õÊ¼Öµ 
			for (m = 2; m <= i - 1; m++)	//½«µãÌíµ½¼ÓµÚ1¸ö¾ØĞÎ 
			   insert(v[2][m], &rect[0]);
			if (intersect(rect[0], rect[1]) || intersect(rect[1], rect[2])
			   || intersect(rect[0], rect[2]))	//Èô3¸ö¾ØĞÎÓĞÏà½»ÇéĞÎ 
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)	//¼ÆËã¸÷¾ØĞÎÃæ»ı 
			   temp += area(rect[m]);
			if (temp < min)	//±£´æ×îĞ¡Ãæ»ı 
			   min = temp;
		 }
	  }
	  //flag=4µÄÇé¿ö 
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
	  //flag=5µÄÇé¿ö 
	  rect[0].lt = rect[0].rb = v[1][1];	//µÚ1¸ö¾ØĞÎ³õÊ¼Öµ 
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
   VERTEX v0;	//ÁÙÊ±½»»»ÓÃ¶¥µã 
   int i, j, value;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("rectang.in", "r")) == NULL)
   {
	  printf("²»ÄÜ´ò¿ªÎÄ¼ş!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d\n", &n, &k);	//¶ÁÈëµãÊınºÍ¾ØĞÎÊık
   for (i = 1; i <= n; i++)	//¶ÁÈë¸÷µãµÄ×ø±ê 
   {
	  fscanf(fp1, "%d%d\n", &v[0][i].x, &v[0][i].y);
	  v[1][i] = v[0][i];
   }
   fclose(fp1);
   for (i = 1; i <= n - 1; i++)	//°´ºá×ø±êÉıĞòÅÅÁĞ¸÷µã£¬´æÈëv[0][i]
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
   for (i = 1; i <= n - 1; i++)	//½«×İ×ø±êÉıĞòÅÅÁĞ£¬´æÈëv[i][1] 
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
	  printf("²»ÄÜ´ò¿ªÎÄ¼ş!\n");
	  exit(1);
   }
   printf("%d\n", value);
   fprintf(fp2, "%d\n", value);
   fclose(fp2);
   getch();
   return 0;
}
