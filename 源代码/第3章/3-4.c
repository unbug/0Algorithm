#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define N 7 
typedef enum { add, nul, sub, div1, yu, l, r }OP; 
int a[N][N] = { 
    { 0, 0, -1, -1, -1, 1, 2 }, 
    { 0, 0, -1, -1, -1, 1, 2 }, 
    { 1, 1, 0, 0, 0, 1, 2 }, 
    { 1, 1, 0, 0, 0, 1, 2 }, 
    { 1, 1, 0, 0, 0, 1, 2 }, 
}; 

int top; 
OP beg; 
int b[1024]; //栈 
OP op[1024]; 

void init_nu( ){
     top=0;
} 
void push_nu(int term ){ //将操作数入栈 
     b[top++]=term;
} 
int pop_nu(){
    return b[--top];
} 
int is_empty_nu( ){
    return top == 0;
} 
void destory_nu( ) {
     top = 0;
} 

void init_sign( ){
     beg = 0;
} 
void push_sign(OP sign ){
     op[beg++] = sign;
} 
void destory_sign( ){
     beg = 0;
} 
OP pop_sign( ){
    return op[--beg];
} 
OP get_sign( ){
    return op[beg - 1];
} 
int is_empty_sign( ){
    return beg == 0;
} 
int eval() 
{
    int i, j; 
    i = pop_nu(); 
    j = pop_nu(); 
    switch( pop_sign() ) 
    {
        case '+': push_nu( j + i ); break; 
        case '-': push_nu( j - i ); break; 
        case '*': push_nu( j * i ); break; 
        case '/': push_nu( j / i ); break; 
        case '%': push_nu( j & i ); break; 
        defult: break; 
    } 
} 
int change(char *s) 
{
    int i; 
    int n=strlen(s); //字符串长度 
    for(i=0;i<n;i++)
    {
         if(s[i]>='0' && s[i]<='9') //为数字 
             //push_nu(0); //操作数入栈 
             push_nu(s[i]-'0');
         while(s[i]>='0' && s[i]<='9') //若字符串继续为数字 
             push_nu(10*pop_nu()+s[i++]-'0' ); //取出原有数字，累加多位数 
         switch(s[i])//判断运算符 
         {
             case '+':
                  while(a[add][get_sign()]<=0)
                      eval();
                  push_sign( add );
                  break;
             case '-':
                  while( a[nul][get_sign()] <= 0 )
                      eval();
                  push_sign( nul );
                  break;
             case '*':
                  while( a[sub][get_sign()] <= 0 )
                      eval();
                  push_sign( sub );
                  break;
             case '/':
                  while( a[div1][get_sign()] <= 0 )
                      eval();
                  push_sign( div1 );
                  break;
             case '%':
                  while(a[yu][get_sign()] <= 0 )
                      eval();
                  push_sign( yu );
                  break;
             case '(':
                  push_sign( l );
                  break;
             case ')':
                  while( (get_sign()) != l )
                      eval();
                  pop_sign();
                  break;
             defult:
                 break;
         }
    }
    return pop_nu();
} 
int main( void ) 
{
    char *s = "((5-3)*2+4/2&2+1)";
    char str1[80];
    printf("输入表达式:");
    scanf("%s",str1); 
    init_nu();
    init_sign();
    printf( "%s=%d\n",str1,change(str1));
    destory_nu();
    destory_sign();
    getch();
    return 0; 
}
