#include <stdio.h>
int main()
{
    double rate[7];//����6��������ȡ������(���ڡ�3�¡����ꡢһ�ꡢ���ꡢ���ꡢ����) 
    double money,total,temp;//�ƻ�������
    int month,j; //�ƻ���Ǯ�������� 
    int y5,y3,y2,y1,y01,y02,y03;//�ֱ��ʾʹ�ò�ͬ����Ǯ�Ĵ���
    int timer[7];//���������Ĵ��� 
    /*
    printf("���ڵ�������:");
    scanf("%lf",&rate[0]);
    printf("������ȡ3���ڵ�������:");
    scanf("%lf",&rate[1]); 
    printf("������ȡ�����ڵ�������:");
    scanf("%lf",&rate[2]); 
    printf("������ȡ1���ڵ�������:");
    scanf("%lf",&rate[3]); 
    printf("������ȡ2���ڵ�������:");
    scanf("%lf",&rate[4]);                 
    printf("������ȡ3���ڵ�������:");
    scanf("%lf",&rate[5]); 
    printf("������ȡ5���ڵ�������:");
    scanf("%lf",&rate[6]);
    */
    rate[0]=0.36;
    rate[1]=1.71;
    rate[2]=1.98;
    rate[3]=2.25;
    rate[4]=2.79;
    rate[5]=3.33;
    rate[6]=3.6;
    printf("�������:");
    scanf("%lf",&money);
    printf("���������:");
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
                          y03=month-60*y5-36*y3-24*y2-12*y1-6*y01-3*y02;//ʣ������ �����ڼ�Ϣ 
                          if(y03<0) break; //������·ݳ���������������������ѭ�� 
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
                          y02++; //����һ��3���� 
                      }while(y02<=(month-y5*60-y3*36-y2*24-y1*12-y01*6)/3);
                      y01++;//����1�ΰ����� 
                  }while(y01<=(month-y5*60-y3*36-y2*24-y1*12));
                  y1++;//����1��1����                
                }while(y1<=(month-y5*60-y3*36-y2*24)/12);
                y2++;//����1��2���� 
            }while(y2<=(month-y5*60-y3*36)/24);
            y3++; //����1��3���� 
        }while(y3<=(month-y5*60)/36);
        y5++;                        //����1��5����
    }while(y5<=month/60);
    printf("�ܽ��:%.2lf������%d�£��ɰ����·�ʽ����ת�棬�����ϼ�:%.2lf\n",money,month,total);
    printf("5���ڴ�%d��\n",timer[6]);
    printf("3���ڴ�%d��\n",timer[5]); 
    printf("2���ڴ�%d��\n",timer[4]);
    printf("1���ڴ�%d��\n",timer[3]);
    printf("�����ڴ�%d��\n",timer[2]);
    printf("3���ڴ�%d��\n",timer[1]);
    printf("���ڴ�%d��\n",timer[0]);
    getch();
    return 0;               
}
