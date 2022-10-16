#include<stdio.h>
#include<string.h>
#include<windows.h>
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



int main()
{
    
    WinExec("a.exe hello",SW_HIDE);
    WinExec("b.exe hello",SW_HIDE);
    int b=0;
    scanf("%d",&b);
    Storage_Location(b,2);
    scanf("%d",&b);
    int a=Read_Location(b);
    printf("%d",a);
}