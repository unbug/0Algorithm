#include "stdio.h"
#include "time.h"
#define MAXNUM 5 //ͣ������λ�� 
#define PRICE 2.0 //ÿСʱ�շ� 
typedef struct car //���峵�Ľṹ��
{
   char num[10]; //���ƺ�(���10���ֽ�) 
   struct tm intime; //����ʱ�� 
   struct tm outtime; //�뿪ʱ�� 
   int expense; //���� 
   int length; //ͣ��ʱ�� 
   int position; //ͣ��λ 
}CAR;
typedef struct //ջ�ṹ 
{
   CAR car[MAXNUM]; //������Ϣ 
   int top; //ջ��ָ�� 
} SeqStack;
void StackInit(SeqStack * s) //��ʼ��ջ
{
   s->top = -1; 
}
int StackIsEmpty(SeqStack * s) //�ж�ջ�Ƿ�Ϊ��
{
   if (s->top == -1)
	  return 1;
   else
	  return 0;
}
int StackIsFull(SeqStack *s) //�ж�ջ�Ƿ�Ϊ��
{
   if (s->top == MAXNUM - 1)
	  return 1;
   else
	  return 0;
}
void StackPush(SeqStack *s, CAR car)	// ��ջ
{
   if (!StackIsFull(s)) //��ջδ�� 
   {
	  s->top++; //�޸�ջ��ָ�� 
	  s->car[s->top] = car; //��������Ϣ��ջ 
   }
}
CAR StackPop(SeqStack *s)	//��ջ
{
   CAR car;
   if (s->top != -1) //ջ��Ϊ�� 
   {
	  car = s->car[s->top];
	  s->top--;
	  return car;
   }
}
CAR StackGetTop(SeqStack * s)		//ȡջ��Ԫ��
{
   CAR car;
   if (s->top != -1)
   {
	  car = s->car[s->top];
	  return car;
   }

}
//��������
typedef struct carnode			//���������еĽڵ� 
{
   CAR data;
   struct carnode *next;
}CarNodeType;
typedef struct					//������ 
{
   CarNodeType *head; //ͷָ�� 
   CarNodeType *rear; //βָ�� 
}CarChainQueue;
void ChainQueueInit(CarChainQueue * q) //��ʼ�������нӵ�����
{
   if(!(q->head = (CarNodeType *) malloc(sizeof(CarNodeType))))
   {
       printf("�ڴ����ʧ��!\n");
       exit(0); 
   }
   q->rear = q->head; //ͷβָ����ͬ 
   q->head->next = NULL; //ͷβָ�����һ���ڵ�Ϊ�� 
   q->rear->next = NULL;
}
void ChainQueueIn(CarChainQueue * q, CAR car)	//�����
{
   CarNodeType *p;
   if(!(p = (CarNodeType *) malloc(sizeof(CarNodeType))))
   {
       printf("�ڴ����ʧ��!\n");
       exit(0); 
   }
   p->data = car;
   p->next = NULL;
   q->rear->next = p;
   q->rear = p;
}
CAR ChainQueueOut(CarChainQueue * q)		//������
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
int ChainQueueIsEmpty(CarChainQueue * q) //�ж��������Ƿ�Ϊ��
{
   if (q->rear == q->head) //�����׵�����β 
	  return 1; //���ؿ� 
   else
	  return 0; //���طǿ� 

}
void separator(int n,char ch,char newline) //�������ַ� 
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
void ShowPark(SeqStack *s) //�鿴��λ״̬ 
{
   int i;
   struct tm gm_date;
   printf("\n��λʹ�����\n");
   separator(40,'_',1);
   if (StackIsEmpty(s)) //��ջ�ǿ� 
	  printf("ͣ��������û�г���!\n");
   else
   {
	  printf("λ��\t���ƺ�\t��վʱ��\n");
	  for (i = 0; i <= s->top; i++)
	  {
		 printf("%d\t", s->car[i].position);
		 printf("%s\t", s->car[i].num);
		 PrintDate(s->car[i].intime); //������� 
	  }
	  printf("\t\t\t��%d��", s->top + 1);
	  if (s->top == MAXNUM - 1)
		 printf("(����)\n");
	  else
		 printf("(����ͣ�ŷ�%d��)\n", MAXNUM - 1 - s->top);
	  printf("\n");
   }
   separator(40,'_',1);
}
void ShowAisle(CarChainQueue * q)//��ʾ�����ϳ�������� 
{
   if (!ChainQueueIsEmpty(q)) //�����в�Ϊ�� 
   {
	  CarNodeType *p;
	  p = q->head->next; //�����еĵ�1���� 
	  printf("\n\n����ʹ�����\n"); 
	  separator(30,'_',1);
	  printf("����\t����ʱ��\n");
	  while (p!= NULL) //���в�Ϊ�� 
	  {
         printf("%s\t", p->data.num);
         PrintDate(p->data.intime);; //��ʾ����������Ϣ 
         p = p->next; //��һ�� 
	  }
   } else
	  printf("\n������û�г��ڵȴ�\n");
   separator(30,'_',1); 
   printf("\n\n");
}
void ShowAll(SeqStack *s, CarChainQueue *q) //�鿴��λ�͹���ʹ����� 
{
   ShowPark(s); //��ʾ��λʹ����� 
   ShowAisle(q); //��ʾ����ʹ����� 
}
void InPark(SeqStack * s, CarChainQueue * q) //��������ͣ���� 
{
   CAR car;
   struct tm *gm_date;
   time_t seconds;
   time(&seconds);
   gm_date = gmtime(&seconds);;

   printf("\n���ƺ�:");
   scanf("%s",&car.num);   
   car.intime=*gm_date; //����ͣ������ʱ�� 

   if (!StackIsFull(s) && ChainQueueIsEmpty(q))	//�����λδռ�꣬�ҹ�����û�г�
   {
	  car.position = (s->top) + 2; //��λ�� 
	  StackPush(s, car); //����ֱ�ӽ��복λ 
	  ShowPark(s); //�������ͣ��������� 
   }
   else if (StackIsFull(s) || !ChainQueueIsEmpty(q)) //�����λ�����������ϻ��г����������ڹ�����
   {
	  printf("��ʾ����λ��,ֻ����ͣ���ڹ����С�\n");
	  car.position = MAXNUM;
	  ChainQueueIn(q, car);	//ͣ���ڹ���

	  ShowPark(s);	//��ʾ��λ�����         
	  ShowAisle(q);	//��������ϵ����
   }
}
void PrintRate(CAR *car)		//�뿪ʱ������õ���� 
{
   printf("\n\n      �˵�\n" );
   separator(30,'_',1);
   printf("����:%s\n", car->num);
   printf("ͣ��λ��:%d\n", car->position);
   printf("����ʱ��:");
   PrintDate(car->intime);
   printf("�뿪ʱ��:"); 
   PrintDate(car->outtime);  
   printf("ͣ��ʱ��(��):%d\n", car->length);
   printf("����(Ԫ):%d\n", car->expense);
   separator(30,'_',1);
   printf("\n\n");
}
void OutPark(SeqStack *s, CarChainQueue *q) //����վ����ʱ�����ϵ�������ڹ�����ֱ�ӽ��복վ
{
   struct tm *gm_date;
   time_t seconds;

   SeqStack p;					//������ʱ�ų��ĵط�
   StackInit(&p);
   char nowtime[10];
   int i, pos;
   CAR car;

   if (StackIsEmpty(s)) //�����λ��û�г���ͣ�� 
   {
	  printf("���г�λ��Ϊ�գ�û�г�����Ҫ�뿪!\n");
   }
   else
   {
	  printf("���ڳ�λʹ�������:\n");
	  ShowPark(s); //�����λʹ����� 
	  printf("�ĸ���λ�ĳ���Ҫ�뿪:");
	  scanf("%d", &pos);
	  if (pos > 0 && pos <= s->top + 1) //���복λ����ȷ 
	  {
		 for (i = s->top + 1; i > pos; i--) //�ڽ�pos��λ֮��ͣ�ĳ�������ʱջ����ʹpos��λ�ĳ����� 
		 {
			car = StackPop(s); //��ջ 
			car.position = car.position - 1;//�޸ĳ�λ��
			StackPush(&p, car); //������������ʱջ 
		 }
		 car = StackPop(s); //��λ��pos��λ�ĳ�����ջ 
		 time(&seconds);
		 gm_date = gmtime(&seconds); //��ȡ��ǰʱ�� 
		 car.outtime=*gm_date;//�뿪ʱ�� 
		 car.length=mktime(&car.outtime)-mktime(&car.intime); //ͣ������ͣ��ʱ�� 
		 car.expense=(car.length/3600+1)*PRICE; //���� 
		 PrintRate(&car);	//�������վʱ�����---����ʱ�䣬��վʱ�䣬ԭ��λ�ã����ķ��õ�
		 while (!StackIsEmpty(&p))	//����ʱջ�еĳ����½��복λ
		 {
			car = StackPop(&p); //����ʱջ��ȡ��һ���� 
			StackPush(s, car); //�������복λ 
		 }
		 while(!StackIsFull(s) && !ChainQueueIsEmpty(q)) //�����λδ��, �ҹ����ϻ��г� 
		 {
			car = ChainQueueOut(q); //������ͣ�ڹ����еĳ������복λ
			time(&seconds);
			gm_date = gmtime(&seconds); //��ȡ��ǰʱ�� 
			car.intime = *gm_date;//������복λ��ʱ�� 
			StackPush(s, car); //���������복λ 
		 }
	  }
      else //��λ��������� 
	  {
		 printf("��λ��������󣬻�ó�λû�г���!\n");
	  }
   }
}
int main()
{
   SeqStack Park; //ͣ����ջ 
   CarChainQueue Aisle; //�������� 
   StackInit(&Park);
   ChainQueueInit(&Aisle);
   char choice;
   do{
       printf("\n\n");
       separator(10,' ',0);
       printf("ͣ��������\n");
       separator(30,'_',1);
       printf("1.��������\n");
       printf("2.�����뿪\n");
       printf("3.�鿴ͣ�������\n");        
       printf("0.�˳�ϵͳ\n");
       separator(56,'_',1);
       printf("��ʾ����ͣ������%d����λ����λͣ����ĳ�����ͣ���ڹ����ϡ�\n",MAXNUM);
       printf("��ͣ����ʱ�Ʒѣ��շѱ�׼:%.2fԪ/Сʱ,�����ϲ��շѡ�\n\n",PRICE);
       printf("\nѡ�����(0~3):");
       fflush(stdin);
       choice=getchar();
       switch (choice)
       {
       case '1': //�������� 
          InPark(&Park,&Aisle);
          break;
       case '2': //�����뿪 
          OutPark(&Park,&Aisle);
          break;
       case '3':
          ShowAll(&Park,&Aisle);
          break;
       }
   }while(choice!='0');
   return 0;
}
