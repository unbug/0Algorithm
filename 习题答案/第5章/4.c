#include <stdio.h>
#define HASH_LEN 18
#define TABLE_LEN 15

int data[TABLE_LEN]={75, 85, 7, 13, 9, 10, 19,91, 21, 37, 56, 64, 80, 33, 88}; //原始数据 
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
    int i;
    CreateHash(hash,HASH_LEN,data,TABLE_LEN);//调用函数创建哈希表 
    printf("哈希表各元素的值:"); 
    for(i=0;i<HASH_LEN;i++)
        printf("%ld ",hash[i]);

    getch();
    return 0;
}