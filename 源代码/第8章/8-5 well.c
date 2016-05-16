#include <stdio.h>
int main()
{
    int len1,len2,len3,len4,len5,len,flag;
    flag=1; //循环标志变量 
    len5=0;
    while(flag)
    {
        len5+=4; //len5为4的倍数
        len1=0;
        while(flag)
        {
            len1+=5;//len1为5的倍数 
            len4=len5+len1/5;//丁家井绳长度 
            len3=len4+len5/4;//丙家井绳长度 
            if(len3%2) //若不能被2整除 
                continue; 
            if(len4%3)  //若不能被3整除 
                continue;
            len2=len3+len4/3;
            if(len2+len3/2<len1) //不符合条件 
                break;
            if(len2+len3/2==len1) //符合条件 
                flag=0;
        }
    }
    len=2*len1+len2; //求进深 
    printf("各家井绳长度分别为:\n");
    printf("甲:%d\n",len1);
    printf("乙:%d\n",len2);
    printf("丙:%d\n",len3);
    printf("丁:%d\n",len4);
    printf("戌:%d\n",len5);
    printf("井深:%d\n",len);
    getch();
    return 0;
}
