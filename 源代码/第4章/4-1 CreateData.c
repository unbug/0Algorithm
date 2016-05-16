#include <stdlib.h>
int CreateData(int arr[],int n,int min,int max) //创建一个随机数组，a保存生成的数据，n为数组元素的数量 
{
    int i,j,flag;
    srand(time(NULL));
    if((max-min+1)<n) return 0; //最大数与最小数之差小于产生数组的数量，生成数据不成功 
    for(i=0;i<n;i++)
    {
        do
        {
            arr[i]=(max-min+1)*rand()/(RAND_MAX+1)+min;
            flag=0;
            for(j=0;j<i;j++)
            {
                if(arr[i]==arr[j])
                    flag=1;
            }
        }while(flag);        
    }
    return 1;
}
