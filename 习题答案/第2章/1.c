#define MAXSIZE 50
int SL[MAXSIZE];//SL一个数组，保存顺序表中的数据 

int count;    //保存顺序表中已有元素的数量 

int SeqListInsert(int n,int data)
{
    int i;
    if(count>=MAXSIZE)   //顺序表结点数量已超过最大数量 
    {
        printf("顺序表已满，不能插入结点!\n");
        return 0;             //返回0表示插入不成功 
    }
    if(n<1 || n>count)  //插入结点序号不正确
    {
        printf("插入元素序号错误，不能插入元素！\n");
        return 0;              //返回0，表示插入不成功 
    } 
    for(i=count;i>=n;i--)  //将顺序表中的数据向后移动 
        SL[i+1]=SL[i]; 
    SL[n]=data;        //插入结点 
    count++;               //顺序表结点数量增加1 
    return 1;                   //返回成功插入  
}
