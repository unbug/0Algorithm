#include <stdio.h>
int main()
{
    int chook,rabbit,head,foot;
    printf("����ͷ���ͽ���:");
    scanf("%d%d",&head,&foot);
    for(chook=0;chook<=head;chook++)
    {
        rabbit=head-chook;
        if(chook*2+rabbit*4==foot)
        {
            printf("����:%dֻ,������:%dֻ��",chook,rabbit);            
        }            
    }
    getch();
    return 0;
}
