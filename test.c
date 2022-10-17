#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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

int main() {
    system("chcp 65001");
    while (1)
    {
        char a[100]={0};
        scanf("%s",a);
        print_in(a,a,"helowd",a,a);
        getchar();
        getchar();
        system("cls");
    }
    
   
    return 0;
}