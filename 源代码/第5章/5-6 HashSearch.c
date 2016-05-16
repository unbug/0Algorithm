#include <stdio.h>
#define HASH_LEN 13
#define TABLE_LEN 8
int data[TABLE_LEN]={69,65,90,37,92,6,28,54}; //原始数据 
int hash[HASH_LEN]={0};//哈希表，初始化为0 
void InsertHash(int hash[],int m,int data) //将关键字data插入哈希表hash中 
{
    int i;
    i=data % 13;//计算哈希地址 
    while(hash[i]) //元素位置已被占用
        i=(++i) % m; //线性探测法解决冲突
    hash[i]=data;
}
void CreateHash(int hash[],int m,int data[],int n)
{
    int i;
    for(i=0;i<n;i++) //循环将原始数据保存到哈希表中 
        InsertHash(hash,m,data[i]); 
}
int HashSearch(int hash[],int m,int key)
{
    int i;
    i=key % 13;//计算哈希地址 
    while(hash[i] && hash[i]!=key) //判断是否冲突 
        i=(++i) % m; //线性探测法解决冲突
    if(hash[i]==0) //查找到开放单元，表示查找失败 
        return -1;//返回失败值 
    else//查找成功 
        return i;//返回对应元素的下标 
}
int main()
{
    int key,i,pos;
    CreateHash(hash,HASH_LEN,data,TABLE_LEN);//调用函数创建哈希表 
    printf("哈希表各元素的值:"); 
    for(i=0;i<HASH_LEN;i++)
        printf("%ld ",hash[i]);
    printf("\n");
    printf("输入查找关键字:");
    scanf("%ld",&key);
    pos=HashSearch(hash,HASH_LEN,key); //调用函数在哈希表中查找 
    if(pos>0)
        printf("查找成功,该关键字位于数组的第%d个位置。\n",pos);
    else
        printf("查找失败!\n");
    getch();
    return 0;
}
