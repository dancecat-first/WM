#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <unistd.h>
#include <windows.h>
#include<direct.h>  

void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
} 
//定义单词结构体
typedef struct WORDS
{
    char Word[20];
    char Means[100];
} WORDS;

void Mandatory_testing(int num,WORDS wd[num]);//强制测试模块
char* getWords(char *find);//获取文件内容
char* findWords(char *word, int _num,WORDS wd[_num]);//获取多个单词模块
char getWord(char *words, int num, WORDS wd[num]);//分析获取单个单词模块
void Download(const int _num,const WORDS wd[_num]);//下载音频模块
void putword(const int _num,WORDS wd[_num],int unit);
void Reverse_Memory(int word_num,char *putout,WORDS wd[],int _num);//逆向记忆模块
void Component_1(char *title,char *word,char * word_1,char * word_2,char * word_3);//测试组件1
void Word_Test(int word_num,char *putout,WORDS wd[]);//单词测试模块
void Storage_Location(int unit,int word_num);//写入位置模块
void WORDS_Init(int num,WORDS wd[num]);//初始化函数
int Read_Location(int unit);//读取上一次的位置
int Generate_random_numbers(int num);//产生随机数
void word_init(char *find,int num,int unit);//初始化模块
void print_in(char *word);//输出模块
void Review(WORDS wd[],int unit);//复习模块
void beg();//开始

int main()
{
    //char *find=NULL;
    system("mode con cols=115 lines=25");
    system("color 6");
    SetConsoleOutputCP(65001);
    //system("chcp 437");
    system("cls");
    
    beg();
    
    getchar();
    /*char a_1[100]={"一. 冠词 (3个)"};
    char a_2[100]={"二. 连词 (24个)"};
    system("cls");
    print_in("请选择要学习的单元：");
    char in=getchar();
    switch (in)
    {
    case '1':
        find=a_1;
        word_init(find,3);
        break;
    case '2':
        find=a_2;
        word_init(find,24);
        break;
    default:
        break;
    }*/
    char find[100]={"二. 连词 (24个)"};
    word_init(find,24,2);
    print_in("学习完成，恭喜");
    Sleep(5000);
    return 0;
}

void beg()
{
    print_in("Welcome");
    Sleep(1000);
    system("cls");
    print_in("按Enter键开始");
    gotoxy(114,12);
    char turn=getch();
    switch (turn)
    {
    case '\n':
        return;
        break;
    case '\r':
        return;
        break;
    case '0':
        system("del /F /S /Q music");
        system("del location.log");
        system("pause");
        exit(0);
        break;
    case '1':
        exit(0);
        break;
    default:
        break;
    }
    
}
void word_init(char *find,int num,int unit)
{
    WORDS wd[num];
    WORDS_Init(num,wd);
    char *a=getWords(find)/*查找find以下的单词*/;
    char *b=findWords(a,num,wd);
    getWord(b,num, wd);
    //Download(num,wd);
    Mandatory_testing(num,wd);
    putword(num,wd,unit);
}

void WORDS_Init(int num,WORDS wd[num])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            wd[i].Means[j]='\0';
        }
        for (int k = 0; k < 20; k++)
        {
            wd[i].Word[k]='\0';
        }
    }
}

char* getWords(char *find)
{
    char word[1024 * 1024]={0};
    FILE *fp = fopen("word.txt", "r");
    for (int i = 0; i < 1024 * 1024; i++)
    {
        word[i] = fgetc(fp);
        if (word[i] == EOF)//判断是否收到文件结束符
        {
            word[i] = '\0';
            break;
        }
    }
    char *noun;
    noun = strstr(word, find);
    noun += (strlen(find)+2);
    //printf("%s\n",noun);
    
    //printf("%s",noun);
    return noun;//返回查找到的单词
}


char* findWords(char _word[], int _num,WORDS wd[_num])
{

    char *words = malloc(1024 * 1024 * sizeof(char));
    char num[5] = {0};
    for (int i = 1; i <= _num; i++)
    {

        sprintf(num, "%d", i);
        num[strlen(num)] = '.';
        // printf("\t\n%s\n\t",num);
        char *temp = strstr(_word, num);
        char *temp_2 = strstr(temp, "\n\n");//查找两个换行符
        temp_2 += 1;
        char *temp_3 = strstr(temp_2, " ");
        if (temp == NULL || temp_2 == NULL || temp_3 == NULL)
            break;
        strncpy(words + strlen(words), temp, temp_2 - temp);
    }
    
    
    return words;
}

char getWord(char *words, int num, WORDS wd[num])
{
    for (int i = 0; i < num; i++)//英文
    {
        char number[6] = {0};
        sprintf(number, "%d", (i + 1));
        // printf("%ld",strlen(number));
        number[strlen(number)] = '.';
        // number[strlen(number)]=' ';

        char *temp = strstr(words, number);
        temp += (strlen(number) + 1);
        // char* temp_2=strstr(temp," ");
        // temp_2+=1;
        char *temp_2 = strstr(temp, " ");
        // temp_2+=1;
        strncpy(wd[i].Word, temp, temp_2 - temp);
        for (int j = 0; j < strlen(wd[i].Word); j++)
        {
            if(wd[i].Word[j]=='_')
            {
                wd[i].Word[j]=' ';
            }
        }
        
    }
    for (int i = 0; i < num; i++)//中文
    {
        char number[6] = {0};
        sprintf(number, "%d", (i + 1));
        number[strlen(number)] = '.';
        char *temp = strstr(words, number);
        temp += (strlen(number) + 1);
        char *temp_2 = strstr(temp, " ");
        temp_2+=1;
        char *temp_3 = strstr(temp, "\n");
        strncpy(wd[i].Means, temp_2, temp_3 - temp_2);
    }
}

void putword(const int _num,WORDS wd[_num],int unit)
{
    //word_num + (9 - word_num % 10)
    /*char output[50]={0};
    sprintf(output,"一共%d个单词", _num);
    system("cls");
    print_in(output);
    Sleep(1000);*/
    system("cls");
    char putout[100]={0};
    int word_num = Read_Location(unit);
    char input[20] = {0};
    if(word_num!=0)
    {
        Review(wd,unit); 
        system("cls");
        print_in("   复习完成");
        Sleep(1000);
        system("cls");
        word_num++;
    }
    
    while (word_num < _num - 10)
    {

        for (int i = word_num; i <= word_num + (9 - word_num % 10); i++)
        {
            if(_num<=word_num)
            {
                return;
            }
            Storage_Location(unit,i);
            system("cls");
            for (int i = 0; i < 100; i++)
            {
                putout[i]='\0';
            }
            sprintf(putout,"请说出中文:%d.%s", i + 1, wd[i].Word);
            char a[100] = {"b.exe \""};
            strcpy(&(a[strlen(a)]), wd[i].Word);
            strcpy(&(a[strlen(a)]), "\"\0");
            //print_in("");
            print_in(putout);
            WinExec(a,SW_HIDE);
            
            while (1)
            {
                char get = getchar();
                printf("\b");
                if (get == '\n')
                {
                    system("cls");
                    for (int i = 0; i < 100; i++)
                    {
                        putout[i]='\0';
                    }
                    sprintf(putout,"%d.%s %s", i + 1, wd[i].Word,wd[i].Means);
                    print_in(putout);
                    get = getchar();
                    if (get == '\n')
                    {
                        break;
                    }
                }
                else
                {
                    WinExec(a,SW_HIDE);
                    system("cls");
                    print_in(putout);
                    fflush(stdin);
                }
            }
        }
        if(_num<=word_num)
        {
            return;
        }
        Reverse_Memory(word_num,putout,wd,_num);
       for(int i=0;i<2;i++)
       {
        Word_Test(word_num,putout,wd);
        system("cls");
        if(i==0)
        {
            print_in("再来一次");
            getch();
        }
       
        
       }
        word_num += 10;
    }
    
    
    for (int i = word_num; i < _num; i++)
    {
        if(_num<=word_num)
        {
            return;
        }
        Storage_Location(unit,i);
            system("cls");
            for (int i = 0; i < 100; i++)
            {
                putout[i]='\0';
            }
            sprintf(putout,"%s", wd[i].Word);
            char a[100] = {"b.exe \""};
            strcpy(&(a[strlen(a)]), wd[i].Word);
            strcpy(&(a[strlen(a)]), "\"\0");
            WinExec(a,SW_HIDE);
            
            while (1)
            {

                //system("stty -echo");
                char get = getchar();
                printf("\b");
                if (get == '\n')
                {
                    system("cls");
                    for (int i = 0; i < 100; i++)
                    {
                        putout[i]='\0';
                    }
                    sprintf(putout,"%d.%s %s", i + 1, wd[i].Word,wd[i].Means);
                    print_in(putout);
                    get = getchar();
                    if (get == '\n')
                    {
                        break;
                    }
                }
                else
                {
                    WinExec(a,SW_HIDE);
                    system("cls");
                    print_in(putout);
                    fflush(stdin);
                }
            }
    }
    if(_num<=word_num)
    {
            return;
    }
    Reverse_Memory(word_num,putout,wd,_num);
       for(int i=0;i<2;i++)
       {
        Word_Test(word_num,putout,wd);
        system("cls");
        print_in("再来一次");
        getch();
       }
}

void Download(const int _num,const WORDS wd[_num])
{ 
    char output[100]={"正在加载中。。。"};
    
    for (int i = 0; i < _num; i++)
    {
        char a[100] = {"a.exe \""};
       
        strcpy(&(a[strlen(a)]), wd[i].Word);
        strcpy(&(a[strlen(a)]), "\"\0");
        WinExec(a,SW_HIDE);
        system("cls");
        sprintf(output,"正在加载中。。。(%d/%d)",i+1,_num);
        print_in(output);
    }
}
void print_in(char *word)
{
    /*if(strlen(word)>45-15)
    {
        puts("The word is too long");
        return;
    }*/
    char pu[100]={0};
    char pu_2[100]={0};
    int sum = 0;
    int index = 0;
    while(word[index])
    {
        if (word[index] < 0)
        {
            sum++;
        }
        index++;
    }
    
    sum /= 3;
    sprintf(pu,"\t\t\t\t");
    for (int i = 4; i < 50+4; i++)
    {
        sprintf(&pu[i],"-");
    }
    sprintf(&pu[strlen(pu)],"\n");
    
    
    sprintf(pu_2,"%s","\t\t\t\t*\t\t\t\t\t\t *\n");
    printf("%s",pu);

    for (int i = 0; i < 4; i++)
    {
        printf("%s",pu_2);
    }
   
                char pu_3[100]={0};
                
    
                for(int i=0;i<4;i++)
                {
                    pu_3[i]='\t';
                }
                pu_3[4]='*';
                for (int i = 5; i < 54; i++)
                {
                    pu_3[i]=' ';
                }   
                int temp=50/2-strlen(word)/2+strlen(word)%2+4;
                strncpy(&pu_3[temp],word,strlen(word));
                for (int i = temp+strlen(word); i < 100; i++)
                {
                    pu_3[i]='\0';
                }
                int t=(strlen(pu_3)-1-sum-3);
                printf("%s",pu_3);
                for (int i = 0; i < (50-t-1)/*+sum*2-1*/; i++)
                {
                    printf("%c",' ');
                }
                printf("*\n");
    
        
    for (int i = 0; i < 5; i++)
    {
        printf("%s",pu_2);
    }   
    printf("%s",pu);

    return;
    
}


void Reverse_Memory(int word_num,char *putout,WORDS wd[],int _num)
{
    system("cls");
     print_in("开始逆向记忆");
    Sleep(500);
        for (int i = word_num; i <= word_num + (9 - word_num % 10); i++)
        {
            if(_num<=word_num)
            {
                return;
            }
            system("cls");
            for (int i = 0; i < 100; i++)
            {
                putout[i]='\0';
            }
            sprintf(putout,"请说出英文:%d.%s", i + 1, wd[i].Means);
            char a[100] = {"b.exe \""};
            strcpy(&(a[strlen(a)]), wd[i].Word);
            strcpy(&(a[strlen(a)]), "\"\0");
            print_in(putout);
            WinExec(a,SW_HIDE);
            
            while (1)
            {
                char get = getchar();
                printf("\b");
                if (get == '\n')
                {
                    system("cls");
                    for (int i = 0; i < 100; i++)
                    {
                        putout[i]='\0';
                    }
                    sprintf(putout,"%d.%s %s", i + 1, wd[i].Word,wd[i].Means);
                    print_in(putout);
                    get = getchar();
                    if (get == '\n')
                    {
                        break;
                    }
                }
                else
                {
                    WinExec(a,SW_HIDE);
                    system("cls");
                    print_in(putout);
                    fflush(stdin);
                }
            }

        }
    return;
}

void Word_Test(int word_num,char *putout,WORDS wd[])
{
    int count=0;
    system("cls");
    print_in("开始测试");
    Sleep(500);
    for (int i = word_num; i <= word_num + (9 - word_num % 10); i++)
    {
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            putout[i]='\0';
        }
        sprintf(putout,"%d.%s", i + 1, wd[i].Means);
        char a[100] = {"b.exe \""};
        strcpy(&(a[strlen(a)]), wd[i].Word);
        strcpy(&(a[strlen(a)]), "\"\0");
        print_in(putout);
        WinExec(a,SW_HIDE);
 
        while (count<3)
        {
            char EnterWord[100]={0};
            printf("请写出英文:");
            scanf("%s",EnterWord);
            if(strcmp(EnterWord,wd[i].Word)!=0)
            {
                count++;
                printf("\n输入错误");
                printf("\t%s\n",wd[i].Word);
                Sleep(1500);
                system("cls");
                print_in(putout);
                continue;
            }
            else
            {
                count=0;//清零
                printf("\n输入正确\n");
                Sleep(500);
                break;
            }
        }

    }
}

void Storage_Location(int unit,int word_num)
{
    char f_in[10]={0};
    FILE *fp=fopen("location.log","w");
    sprintf(f_in,"%d%s%d",unit,",",word_num);
    fwrite(f_in,sizeof(char),strlen(f_in),fp);
    fclose(fp);
}

int Read_Location(int unit)
{
    char f_out[10]={0};
    char TP='\0';
    int L=0;
    int temp=0;
    FILE *fp;
    if((fp=fopen("location.log","r"))==NULL)//如果没有此文件，则返回0
    {
        return 0;
    }
    else//如果有，则开始读取
    {
        for (int i = 0; i < 10; i++)
        {
            f_out[i]=fgetc(fp);
            if (f_out[i]==',')
            {
                f_out[i]='\0';
                sscanf(f_out,"%d",&temp);
                if (temp==unit)
                {
                    char f_out_next[10]={0};
                    for (int i = 0; i < 10; i++)
                    {
                        f_out_next[i]=fgetc(fp);
                        if (f_out_next[i]==EOF)
                        {
                            f_out_next[i]='\0';
                            sscanf(f_out_next,"%d",&L);
                            return L;
                        }
                    }
                }
                else
                {                    
                    return 0;
                }   
            }  
            
        }  
    }
    return 0;
}


void Review(WORDS wd[],int unit)
{
    print_in("开始复习(按Enter开始)");
    Sleep(1000);
    char *a=malloc(sizeof(char));
    *a=getch();
    if(*a!='\r')
    {
        system("cls");
        print_in("退出成功");
        Sleep(500);
        system("cls");
        return;
    }
    int word_num=Read_Location(unit);
    char putout[100]={0};
    for (int i = 0; i <= word_num ; i++)
        {
            system("cls");
            for (int i = 0; i < 100; i++)
            {
                putout[i]='\0';
            }
            sprintf(putout,"请说出中文:%d.%s(%d/%d)", i + 1, wd[i].Word,i+1,word_num+1);
            char a[100] = {"b.exe \""};
            strcpy(&(a[strlen(a)]), wd[i].Word);
            strcpy(&(a[strlen(a)]), "\"\0");
            print_in(putout);
            WinExec(a,SW_HIDE);
            
            while (1)
            {
                char get = getchar();
                printf("\b");
                if (get == '\n')
                {
                    system("cls");
                    for (int i = 0; i < 100; i++)
                    {
                        putout[i]='\0';
                    }
                    sprintf(putout,"%d.%s %s", i + 1, wd[i].Word,wd[i].Means);
                    print_in(putout);
                    get = getchar();
                    if (get == '\n')
                    {
                        break;
                    }
                }
                else
                {
                    WinExec(a,SW_HIDE);
                    system("cls");
                    print_in(putout);
                    fflush(stdin);
                }
            }
        }

}

void Mandatory_testing(int num,WORDS wd[num])
{
    int ago_num[1024]={0};

    int count=0;
    int nth_word=0;
    int nth=0;
    for(int i=0;i<num;i++)
    {
        char out_put[100]={0};
        char out_put_1[100]={0};
        char out_put_2[100]={0};
        char out_put_3[100]={0};
        char out_put_4[100]={0};
        nth_word=rand()%num;
        srand((unsigned)time(NULL));
agian:
        for(int j=0;j<i;j++)
        {
            
            if(nth_word==ago_num[j])
            {
                nth_word=rand()%num;
                srand((unsigned)time(NULL));
                goto agian;
            }
        }
        nth=rand()%2;
        if (nth==1)
        {
            system("cls");
            sprintf(out_put,"%d.%s", i + 1, wd[nth_word].Means);
            char a[100] = {"b.exe \""};
            strcpy(&(a[strlen(a)]), wd[nth_word].Word);
            strcpy(&(a[strlen(a)]), "\"\0");
            print_in(out_put);
            WinExec(a,SW_HIDE);

            count=0;//清零
            while(count<3)
            {
                char EnterWord[100]={0};
                printf("请写出英文:");
                fflush(stdin);
                scanf("%s",EnterWord);
                if(strcmp(EnterWord,wd[nth_word].Word)!=0)
                {
                    count++;
                    printf("\n输入错误");
                    printf("\t%s\n",wd[nth_word].Word);
                    Sleep(1500);
                    system("cls");
                    print_in(out_put);
                    continue;
                }
                else
                {
                    count=0;//清零
                    printf("\n输入正确\n");
                    Sleep(500);
                    break;
                }
            }
            ago_num[i]=nth_word;
        }
        else
        {
            system("cls");
            sprintf(out_put,"请选择中文:%d.%s", i + 1, wd[nth_word].Word);
            int temp=Generate_random_numbers(4);
            switch (temp)
            {
            case 0:
                sprintf(out_put_1,"A.%s",wd[nth_word].Means);
                sprintf(out_put_2,"B.%s",wd[Generate_random_numbers(num)+1].Means);
                sprintf(out_put_3,"C.%s",wd[Generate_random_numbers(num)+2].Means);
                sprintf(out_put_4,"D.%s",wd[Generate_random_numbers(num)+3].Means);
                break;
            case 1:
                sprintf(out_put_1,"A.%s",wd[Generate_random_numbers(num)+3].Means);
                sprintf(out_put_2,"B.%s",wd[nth_word].Means);
                sprintf(out_put_3,"C.%s",wd[Generate_random_numbers(num)+1].Means);
                sprintf(out_put_4,"D.%s",wd[Generate_random_numbers(num)+2].Means);
                break;
            case 2:
                sprintf(out_put_1,"A.%s",wd[Generate_random_numbers(num)+1].Means);
                sprintf(out_put_2,"B.%s",wd[Generate_random_numbers(num)+2].Means);
                sprintf(out_put_3,"C.%s",wd[nth_word].Means);
                sprintf(out_put_4,"D.%s",wd[Generate_random_numbers(num)+3].Means);
                break;
            case 3:
                sprintf(out_put_1,"A.%s",wd[Generate_random_numbers(num)+1].Means);
                sprintf(out_put_2,"B.%s",wd[Generate_random_numbers(num)+2].Means);
                sprintf(out_put_3,"C.%s",wd[Generate_random_numbers(num)+3].Means);
                sprintf(out_put_4,"D.%s",wd[nth_word].Means);
                break;
            default:
                break;
            }
            Component_1(out_put,out_put_1,out_put_2,out_put_3,out_put_4);
            count=0;//清零
            while(count<3)
            {
                char word_answer='0';
                char EnterWord='0';
                switch (temp)
                {
                case 0:
                        word_answer='A';
                    break;
                case 1:
                        word_answer='B';
                    break;
                case 2:
                        word_answer='C';
                    break;
                case 3:
                        word_answer='D';
                    break;
                default:
                    break;
                }
                printf("请选择:");
                fflush(stdin);
                EnterWord=getchar();
                if(EnterWord!=word_answer)
                {
                    count++;
                    printf("\n输入错误");
                    printf("\t%c\n",word_answer);
                    Sleep(1500);
                    system("cls");
                    Component_1(out_put,out_put_1,out_put_2,out_put_3,out_put_4);
                    continue;
                }
                else
                {
                    count=0;//清零
                    printf("\n输入正确\n");
                    Sleep(500);
                    break;
                }
            }
            ago_num[i]=nth_word;
        }

    }
}

int Generate_random_numbers(int num)
{
    int rand_4=rand()%num;
    srand((unsigned)time(NULL));
    return rand_4;
}

void Component_1(char *title,char *word,char * word_1,char * word_2,char * word_3)
{
    /*if(strlen(word)>45-15)
    {
        puts("The word is too long");
        return;
    }*/
    char pu[100]={0};
    char pu_2[100]={0};
    int sum = 0;
    int index = 0;
    while(word[index])
    {
        if (word[index] < 0)
        {
            sum++;
        }
        index++;
    }
    
    sum /= 3;
    sprintf(pu,"\t\t\t\t");
    for (int i = 4; i < 50+4; i++)
    {
        sprintf(&pu[i],"-");
    }
    sprintf(&pu[strlen(pu)],"\n");
    
    
    sprintf(pu_2,"%s","\t\t\t\t*\t\t\t\t\t\t *\n");
    printf("%s",pu);

    for (int i = 0; i < 2; i++)
    {
        printf("%s",pu_2);
    }

            {
                char pu_3[100]={0};
                for(int i=0;i<4;i++)
                {
                    pu_3[i]='\t';
                }
                pu_3[4]='*';
                for (int i = 5; i < 54; i++)
                {
                    pu_3[i]=' ';
                }   
                int temp=50/2-strlen(title)/2+strlen(title)%2+4;
                strncpy(&pu_3[temp],title,strlen(title));
                for (int i = temp+strlen(title); i < 100; i++)
                {
                    pu_3[i]='\0';
                }
                int t=(strlen(pu_3)-1-sum-3);
                printf("%s",pu_3);
                for (int i = 0; i < (50-t-1)/*+sum*2-1*/; i++)
                {
                    printf("%c",' ');
                }
                printf("*\n");
            }
   
            {    char pu_3[100]={0};
                for(int i=0;i<4;i++)
                {
                    pu_3[i]='\t';
                }
                pu_3[4]='*';
                for (int i = 5; i < 54; i++)
                {
                    pu_3[i]=' ';
                }   
                int temp=50/2-strlen(word)/2+strlen(word)%2+4;
                strncpy(&pu_3[temp],word,strlen(word));
                for (int i = temp+strlen(word); i < 100; i++)
                {
                    pu_3[i]='\0';
                }
                int t=(strlen(pu_3)-1-sum-3);
                printf("%s",pu_3);
                for (int i = 0; i < (50-t-1)/*+sum*2-1*/; i++)
                {
                    printf("%c",' ');
                }
                printf("*\n");
            }
                
            {
                char pu_3[100]={0};
                for(int i=0;i<4;i++)
                {
                    pu_3[i]='\t';
                }
                pu_3[4]='*';
                for (int i = 5; i < 54; i++)
                {
                    pu_3[i]=' ';
                }   
                int temp=50/2-strlen(word_1)/2+strlen(word_1)%2+4;
                strncpy(&pu_3[temp],word_1,strlen(word_1));
                for (int i = temp+strlen(word_1); i < 100; i++)
                {
                    pu_3[i]='\0';
                }
                int t=(strlen(pu_3)-1-sum-3);
                printf("%s",pu_3);
                for (int i = 0; i < (50-t-1)/*+sum*2-1*/; i++)
                {
                    printf("%c",' ');
                }
                printf("*\n");
            }

            {
                char pu_3[100]={0};
                for(int i=0;i<4;i++)
                {
                    pu_3[i]='\t';
                }
                pu_3[4]='*';
                for (int i = 5; i < 54; i++)
                {
                    pu_3[i]=' ';
                }   
                int temp=50/2-strlen(word_2)/2+strlen(word_2)%2+4;
                strncpy(&pu_3[temp],word_2,strlen(word_2));
                for (int i = temp+strlen(word_2); i < 100; i++)
                {
                    pu_3[i]='\0';
                }
                int t=(strlen(pu_3)-1-sum-3);
                printf("%s",pu_3);
                for (int i = 0; i < (50-t-1)/*+sum*2-1*/; i++)
                {
                    printf("%c",' ');
                }
                printf("*\n");
            }

            {
                char pu_3[100]={0};
                for(int i=0;i<4;i++)
                {
                    pu_3[i]='\t';
                }
                pu_3[4]='*';
                for (int i = 5; i < 54; i++)
                {
                    pu_3[i]=' ';
                }   
                int temp=50/2-strlen(word_3)/2+strlen(word_3)%2+4;
                strncpy(&pu_3[temp],word_3,strlen(word_3));
                for (int i = temp+strlen(word_3); i < 100; i++)
                {
                    pu_3[i]='\0';
                }
                int t=(strlen(pu_3)-1-sum-3);
                printf("%s",pu_3);
                for (int i = 0; i < (50-t-1)/*+sum*2-1*/; i++)
                {
                    printf("%c",' ');
                }
                printf("*\n");
            }
        
    for (int i = 0; i < 3; i++)
    {
        printf("%s",pu_2);
    }   
    printf("%s",pu);

    return;
    
}
