#include<stdio.h>
#include<malloc.h>
#define MAXBIT 4 //ÿ���ֱ�������λ�� 
int maxnumber; //ȫ�ֲ���
typedef struct node
{
    int data;
    struct node *next;
}BIGINT,*pBIGINT;   //��������ṹ
pBIGINT BigIntInput() //���������
{
	int i,j,k;
	long sum;
	char c;
    pBIGINT node,ps,qs;
	struct number    //������ʱ�м�ṹ
	{
		int num;
		struct number *np;
	}*p,*q;
	p=NULL;     //����Ϊ��λ����βΪ��λ
	while((c=getchar())!='\n')  //���ַ���������
	{
		if(c>='0' && c<='9')      //��Ϊ���־ʹ���
		{
			if(!(q=(struct number *)malloc(sizeof(struct number))))
			{
                printf("�ڴ����ʧ��!\n");
                getch();
                exit(0); 
            }
			q->num=c-'0';       //����һλ����
			q->np=p; //�������� 
			p=q;
		}
    }
	if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//�����ͷ�ڴ�
	{
        printf("�ڴ����ʧ��!\n");getch();
        exit(0); 
    }	
	node->data=-1; //��ͷ
	ps=node;
	while(p!=NULL) //���������λ����������Ϊ��
	{
		sum=0;
        i=0;
        k=1;
		while(i<MAXBIT  && p!=NULL) //��MAXBIT λ�ϲ�λ����
		{
			sum=sum+k*(p->num); //�ɵ�λ��ʼ�ۼ����� 
			i++; //λ����1 
            p=p->np; //������һλ���� 
            k=k*10; //ϵ�� 
		}
		if(!(qs=(pBIGINT)malloc(sizeof(BIGINT))))//���䱣��ڵ���ڴ� 
		{
            printf("�ڴ����ʧ��!\n");getch();
            exit(0); 
        }
		qs->data=sum; //����ϵ����ݱ��浽�ڵ� 
		ps->next=qs; //���ڵ�������� 
		ps=qs;
	}
	ps->next=node;    //�������
	return(node);
}
void BigIntPrint(pBIGINT result) //��������� 
{
	if(result->next->data!=-1) //����һ�ڵ㲻�������β��(ͨ���ݹ��ҵ�����Ľ�β )
	{
		BigIntPrint(result->next); //�ݹ����������� 
		if(result->next->next->data==-1) //����һ�ڵ������һ�ڵ�������β 
			printf("%d",result->next->data); //�����һ�ڵ������ 
		else{
			int i,k=maxnumber;
			for(i=1;i<=MAXBIT ;i++,k/=10) //�м䲿�ֵ����ݲ���MAXBIT λ����ǰ�����0 
				putchar('0'+result->next->data%(k)/(k/10));
		}
	}
}
pBIGINT BigIntInsert(pBIGINT num1,int num)//��num1�ڵ�֮�����һ���µĽڵ㣬�ڵ��б���ֵNUM
{
    pBIGINT node;
    if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//�����ڴ�
    {
        printf("�ڴ����ʧ��!\n");getch();
        exit(0); 
    }
    node->data=num;      //��ֵ
    num1->next=node;        //���µĽڵ��������num1�ĺ���
    return(node);
}
pBIGINT BigIntAdd(pBIGINT num1,pBIGINT num2)   //��ɼӷ�����
{
	pBIGINT num11,num21,node,temp,temp1;
	int total,number,carry;
	num11=num1->next; //����������ĵ�1��λ�� 
    num21=num2->next; //��������ĵ�1��λ�� 
	if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//������ź͵������ͷ
	{
        printf("�ڴ����ʧ��!\n");getch();
        exit(0); 
    }
	node->data=-1; //��ͷ���ݲ��ִ��-1 
	temp=node; //ʹtempָ���ź͵����� 
	carry=0; //��λ����
	while(num11->data!=-1 && num21->data!=-1)//�����Ǳ�ͷ
	{
		total=num11->data + num21->data + carry;//��Ӧλ���ϴν�λ�����
		number=total % maxnumber;      //��¼���Դ����������
		carry=total / maxnumber;       //����maxnumber������Ϊ��λ��
		temp=BigIntInsert(temp,number);    //�ѿɴ��������������
		num11=num11->next;      //ȡ�����ĺ��沿�����
		num21=num21->next;
    }
	temp1=(num11->data!=-1)?num11:num21;//������С��һȡ��δ�����ָ��
	while(temp->data!=-1)     //�ж���һ���Ƿ�ͷ
	{
		total=temp1->data+carry;//���λ�����
		number=total%maxnumber;   //��¼�ɴ������
		carry=total/maxnumber;    //��¼��λ��
		temp=BigIntInsert(temp,number); //��������
		temp1=temp1->next;
	}
	if(carry)     //������н�λ��
		temp=BigIntInsert(temp,1);//�����λ 
	temp->next=node;   //�������
	return(node);   //������ͽ��������ָ��
}
pBIGINT BigIntSub(pBIGINT num1,pBIGINT num2)   //��ɼ�������
{
	pBIGINT num11,num21,node,temp;
	int diff,number,borrow;
	num11=num1->next; //����������ĵ�1��λ�� 
    num21=num2->next; //��������ĵ�1��λ�� 
	if(!(node=(pBIGINT)malloc(sizeof(BIGINT))))//������Ų�������ͷ
	{
        printf("�ڴ����ʧ��!\n");getch();
        exit(0); 
    }
	node->data=-1; //��ͷ���ݲ��ִ��-1 
	temp=node; //ʹtempָ���Ų������ 
	borrow=0; //��λ����
	while(num11->data!=-1)//����������δ����ͷ
	{
		if(num21->data!=-1) //��������δ����ͷ
        { 
            diff=num11->data - num21->data - borrow;//��ȥ��Ӧλ���ϴεĽ�λ��
            if(diff<0) //���Ϊ��������Ҫ��λ 
    		{
    		    diff=maxnumber+diff; //��λ�õ����� 
    		    borrow=1; //���ý�λ��־
            }else
                borrow=0; //�����λ��־ 
            num21=num21->next;//������һ������            
        }
        else
        {
            diff=num11->data - borrow;//��ȥ��λ
            borrow=0; 
        }
		temp=BigIntInsert(temp,diff);    //�ѿɴ��������������
		num11=num11->next;      //ȡ�����ĺ��沿����� 
    }
	while(num21->data!=-1)     //����������δ����ͷ
	{
		diff=num21->data - borrow;//���λ�����
        if(diff<0) //���Ϊ��������Ҫ��λ 
		{
		    diff=maxnumber+diff; //��λ�õ����� 
		    borrow=1; //���ý�λ��־
        }else
            borrow=0; //�����λ��־
        temp=BigIntInsert(temp,diff);    //�ѿɴ��������������   
		num21=num21->next;
	}
	temp->next=node;   //�������
	return(node);   //���������������ָ��
}

int main()
{
	pBIGINT num1,num2,result;
	int i;
	char op;
	maxnumber=1;
	for(i=0;i<MAXBIT;i++) //�������������������������Ҫʹ�� 
        maxnumber=maxnumber*10;
   printf("ѡ�������������(+��-):");  
   scanf("%c", &op);
   fflush(stdin);
   switch (op)
   {
   case '+':
	  printf("\n���뱻����:");
	  num1=BigIntInput();
	  printf("\n�������:");
	  num2=BigIntInput();
	  result=BigIntAdd(num1, num2);	//�ӷ� 
	  break;
   case '-':
	  printf("\n���뱻����:");
	  num1=BigIntInput();
	  printf("\n�������:");
	  num2=BigIntInput();
	  result=BigIntSub(num1,num2);;	//���� 
	  break;
   default:
      printf("������������!\n");
      break; 
   }
   if (op == '+' || op == '-')
   {
	  printf("\n���:");
	  BigIntPrint(result);
      printf("\n");
   }
   getch();
   getch();
   return 0;
}
