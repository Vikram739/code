#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fclnt.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int cnt_char(char *str)
{
    int i=0,ch=0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            ch++;
        }
    }
    return(ch);
}
int cnt_wrd(char *str)
{
    int i=0,wrd=0;
    while(str[i] != '\0')
    {
        if(str[i] == ' ' && str[i] == '\n' && str[i] == '\t')
        {
            wrd++;
        }
    }
    return(wrd);
}
int cnt_line(char *str)
{
    int i=0,line=0;
    while(str[i] != '\0')
    {
        if(str[i] == '\n' )
        {
            line++;
        }
    }
    return(line);
}
int main()
{
    int fd1,fd2;
    char buff[100];
    char *str;
    char lines[100] = "Lines ara: ";
    char words[100] = "words are: ";
    char cha[100] = "char are: ";

    // create pipes...
    mkfifo("fifo2",0777);
    printf("fifo2 is created...");

    // read data...
    fd1 = open("fifo1",O_RDWR);
    read(fd1,buff,100);

    // write data...
    fd2 = open("fifo2",O_RDWR);

    // count...

    int ch = cnt_char(buff);
    int wrd = cnt_wrd(buff);
    int line = cnt_line(buff);

    // int to string...
    write(fd2,cha,100);

    return 0;
}