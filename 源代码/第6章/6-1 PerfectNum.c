/*求10000以内的完数*/
#include <stdio.h>
int main()
{
    long p[300]; //保存分解的因子 
    long i,num,count,s,c=0;
    for(num=2;num<=2000000;num++)
    {
        count=0;
        s=num;
        for(i=1;i<num/2+1;i++) //循环处理每1个数 
        {
            if(num % i==0) //能被i整除*/
            {
                p[count++]=i; //保存因子，计数器count增加1                
                s-=i; //减去一个因子*/ 
             }
        }
        if(s==0) //已被分解完成，则输出*/ 
        {
            printf("%4ld是一个完数,因子是",num);
            printf("%ld=%ld",num,p[0]); //输出完数 */
            for(i=1;i<count;i++) //输出因子 */
                printf("+%ld",p[i]);
            printf("\n");
            c++;
        }
    }
    printf("\n共找到%d个完数。\n",c);
    getch();
    return 0; 
}
