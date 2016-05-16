#include <stdio.h>
int main()
{
    int chook,rabbit,head,foot;
    printf("输入头数和脚数:");
    scanf("%d%d",&head,&foot);
    for(chook=0;chook<=head;chook++)
    {
        rabbit=head-chook;
        if(chook*2+rabbit*4==foot)
        {
            printf("鸡有:%d只,兔子有:%d只。",chook,rabbit);            
        }            
    }
    getch();
    return 0;
}
