#include <stdio.h>
int main()
{
    double rate[7];//保存6种整存整取的利率(活期、3月、半年、一年、二年、三年、五年) 
    double money,total,temp;//计划存入金额
    int month,j; //计划存钱的总月数 
    int y5,y3,y2,y1,y01,y02,y03;//分别表示使用不同档存钱的次数
    int timer[7];//保存各档存的次数 
    /*
    printf("活期的年利率:");
    scanf("%lf",&rate[0]);
    printf("整存整取3月期的年利率:");
    scanf("%lf",&rate[1]); 
    printf("整存整取半年期的年利率:");
    scanf("%lf",&rate[2]); 
    printf("整存整取1年期的年利率:");
    scanf("%lf",&rate[3]); 
    printf("整存整取2年期的年利率:");
    scanf("%lf",&rate[4]);                 
    printf("整存整取3年期的年利率:");
    scanf("%lf",&rate[5]); 
    printf("整存整取5年期的年利率:");
    scanf("%lf",&rate[6]);
    */
    rate[0]=0.36;
    rate[1]=1.71;
    rate[2]=1.98;
    rate[3]=2.25;
    rate[4]=2.79;
    rate[5]=3.33;
    rate[6]=3.6;
    printf("存款总数:");
    scanf("%lf",&money);
    printf("存款总月数:");
    scanf("%d",&month);     
    for(j=0;j<=6;j++)
        rate[j]=rate[j]/12/100; 
    total=money;
    y5=0;
    do{
        y3=0;
        do{
            y2=0;
            do{
                y1=0;
                do{
                  y01=0;
                  do{
                      y02=0;
                      do{
                          y03=month-60*y5-36*y3-24*y2-12*y1-6*y01-3*y02;//剩余月数 按活期计息 
                          if(y03<0) break; //若存款月份超过总月数，则跳出本层循环 
                          temp=money*pow(1+rate[1]*3,(double)y02)
                                     *pow(1+rate[2]*6,(double)y01)
                                     *pow(1+rate[3]*12,(double)y1)
                                     *pow(1+rate[4]*12*2,(double)y2)
                                     *pow(1+rate[5]*12*3,(double)y3)
                                     *pow(1+rate[6]*12*5,(double)y5)
                                     *pow(1+rate[0],(double)y03);
                          if(temp>total)
                          {
                              total=temp;
                              timer[0]=y03;
                              timer[1]=y02;
                              timer[2]=y01;
                              timer[3]=y1;
                              timer[4]=y2;
                              timer[5]=y3;
                              timer[6]=y5;                              
                          }
                          y02++; //增加一次3月期 
                      }while(y02<=(month-y5*60-y3*36-y2*24-y1*12-y01*6)/3);
                      y01++;//增加1次半年期 
                  }while(y01<=(month-y5*60-y3*36-y2*24-y1*12));
                  y1++;//增加1次1年期                
                }while(y1<=(month-y5*60-y3*36-y2*24)/12);
                y2++;//增加1次2年期 
            }while(y2<=(month-y5*60-y3*36)/24);
            y3++; //增加1次3年期 
        }while(y3<=(month-y5*60)/36);
        y5++;                        //增加1次5年期
    }while(y5<=month/60);
    printf("总金额:%.2lf，共存%d月，可按以下方式进行转存，本利合计:%.2lf\n",money,month,total);
    printf("5年期存%d次\n",timer[6]);
    printf("3年期存%d次\n",timer[5]); 
    printf("2年期存%d次\n",timer[4]);
    printf("1年期存%d次\n",timer[3]);
    printf("半年期存%d次\n",timer[2]);
    printf("3月期存%d次\n",timer[1]);
    printf("活期存%d次\n",timer[0]);
    getch();
    return 0;               
}
