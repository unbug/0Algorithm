#include <stdio.h>
int main()
{
    int chook,rabbit,head,foot;
    printf("����ͷ���ͽ���:");
    scanf("%d%d",&head,&foot);
    rabbit=(foot-2*head)/2; //���ܽ���foot��ȥ������2*head
    chook=head-rabbit;  //����ͷ����ȥ��������ʣ��ľ��Ǽ���
    printf("����:%dֻ,������:%dֻ��",chook,rabbit);
    getch();
    return 0;
}
