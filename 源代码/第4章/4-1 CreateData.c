#include <stdlib.h>
int CreateData(int arr[],int n,int min,int max) //����һ��������飬a�������ɵ����ݣ�nΪ����Ԫ�ص����� 
{
    int i,j,flag;
    srand(time(NULL));
    if((max-min+1)<n) return 0; //���������С��֮��С�ڲ���������������������ݲ��ɹ� 
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
