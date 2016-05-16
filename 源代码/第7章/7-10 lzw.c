#include <stdlib.h>
#include <stdio.h>
#define BITS 12 //ÿ��������Ķ�����λ�� 
#define HASHING_SHIFT BITS-8 //HASH�����λ�� 
#define MAX_VALUE (1<<BITS)-1
#define MAX_CODE MAX_VALUE-1 //����� 
#define TABLE_SIZE 4099 //HASH��ĳ��� 
typedef struct{
    int *code;    //����
    unsigned int *prefix; //ǰ׺
    unsigned char *suffix; //��׺
}LZW_DATA;
unsigned char decode_stack[TABLE_SIZE]; //���ڱ����ѹ���������
LZW_DATA lzw1,*lzw;

void compress(FILE *input,FILE *output); //ѹ������ 
void expand(FILE *input,FILE *output); //��ѹ���� 
unsigned int hashsearch(int hash_prefix,unsigned int hash_character); //HASH���������� 
char *decode(unsigned char *buffer,unsigned int code);
unsigned int incode(FILE *input);
void outcode(FILE *output,unsigned int code);

void compress(FILE *input,FILE *output) //ѹ������ 
{
    unsigned int curr_code;
    unsigned int suffix;   //��׺�ַ� 
    unsigned int prefix;   //ǰ׺�ַ� 
    unsigned int index;
    int i;

    if(!(lzw1.code=malloc(TABLE_SIZE*sizeof(unsigned int)))) //����ֵ���� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0); 
    }
    if(!(lzw1.prefix=malloc(TABLE_SIZE*sizeof(unsigned int))))//ѹ��ǰ���� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0); 
    }    
    if(!(lzw1.suffix=malloc(TABLE_SIZE*sizeof(unsigned char))))//ѹ�������� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0); 
    }    
    lzw=&lzw1;
    curr_code=258; //������е��ַ�����Ŵ�258��ʼ 
    for(i=0;i<TABLE_SIZE;i++) //��ʼ��������� 
        lzw->code[i]=-1;
    i=0;
    printf("\n��ʼѹ��.");
    prefix=getc(input); //���ļ���ȡһ���ֽ� 
    while((suffix=getc(input))!= (unsigned)EOF) //ѭ�����������ļ��е����� 
    {
        if (++i==1000) //����1000���ֽ���ʾһ��С���㣬��ʾϵͳ���ڴ��� 
        {
            i=0;
            printf(".");
        }
        index=hashsearch(prefix,suffix); //��HASH���в��Ҳ����������� 
        if (lzw->code[index]!=-1)//���ñ�Ŵ��� 
            prefix=lzw->code[index];//ʹ�øñ����Ϊǰ׺ 
        else{                                            //����Ų����� 
            if (curr_code<=(MAX_CODE)){ //���δ��������� 
                lzw->code[index]=curr_code++; //����һ����� 
                lzw->prefix[index]=prefix;  //����ǰ׺ 
                lzw->suffix[index]=suffix; //�����׺ 
            }
            outcode(output,prefix); //���ǰ׺�ֽڵ����� 
            prefix=suffix;//����׺��ǰ׺��׼���´�ѭ�� 
        }
    }
    outcode(output,prefix); //���ǰ׺ 
    outcode(output,(MAX_VALUE)); //���������־ 
    outcode(output,0);   

    free(lzw->code); //�ͷŷ�����ڴ� 
    free(lzw->prefix);
    free(lzw->suffix);
}

unsigned int hashsearch(int prefix,unsigned int suffix)//HASH���������� 
{
    int index;
    int offset;
    index=(suffix << HASHING_SHIFT)^prefix; //����HASH��ַ 
    if(index == 0) 
        offset=1;
    else
        offset=TABLE_SIZE-index;
    while(1)
    {
        if(lzw->code[index]==-1) //�ҵ�һ���ձ��� 
            return(index); //����HASH��ַ 
        if (lzw->prefix[index]==prefix && lzw->suffix[index]==suffix) //�ҵ�Ŀ������ 
            return(index); //����HASH��ַ 
        index-=offset; //�����ͻ������HASH��ַ 
        if(index<0) index+=TABLE_SIZE; //����HASH��ַ 
    }
}

void outcode(FILE *output,unsigned int code) //���ѹ������ֽ����� 
{
    static int ob=0; //��̬������������������ݵĶ�����λ�� 
    static unsigned long obb=0L;//��̬������������������ݵĶ�����λ�� 
    obb |= (unsigned long) code << (32-BITS-ob); //������λ�ϲ� 
    ob+=BITS; //������������ݵĶ�����λ 
    while (ob>=8)  //�ﵽһ���ֽڣ������ 
    {
        putc(obb>>24,output); //����24λ��ʹ���ֽ�8λΪ��Ҫ��������� 
        obb<<= 8;  //����8λ��ȥ���������һ���ֽ����� 
        ob-=8;    //��ȥ�������8λ������ʣ���δ�����λ�� 
    }
    return;
}
void expand(FILE *input,FILE *output) //��ѹ������ 
{        
    unsigned int curr_code;
    unsigned int suffix;
    unsigned int prefix;
    int ch;
    int i;
    unsigned char *ps;
    char *decode(unsigned char *buffer,unsigned int code);
    
    if(!(lzw1.code=malloc(TABLE_SIZE*sizeof(unsigned int)))) //����ֵ���� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0); 
    }
    if(!(lzw1.prefix=malloc(TABLE_SIZE*sizeof(unsigned int))))//ѹ��ǰ���� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0);                                                       
    }
    if(!(lzw1.suffix=malloc(TABLE_SIZE*sizeof(unsigned char))))//ѹ�������� 
    {
        printf("�ڴ����ʧ��!\n");
        exit(0);                                                   
    }
    lzw=&lzw1;
    curr_code=258; //�����Ŵ�258��ʼ 
    i=0;
    printf("\n��ѹ��.");
    prefix=incode(input);  //�����һ�����룬����ʼ���ַ����� 
    ch=prefix; //����ǰ׺���ַ����� 
    putc(prefix,output);      // ����ַ�������ļ���
    while ((suffix=incode(input))!=(MAX_VALUE)) //ѭ�����н�ѹ�� 
    {
        if (++i==1000)    //����1000���ֽھ���ʾһ���� 
        {
            i=0;
            printf(".");
        }
        if (suffix>=curr_code)//��׺��δ����ı�� 
        {
            *decode_stack=ch; //����ǰ׺�ַ� 
            ps=decode(decode_stack+1,prefix);//���ú������н��� 
        }
        else
            ps=decode(decode_stack,suffix); //���ý��뺯�������׺ 
        
        ch=*ps;
        while(ps>=decode_stack) //ѭ�����������ֽ� 
            putc(*ps--,output);        
        if (curr_code<=MAX_CODE) //�����δ�������ֵ 
        {
            lzw->prefix[curr_code]=prefix; //����ǰ׺������� 
            lzw->suffix[curr_code]=ch;     //�����׺������� 
            curr_code++; //������� 
        }
        prefix=suffix; //��׺��ǰ׺��׼���´ε�ѭ�� 
    }
    
    free(lzw->code); //�ͷŷ�����ڴ� 
    free(lzw->prefix);
    free(lzw->suffix);  
}
char *decode(unsigned char *buffer,unsigned int code) //���뺯�� 
{
    int i=0;
    while(code>257) //code����ASCII���ַ� 
    {
        *buffer++ =lzw->suffix[code]; //�����ŵ������� 
        code=lzw->prefix[code]; //ȡ�øñ�ŵ�ǰ׺ 
        if (i++>=TABLE_SIZE)
        {
            printf("�ڴ����!\n");
            exit(1);
        }
    }
    *buffer=code; //����ŷ��뻺���� 
    return(buffer); //���ػ������е����� 
}

unsigned int incode(FILE *input) //��ѹ���ļ��ж�ȡ���� 
{
    unsigned int ret;
    static int ib=0; //��̬����������������ݵĶ�����λ�� 
    static unsigned long ibb=0L; //��̬�����������Ѷ������ݵĶ�����λ
    while (ib <= 24) //������λ��С��24λ 
    {
        ibb |= (unsigned long) getc(input) << (24-ib); //���ļ��л�ȡһ���ֽڣ�����ϵ�������Ķ�����λ�� 
        ib += 8;
    }
    ret=ibb>>(32-BITS); //����20λ�������� (32-12)
    ibb <<= BITS; //�����12λ 
    ib -= BITS; //��ȥ�ѷ��ص�λ�� 
    return(ret);//������λ������� 
}
int main(int argc, char *argv[])
{
    FILE *fp1,*fp2;
    int flag=0;
    char *op;
    if(argc!=4) //�жϴ������������ 
        flag=1;
    else{
        op=argv[1];
        if ((strcmp(op,"-z")!=0) && strcmp(op,"-e")!=0) flag=1;
    }
    if(flag)
    {
        printf("ʹ�÷���:command -z/-e source dest\n");
        exit(1); 
    }
    if((fp1=fopen(argv[2],"rb"))==NULL) //���ļ����� 
    {
        printf("���ܴ�Դ�ļ�!\n");
        exit(1);
    }
    if((fp2=fopen(argv[3],"wb"))==NULL) //�����ļ����� 
    {
        printf("���ܴ���Ŀ���ļ�!\n");
        exit(1); 
    }
    if(strcmp(op,"-z")==0)
        compress(fp1,fp2);//����ѹ������ 
    else
        expand(fp1,fp2);//���ý�ѹ������ 
    fclose(fp1);//�ͷ��ļ�ָ�� 
    fclose(fp2);
    return 0;
}
