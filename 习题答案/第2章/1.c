#define MAXSIZE 50
int SL[MAXSIZE];//SLһ�����飬����˳����е����� 

int count;    //����˳���������Ԫ�ص����� 

int SeqListInsert(int n,int data)
{
    int i;
    if(count>=MAXSIZE)   //˳����������ѳ���������� 
    {
        printf("˳������������ܲ�����!\n");
        return 0;             //����0��ʾ���벻�ɹ� 
    }
    if(n<1 || n>count)  //��������Ų���ȷ
    {
        printf("����Ԫ����Ŵ��󣬲��ܲ���Ԫ�أ�\n");
        return 0;              //����0����ʾ���벻�ɹ� 
    } 
    for(i=count;i>=n;i--)  //��˳����е���������ƶ� 
        SL[i+1]=SL[i]; 
    SL[n]=data;        //������ 
    count++;               //˳�������������1 
    return 1;                   //���سɹ�����  
}
