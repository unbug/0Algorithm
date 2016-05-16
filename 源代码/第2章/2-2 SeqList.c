void SeqListInit(SeqListType *SL) //初始化顺序表
{
    SL->ListLen=0;     //初始化时，设置顺序表长度为0 
} 
int SeqListLength(SeqListType *SL)  //返回顺序表的元素数量 
{
    return (SL->ListLen);    
}
int SeqListAdd(SeqListType *SL,DATA data)  //增加元素到顺序表尾部
{
    if(SL->ListLen>=MAXSIZE)  //顺序表已满 
    {
        printf("顺序表已满，不能再添加结点了！\n");
        return 0;    
    }
    SL->ListData[++SL->ListLen]=data;
    return 1;
} 
int SeqListInsert(SeqListType *SL,int n,DATA data)
{
    int i;
    if(SL->ListLen>=MAXSIZE)   //顺序表结点数量已超过最大数量 
    {
        printf("顺序表已满，不能插入结点!\n");
        return 0;             //返回0表示插入不成功 
    }
    if(n<1 || n>SL->ListLen-1)  //插入结点序号不正确
    {
        printf("插入元素序号错误，不能插入元素！\n");
        return 0;              //返回0，表示插入不成功 
    } 
    for(i=SL->ListLen;i>=n;i--)  //将顺序表中的数据向后移动 
        SL->ListData[i+1]=SL->ListData[i]; 
    SL->ListData[n]=data;        //插入结点 
    SL->ListLen++;               //顺序表结点数量增加1 
    return 1;                   //返回成功插入  
}
int SeqListDelete(SeqListType *SL,int n)  //删除顺序表中的数据元素 
{
    int i;
    if(n<1 || n>SL->ListLen+1)  //删除元素序号不正确
    {
        printf("删除结点序号错误，不能删除结点！\n");
        return 0;              //返回0，表示删除不成功 
    } 
    for(i=n;i<SL->ListLen;i++)  //将顺序表中的数据向前移动 
        SL->ListData[i]=SL->ListData[i+1]; 
    SL->ListLen--;               //顺序表元素数量减1 
    return 1;                   //返回成功删除  
}
DATA *SeqListFindByNum(SeqListType *SL,int n)  //根据序号返回数据元素
{
    if(n<1 || n>SL->ListLen+1)  //元素序号不正确
    {
        printf("结点序号错误，不能返回结点！\n");
        return NULL;              //返回0，表示不成功 
    } 
    return &(SL->ListData[n]);
} 
int SeqListFindByCont(SeqListType *SL,char *key)  //按关键字查询结点 
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
        if(strcmp(SL->ListData[i].key,key)==0)  //如果找到所需结点 
            return i;        //返回结点序号 
    return 0;  //遍历后仍没有找到，则返回0 
}
