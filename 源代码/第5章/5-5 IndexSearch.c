#include <stdio.h>
#define INDEXTABLE_LEN 3
#define TABLE_LEN 30
typedef struct item
{
    int index;    //索引值 
    int start;    //开始位置 
    int length;   //子表长度 
}INDEXITEM;
//定义主表数据 
long stu[TABLE_LEN]={
     1080101,1080102,1080103,1080104,1080105,1080106,0,0,0,0,
     1080201,1080202,1080203,1080204,0,0,0,0,0,0,
     1080301,1080302,1080303,1080304,0,0,0,0,0,0};
//定义索引表 
INDEXITEM indextable[INDEXTABLE_LEN]={
    {10801,0,6},
    {10802,10,4},
    {10803,20,4}};
int IndexSearch(int key) //按索引查找 
{
    int i,index1,start,length;
    index1=key/100;//计算索引值
    for(i=0;i<INDEXTABLE_LEN;i++) //在索引表中查找索引值 
    {
        if(indextable[i].index==index1) //找到索引值 
        {
            start=indextable[i].start; //获取数组开始序号 
            length=indextable[i].length; //获取元素长度 
            break; //跳出循环 
        }
    }
    if(i>=INDEXTABLE_LEN)
        return -1;//索引表中查找失败 
    for(i=start;i<start+length;i++)
    {
        if(stu[i]==key) //找到关键字 
            return i; //返回序号 
    }
    return -1; //查找失败，返回-1 
}
int InsertNode(key)
{
    int i,index1,start,length;
    index1=key/100;//计算索引值
    for(i=0;i<INDEXTABLE_LEN;i++) //在索引表中查找索引值 
    {
        if(indextable[i].index==index1) //找到索引值 
        {
            start=indextable[i].start; //获取数组开始序号 
            length=indextable[i].length; //获取元素长度 
            break; //跳出循环 
        }
    }
    for(i=0;i<INDEXTABLE_LEN;i++) //在索引表中查找索引值 
    {
        if(indextable[i].index==index1) //找到索引值 
        {
            start=indextable[i].start; //获取数组开始序号 
            length=indextable[i].length; //获取元素长度 
            break; //跳出循环 
        }
    }
    if(i>=INDEXTABLE_LEN)
        return -1;//索引表中查找失败     
    stu[start+length]=key;//保存关键字到主表 
    indextable[i].length++;//修改索引表中的子表长度
    return 0;    
}

int main()
{
    long key;
    int i,pos;
    printf("原数据:"); 
    for(i=0;i<TABLE_LEN;i++)
        printf("%ld ",stu[i]);
    printf("\n");
    printf("输入查找关键字:");
    scanf("%ld",&key);
    pos=IndexSearch(key);
    if(pos>0)
        printf("查找成功,该关键字位于数组的第%d个位置。\n",pos);
    else
        printf("查找失败!\n");
    printf("输入插入关键字:");
    scanf("%ld",&key);
    if(InsertNode(key)==-1)
        printf("插入数据失败!\n");
    else
    {
        for(i=0;i<TABLE_LEN;i++)
            printf("%ld ",stu[i]);
        printf("\n");
    }    
    getch();
    return 0;
}
