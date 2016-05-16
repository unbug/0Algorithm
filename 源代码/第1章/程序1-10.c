#include <stdio.h>
void main()
{
    int i[7],j;
    for(i[0]=1;i[0]<=29;i[0]++)
        for(i[1]=1;i[1]<=29;i[1]++)
        {
            if(i[0]==i[1]) continue;
            for(i[2]=1;i[2]<=29;i[2]++)
            {
                if(i[0]==i[2] || i[1]==i[2]) continue;
                    for(i[3]=1;i[3]<=29;i[3]++)
                    {
                        if(i[0]==i[3] || i[1]==i[3] || 
                            i[2]==i[3]) continue;
                        for(i[4]=1;i[4]<=29;i[4]++)
                        {
                            if(i[0]==i[4] || i[1]==i[4] || 
                                i[2]==i[4] || i[3]==i[4]) continue;
                            for(i[5]=1;i[5]<=29;i[5]++)
                            {
                                if(i[0]==i[5] || i[1]==i[5]  || 
                                    i[2]==i[5] || i[3]==i[5] || 
                                    i[4]==i[5]) continue;
                                for(i[6]=1;i[6]<=29;i[6]++)
                                {
                                    if(i[0]==i[6] || i[1]==i[6]  || 
                                        i[2]==i[6] || i[3]==i[6] || 
                                        i[4]==i[6] || i[5]==i[6]) continue;
                                    for(j=0;j<7;j++)
                                        printf("%3d",i[j]);
                                    printf("\n");
                                    getch();
                                }
                            }                        
                        }                                        
                    }                
                }
        }         
}
