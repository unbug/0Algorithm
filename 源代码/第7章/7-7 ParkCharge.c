#include "stdio.h"
#include "time.h"
#define MAXNUM 5 //停车场车位数 
#define PRICE 2.0 //每小时收费 
typedef struct car //定义车的结构体
{
   char num[10]; //车牌号(最多10个字节) 
   struct tm intime; //进入时间 
   struct tm outtime; //离开时间 
   int expense; //费用 
   int length; //停车时长 
   int position; //停车位 
}CAR;
typedef struct //栈结构 
{
   CAR car[MAXNUM]; //车辆信息 
   int top; //栈顶指针 
} SeqStack;
void StackInit(SeqStack * s) //初始化栈
{
   s->top = -1; 
}
int StackIsEmpty(SeqStack * s) //判断栈是否为空
{
   if (s->top == -1)
	  return 1;
   else
	  return 0;
}
int StackIsFull(SeqStack *s) //判断栈是否为满
{
   if (s->top == MAXNUM - 1)
	  return 1;
   else
	  return 0;
}
void StackPush(SeqStack *s, CAR car)	// 进栈
{
   if (!StackIsFull(s)) //若栈未满 
   {
	  s->top++; //修改栈顶指针 
	  s->car[s->top] = car; //将车辆信息入栈 
   }
}
CAR StackPop(SeqStack *s)	//出栈
{
   CAR car;
   if (s->top != -1) //栈不为空 
   {
	  car = s->car[s->top];
	  s->top--;
	  return car;
   }
}
CAR StackGetTop(SeqStack * s)		//取栈顶元素
{
   CAR car;
   if (s->top != -1)
   {
	  car = s->car[s->top];
	  return car;
   }

}
//队列链表
typedef struct carnode			//定义链队列的节点 
{
   CAR data;
   struct carnode *next;
}CarNodeType;
typedef struct					//链队列 
{
   CarNodeType *head; //头指针 
   CarNodeType *rear; //尾指针 
}CarChainQueue;
void ChainQueueInit(CarChainQueue * q) //初始化链队列接点性质
{
   if(!(q->head = (CarNodeType *) malloc(sizeof(CarNodeType))))
   {
       printf("内存分配失败!\n");
       exit(0); 
   }
   q->rear = q->head; //头尾指针相同 
   q->head->next = NULL; //头尾指针后下一个节点为空 
   q->rear->next = NULL;
}
void ChainQueueIn(CarChainQueue * q, CAR car)	//入队列
{
   CarNodeType *p;
   if(!(p = (CarNodeType *) malloc(sizeof(CarNodeType))))
   {
       printf("内存分配失败!\n");
       exit(0); 
   }
   p->data = car;
   p->next = NULL;
   q->rear->next = p;
   q->rear = p;
}
CAR ChainQueueOut(CarChainQueue * q)		//出队列
{
   CarNodeType *p;
   CAR car;
   if (q->head != q->rear)
   {
	  p = q->head->next;
	  if (p->next == NULL)
	  {
		 car = p->data;
		 q->rear = q->head;
		 free(p);
	  } else
	  {
		 q->head->next = p->next;
		 car = p->data;
		 free(p);
	  }
	  return car;
   }

}
int ChainQueueIsEmpty(CarChainQueue * q) //判断链队列是否为空
{
   if (q->rear == q->head) //若队首等于列尾 
	  return 1; //返回空 
   else
	  return 0; //返回非空 

}
void separator(int n,char ch,char newline) //输出多个字符 
{
   int i;
   for(i=0;i<n;i++)
       printf("%c",ch);
   if(newline==1)
       printf("\n");
}
void PrintDate(struct tm gm_date)
{
    printf("%d/%d %02d:%02d:%02d\n", gm_date.tm_mon,gm_date.tm_mday,gm_date.tm_hour+8, gm_date.tm_min, gm_date.tm_sec);
}
void ShowPark(SeqStack *s) //查看车位状态 
{
   int i;
   struct tm gm_date;
   printf("\n车位使用情况\n");
   separator(40,'_',1);
   if (StackIsEmpty(s)) //若栈是空 
	  printf("停车场内已没有车辆!\n");
   else
   {
	  printf("位置\t车牌号\t进站时间\n");
	  for (i = 0; i <= s->top; i++)
	  {
		 printf("%d\t", s->car[i].position);
		 printf("%s\t", s->car[i].num);
		 PrintDate(s->car[i].intime); //输出日期 
	  }
	  printf("\t\t\t共%d辆", s->top + 1);
	  if (s->top == MAXNUM - 1)
		 printf("(已满)\n");
	  else
		 printf("(还可停放放%d辆)\n", MAXNUM - 1 - s->top);
	  printf("\n");
   }
   separator(40,'_',1);
}
void ShowAisle(CarChainQueue * q)//显示过道上车辆的情况 
{
   if (!ChainQueueIsEmpty(q)) //若队列不为空 
   {
	  CarNodeType *p;
	  p = q->head->next; //队列中的第1辆车 
	  printf("\n\n过道使用情况\n"); 
	  separator(30,'_',1);
	  printf("车牌\t进入时间\n");
	  while (p!= NULL) //队列不为空 
	  {
         printf("%s\t", p->data.num);
         PrintDate(p->data.intime);; //显示该辆车的信息 
         p = p->next; //下一辆 
	  }
   } else
	  printf("\n过道上没有车在等待\n");
   separator(30,'_',1); 
   printf("\n\n");
}
void ShowAll(SeqStack *s, CarChainQueue *q) //查看车位和过道使用情况 
{
   ShowPark(s); //显示车位使用情况 
   ShowAisle(q); //显示过道使用情况 
}
void InPark(SeqStack * s, CarChainQueue * q) //车辆进入停车场 
{
   CAR car;
   struct tm *gm_date;
   time_t seconds;
   time(&seconds);
   gm_date = gmtime(&seconds);;

   printf("\n车牌号:");
   scanf("%s",&car.num);   
   car.intime=*gm_date; //进入停车场的时间 

   if (!StackIsFull(s) && ChainQueueIsEmpty(q))	//如果车位未占完，且过道上没有车
   {
	  car.position = (s->top) + 2; //车位号 
	  StackPush(s, car); //车辆直接进入车位 
	  ShowPark(s); //输出现在停车场的情况 
   }
   else if (StackIsFull(s) || !ChainQueueIsEmpty(q)) //如果车位已满，过道上还有车，则必须放在过道上
   {
	  printf("提示：车位满,只有先停放在过道中。\n");
	  car.position = MAXNUM;
	  ChainQueueIn(q, car);	//停放在过道

	  ShowPark(s);	//显示车位的情况         
	  ShowAisle(q);	//输出过道上的情况
   }
}
void PrintRate(CAR *car)		//离开时输出费用等情况 
{
   printf("\n\n      账单\n" );
   separator(30,'_',1);
   printf("车牌:%s\n", car->num);
   printf("停车位置:%d\n", car->position);
   printf("进入时间:");
   PrintDate(car->intime);
   printf("离开时间:"); 
   PrintDate(car->outtime);  
   printf("停车时间(秒):%d\n", car->length);
   printf("费用(元):%d\n", car->expense);
   separator(30,'_',1);
   printf("\n\n");
}
void OutPark(SeqStack *s, CarChainQueue *q) //车出站出当时过道上的情况放在过道上直接进入车站
{
   struct tm *gm_date;
   time_t seconds;

   SeqStack p;					//申请临时放车的地方
   StackInit(&p);
   char nowtime[10];
   int i, pos;
   CAR car;

   if (StackIsEmpty(s)) //如果车位中没有车辆停放 
   {
	  printf("所有车位都为空，没有车辆需要离开!\n");
   }
   else
   {
	  printf("现在车位使用情况是:\n");
	  ShowPark(s); //输出车位使用情况 
	  printf("哪个车位的车辆要离开:");
	  scanf("%d", &pos);
	  if (pos > 0 && pos <= s->top + 1) //输入车位号正确 
	  {
		 for (i = s->top + 1; i > pos; i--) //在将pos车位之后停的车放入临时栈，以使pos车位的车出来 
		 {
			car = StackPop(s); //出栈 
			car.position = car.position - 1;//修改车位号
			StackPush(&p, car); //将车辆放入临时栈 
		 }
		 car = StackPop(s); //将位于pos车位的车辆出栈 
		 time(&seconds);
		 gm_date = gmtime(&seconds); //获取当前时间 
		 car.outtime=*gm_date;//离开时间 
		 car.length=mktime(&car.outtime)-mktime(&car.intime); //停车场中停放时间 
		 car.expense=(car.length/3600+1)*PRICE; //费用 
		 PrintRate(&car);	//输出车出站时的情况---进入时间，出站时间，原来位置，花的费用等
		 while (!StackIsEmpty(&p))	//将临时栈中的车重新进入车位
		 {
			car = StackPop(&p); //从临时栈中取出一辆车 
			StackPush(s, car); //将车进入车位 
		 }
		 while(!StackIsFull(s) && !ChainQueueIsEmpty(q)) //如果车位未满, 且过道上还有车 
		 {
			car = ChainQueueOut(q); //将最先停在过道中的车辆进入车位
			time(&seconds);
			gm_date = gmtime(&seconds); //获取当前时间 
			car.intime = *gm_date;//保存进入车位的时间 
			StackPush(s, car); //将车辆进入车位 
		 }
	  }
      else //车位号输入错误 
	  {
		 printf("车位号输入错误，或该车位没有车辆!\n");
	  }
   }
}
int main()
{
   SeqStack Park; //停车场栈 
   CarChainQueue Aisle; //过道链表 
   StackInit(&Park);
   ChainQueueInit(&Aisle);
   char choice;
   do{
       printf("\n\n");
       separator(10,' ',0);
       printf("停车场管理\n");
       separator(30,'_',1);
       printf("1.车辆进入\n");
       printf("2.车辆离开\n");
       printf("3.查看停车场情况\n");        
       printf("0.退出系统\n");
       separator(56,'_',1);
       printf("提示：本停车场有%d个车位，车位停满后的车辆将停放在过道上。\n",MAXNUM);
       printf("本停车场时计费，收费标准:%.2f元/小时,过道上不收费。\n\n",PRICE);
       printf("\n选择操作(0~3):");
       fflush(stdin);
       choice=getchar();
       switch (choice)
       {
       case '1': //车辆进入 
          InPark(&Park,&Aisle);
          break;
       case '2': //车辆离开 
          OutPark(&Park,&Aisle);
          break;
       case '3':
          ShowAll(&Park,&Aisle);
          break;
       }
   }while(choice!='0');
   return 0;
}
