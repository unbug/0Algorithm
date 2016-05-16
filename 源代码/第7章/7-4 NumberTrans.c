#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE  100
#define SIZE_INCREMENT  5
typedef struct //ջ�ṹ 
{
    int *base; //ջ�� 
    int *top; //ջ�� 
    int stacksize; //ջ��С 
}SqStack,*SQSTACK;
int StackInit(SQSTACK s) //��ʼ��ջ 
{
    s->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!(s->base))
        exit(0);
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
    return 1;
}
int PUSH(SQSTACK s,int e) //��ջ 
{
    if(s->base+s->stacksize==s->top)
    {
        s->base=(int *)realloc(s->base,(SIZE_INCREMENT+s->stacksize)*sizeof(int));
        s->top=s->base+s->stacksize;
        s->stacksize+=SIZE_INCREMENT;
    }
    *(s->top)=e;
     s->top+=1;
     return 1;
}
int POP(SQSTACK s,int *p) //��ջ 
{
    if(s->base==s->top) //��ջ 
        return 0;
     *p=*(s->top-1);
     s->top--;
     return 1;
}
int StackLength(SQSTACK s) //ջ�ĳ���(Ԫ������) 
{
    return (s->top-s->base);
}
int StackFree(SQSTACK s) //�ͷ�ջ 
{
    free(s->base);
    s->top=s->base=NULL;
    return 1;
}
char *DecToOther(unsigned long num,int sys) //10����ת��Ϊ�������ƣ�����һ���ַ��� 
{//num��ת��������,sysΪ��ת���Ľ��� 
    SqStack s;
    int rem,i,length,num1,inc=1;
    char *out,*p; //��������ַ��� 
    if(!StackInit(&s)) //��ʼ��ջʧ�� 
        exit(0);//�˳�
    do{
        if(num<sys) //������С�ڽ��� 
        {
            rem=num;
            PUSH(&s,rem); //���ӽ���������ջ 
            break;//�˳�ѭ�� 
        }
        else
        {
            rem=num % sys; //��������ȡ���� 
            PUSH(&s,rem); //��������ջ 
            num=(num-rem)/sys; //��
        }
    }while(num); //dividend��Ϊ0
    if(sys==16) //16�����������ַ���ǰ׺ 
        inc++;
    length=StackLength(&s); //��ȡջ�ĳ���(�����Ԫ�صĸ���) 
    if(!(out=(char *)malloc(sizeof(char)*(length+inc))))//�������ڴ�ʧ��
    {
        printf("�ڴ����ʧ��!\n");
        exit(0);
    } 
    p=out; //ָ��pָ������ڴ��׵�ַ 
    *p++='0';//���ǰ׺    
    if(sys==16) //16���Ƶ�ǰ׺ 
        *p++='x';
    for(i=1;i<=length;i++)
    {
        POP(&s,&num1); //��ջ�е���һ���� 
        if(num1<10) //��С��10
            *p++=num1+'0'; //�������ֵ�ASCII�ַ� 
        else //����10�����A~F 
            *p++=num1+'A'-10;//���A~F֮�����ĸ 
    }
    StackFree(&s); //�ͷ�ջ��ռ�ÿռ� 
    *p='\0';
    return (out);//�����ַ��� 
}
int OtherToDec(int sys,char *in_str) //��������ת��Ϊ10����(������)
{ //sys����,arrat_char�账����ַ��� 
    int i,j,length,start=0;
    unsigned long sum=0,pow;
    int *in_bit;
       
    length=strlen(in_str); //�ַ����ĳ��� 
    if(!(in_bit=(int *)malloc(sizeof(int)*length)))
    {
        printf("�ڴ����ʧ��!\n");
        exit(0); 
    }
    if(in_str[0]=='-') //Ϊ�������������� 
        start++;
    j=0;
    for(i=length-1;i>=start;i--)
    {
        if(in_str[i]>='0' && in_str[i]<='9') //Ϊ����0~9 
            in_bit[j]=in_str[i]-'0'; //���ַ�ת��Ϊ���� 
        else if(in_str[i]>='A' && in_str[i]<='F') //��д��ĸ A~F
            in_bit[j]=in_str[i]-'A'+10;
        else if(in_str[i]>='a' && in_str[i]<='f') //Сд��ĸ a~f
            in_bit[j]=in_str[i]-'a'+10;
        else
            exit(0);
        j++;
    }
    length-=start; 
    for(i=0;i<length;i++)
    {
        if(in_bit[i]>=sys) //��ĳ���������˽��� 
        {
            printf("��������ݲ�����%d�������ݵĹ���!",sys); //��ʾ���� 
            exit(0);
        }
        for(j=1,pow=1;j<=i;j++)
            pow*=sys;
        sum+=in_bit[i]*pow;
    }
    return sum;
}

int main()
{
    int old,new1;
    char select='N',*other,str[80]; //����
    unsigned long num10; //����10������ 
    char array[32];
    do{
        printf("\nԭ���ݽ���:");
        scanf("%d",&old);
        printf("����%d������:",old);
        scanf("%s",str); //�����ַ��� 
        num10=OtherToDec(old,str); //����������ת��Ϊ10���� 
        printf("��ת���Ľ���:");
        scanf("%d",&new1);
        if(10==new1) //����ת��Ϊ10���� 
        {
            printf("\n��%d������%s\nת��Ϊ10������:%d\n",old,str,num10); 
        }
        else
        {
            other=DecToOther(num10,new1);
            printf("��%d������%s\nת��Ϊ%d������:%s\n",old,str,new1,other);
        }
        printf("\n����(Y/N)?");
        select=getch();
    }while(select=='y' || select =='Y');
    getch();
    return 0;
}
