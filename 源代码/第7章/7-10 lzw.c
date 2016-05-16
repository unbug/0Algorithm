#include <stdlib.h>
#include <stdio.h>
#define BITS 12 //每个数据项的二进制位数 
#define HASHING_SHIFT BITS-8 //HASH表的移位数 
#define MAX_VALUE (1<<BITS)-1
#define MAX_CODE MAX_VALUE-1 //最大标号 
#define TABLE_SIZE 4099 //HASH表的长度 
typedef struct{
    int *code;    //代码
    unsigned int *prefix; //前缀
    unsigned char *suffix; //后缀
}LZW_DATA;
unsigned char decode_stack[TABLE_SIZE]; //用于保存解压缩后的数据
LZW_DATA lzw1,*lzw;

void compress(FILE *input,FILE *output); //压缩函数 
void expand(FILE *input,FILE *output); //解压函数 
unsigned int hashsearch(int hash_prefix,unsigned int hash_character); //HASH表搜索函数 
char *decode(unsigned char *buffer,unsigned int code);
unsigned int incode(FILE *input);
void outcode(FILE *output,unsigned int code);

void compress(FILE *input,FILE *output) //压缩函数 
{
    unsigned int curr_code;
    unsigned int suffix;   //后缀字符 
    unsigned int prefix;   //前缀字符 
    unsigned int index;
    int i;

    if(!(lzw1.code=malloc(TABLE_SIZE*sizeof(unsigned int)))) //代码值数组 
    {
        printf("内存分配失败!\n");
        exit(0); 
    }
    if(!(lzw1.prefix=malloc(TABLE_SIZE*sizeof(unsigned int))))//压缩前数据 
    {
        printf("内存分配失败!\n");
        exit(0); 
    }    
    if(!(lzw1.suffix=malloc(TABLE_SIZE*sizeof(unsigned char))))//压缩后数据 
    {
        printf("内存分配失败!\n");
        exit(0); 
    }    
    lzw=&lzw1;
    curr_code=258; //编译表中的字符串编号从258开始 
    for(i=0;i<TABLE_SIZE;i++) //初始化标号数组 
        lzw->code[i]=-1;
    i=0;
    printf("\n开始压缩.");
    prefix=getc(input); //从文件读取一个字节 
    while((suffix=getc(input))!= (unsigned)EOF) //循环处理输入文件中的内容 
    {
        if (++i==1000) //处理1000个字节显示一个小数点，表示系统正在处理 
        {
            i=0;
            printf(".");
        }
        index=hashsearch(prefix,suffix); //在HASH表中查找并返回索引号 
        if (lzw->code[index]!=-1)//若该标号存在 
            prefix=lzw->code[index];//使用该标号作为前缀 
        else{                                            //若标号不存在 
            if (curr_code<=(MAX_CODE)){ //标号未超过最大标号 
                lzw->code[index]=curr_code++; //增加一个标号 
                lzw->prefix[index]=prefix;  //保存前缀 
                lzw->suffix[index]=suffix; //保存后缀 
            }
            outcode(output,prefix); //输出前缀字节的内容 
            prefix=suffix;//将后缀作前缀，准备下次循环 
        }
    }
    outcode(output,prefix); //输出前缀 
    outcode(output,(MAX_VALUE)); //输出结束标志 
    outcode(output,0);   

    free(lzw->code); //释放分配的内存 
    free(lzw->prefix);
    free(lzw->suffix);
}

unsigned int hashsearch(int prefix,unsigned int suffix)//HASH表搜索函数 
{
    int index;
    int offset;
    index=(suffix << HASHING_SHIFT)^prefix; //构造HASH地址 
    if(index == 0) 
        offset=1;
    else
        offset=TABLE_SIZE-index;
    while(1)
    {
        if(lzw->code[index]==-1) //找到一个空表项 
            return(index); //返回HASH地址 
        if (lzw->prefix[index]==prefix && lzw->suffix[index]==suffix) //找到目标数据 
            return(index); //返回HASH地址 
        index-=offset; //处理冲突，调整HASH地址 
        if(index<0) index+=TABLE_SIZE; //调整HASH地址 
    }
}

void outcode(FILE *output,unsigned int code) //输出压缩后的字节内容 
{
    static int ob=0; //静态变量，保存已输出数据的二进制位数 
    static unsigned long obb=0L;//静态变量，保存需输出数据的二进制位数 
    obb |= (unsigned long) code << (32-BITS-ob); //进行移位合并 
    ob+=BITS; //增加需输出数据的二进制位 
    while (ob>=8)  //达到一个字节，则输出 
    {
        putc(obb>>24,output); //右移24位，使低字节8位为需要输出的数据 
        obb<<= 8;  //左移8位，去掉已输入的一个字节数据 
        ob-=8;    //减去已输出的8位，保留剩余的未输出的位数 
    }
    return;
}
void expand(FILE *input,FILE *output) //解压缩函数 
{        
    unsigned int curr_code;
    unsigned int suffix;
    unsigned int prefix;
    int ch;
    int i;
    unsigned char *ps;
    char *decode(unsigned char *buffer,unsigned int code);
    
    if(!(lzw1.code=malloc(TABLE_SIZE*sizeof(unsigned int)))) //代码值数组 
    {
        printf("内存分配失败!\n");
        exit(0); 
    }
    if(!(lzw1.prefix=malloc(TABLE_SIZE*sizeof(unsigned int))))//压缩前数据 
    {
        printf("内存分配失败!\n");
        exit(0);                                                       
    }
    if(!(lzw1.suffix=malloc(TABLE_SIZE*sizeof(unsigned char))))//压缩后数据 
    {
        printf("内存分配失败!\n");
        exit(0);                                                   
    }
    lzw=&lzw1;
    curr_code=258; //定义标号从258开始 
    i=0;
    printf("\n解压缩.");
    prefix=incode(input);  //读入第一个编码，并初始化字符变量 
    ch=prefix; //保存前缀到字符变量 
    putc(prefix,output);      // 输出字符到输出文件上
    while ((suffix=incode(input))!=(MAX_VALUE)) //循环进行解压缩 
    {
        if (++i==1000)    //处理1000个字节就显示一个点 
        {
            i=0;
            printf(".");
        }
        if (suffix>=curr_code)//后缀是未定义的标号 
        {
            *decode_stack=ch; //保存前缀字符 
            ps=decode(decode_stack+1,prefix);//调用函数进行解码 
        }
        else
            ps=decode(decode_stack,suffix); //调用解码函数处理后缀 
        
        ch=*ps;
        while(ps>=decode_stack) //循环输出解码的字节 
            putc(*ps--,output);        
        if (curr_code<=MAX_CODE) //若标号未超过最大值 
        {
            lzw->prefix[curr_code]=prefix; //保存前缀到编译表 
            lzw->suffix[curr_code]=ch;     //保存后缀到编译表 
            curr_code++; //标号增加 
        }
        prefix=suffix; //后缀作前缀，准备下次的循环 
    }
    
    free(lzw->code); //释放分配的内存 
    free(lzw->prefix);
    free(lzw->suffix);  
}
char *decode(unsigned char *buffer,unsigned int code) //解码函数 
{
    int i=0;
    while(code>257) //code不是ASCII码字符 
    {
        *buffer++ =lzw->suffix[code]; //保存标号到缓冲区 
        code=lzw->prefix[code]; //取得该标号的前缀 
        if (i++>=TABLE_SIZE)
        {
            printf("内存溢出!\n");
            exit(1);
        }
    }
    *buffer=code; //将标号放入缓冲区 
    return(buffer); //返回缓冲区中的内容 
}

unsigned int incode(FILE *input) //从压缩文件中读取数据 
{
    unsigned int ret;
    static int ib=0; //静态变量，保存读入数据的二进制位数 
    static unsigned long ibb=0L; //静态变量，保存已读入数据的二进制位
    while (ib <= 24) //若数据位数小于24位 
    {
        ibb |= (unsigned long) getc(input) << (24-ib); //从文件中获取一个字节，并组合到需输出的二进制位中 
        ib += 8;
    }
    ret=ibb>>(32-BITS); //右移20位二进制数 (32-12)
    ibb <<= BITS; //再左多12位 
    ib -= BITS; //减去已返回的位数 
    return(ret);//返回移位后的数据 
}
int main(int argc, char *argv[])
{
    FILE *fp1,*fp2;
    int flag=0;
    char *op;
    if(argc!=4) //判断传入参数的数量 
        flag=1;
    else{
        op=argv[1];
        if ((strcmp(op,"-z")!=0) && strcmp(op,"-e")!=0) flag=1;
    }
    if(flag)
    {
        printf("使用方法:command -z/-e source dest\n");
        exit(1); 
    }
    if((fp1=fopen(argv[2],"rb"))==NULL) //打开文件出错 
    {
        printf("不能打开源文件!\n");
        exit(1);
    }
    if((fp2=fopen(argv[3],"wb"))==NULL) //创建文件出错 
    {
        printf("不能创建目标文件!\n");
        exit(1); 
    }
    if(strcmp(op,"-z")==0)
        compress(fp1,fp2);//调用压缩函数 
    else
        expand(fp1,fp2);//调用解压缩函数 
    fclose(fp1);//释放文件指针 
    fclose(fp2);
    return 0;
}
