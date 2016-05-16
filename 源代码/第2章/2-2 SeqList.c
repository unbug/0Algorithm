void SeqListInit(SeqListType *SL) //��ʼ��˳���
{
    SL->ListLen=0;     //��ʼ��ʱ������˳�����Ϊ0 
} 
int SeqListLength(SeqListType *SL)  //����˳����Ԫ������ 
{
    return (SL->ListLen);    
}
int SeqListAdd(SeqListType *SL,DATA data)  //����Ԫ�ص�˳���β��
{
    if(SL->ListLen>=MAXSIZE)  //˳������� 
    {
        printf("˳�����������������ӽ���ˣ�\n");
        return 0;    
    }
    SL->ListData[++SL->ListLen]=data;
    return 1;
} 
int SeqListInsert(SeqListType *SL,int n,DATA data)
{
    int i;
    if(SL->ListLen>=MAXSIZE)   //˳����������ѳ���������� 
    {
        printf("˳������������ܲ�����!\n");
        return 0;             //����0��ʾ���벻�ɹ� 
    }
    if(n<1 || n>SL->ListLen-1)  //��������Ų���ȷ
    {
        printf("����Ԫ����Ŵ��󣬲��ܲ���Ԫ�أ�\n");
        return 0;              //����0����ʾ���벻�ɹ� 
    } 
    for(i=SL->ListLen;i>=n;i--)  //��˳����е���������ƶ� 
        SL->ListData[i+1]=SL->ListData[i]; 
    SL->ListData[n]=data;        //������ 
    SL->ListLen++;               //˳�������������1 
    return 1;                   //���سɹ�����  
}
int SeqListDelete(SeqListType *SL,int n)  //ɾ��˳����е�����Ԫ�� 
{
    int i;
    if(n<1 || n>SL->ListLen+1)  //ɾ��Ԫ����Ų���ȷ
    {
        printf("ɾ�������Ŵ��󣬲���ɾ����㣡\n");
        return 0;              //����0����ʾɾ�����ɹ� 
    } 
    for(i=n;i<SL->ListLen;i++)  //��˳����е�������ǰ�ƶ� 
        SL->ListData[i]=SL->ListData[i+1]; 
    SL->ListLen--;               //˳���Ԫ��������1 
    return 1;                   //���سɹ�ɾ��  
}
DATA *SeqListFindByNum(SeqListType *SL,int n)  //������ŷ�������Ԫ��
{
    if(n<1 || n>SL->ListLen+1)  //Ԫ����Ų���ȷ
    {
        printf("�����Ŵ��󣬲��ܷ��ؽ�㣡\n");
        return NULL;              //����0����ʾ���ɹ� 
    } 
    return &(SL->ListData[n]);
} 
int SeqListFindByCont(SeqListType *SL,char *key)  //���ؼ��ֲ�ѯ��� 
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
        if(strcmp(SL->ListData[i].key,key)==0)  //����ҵ������� 
            return i;        //���ؽ����� 
    return 0;  //��������û���ҵ����򷵻�0 
}
