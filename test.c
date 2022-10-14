#include<stdio.h>

void Download(const int _num,const char word[])
{ 
    char output[100]={"正在加载中。。。"};
    
    for (int i = 0; i < _num; i++)
    {
        char a[100] = {"start a.exe "};
       
        strcpy(&(a[strlen(a)]), word);
        system(a);
        system("cls");
        sprintf(output,"正在加载中。。。(%d/%d)",i+1,_num);
    }
}

int main()
{
    Download(1,"hello");
    system(".\b.exe hello");
}