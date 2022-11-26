#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fclnt.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
    char buff[100];
    int fd1,fd2;

    mkfifo("fifo1",0777);
    mkfifo("fifo2",0777);

    // write data
    fd2 = open("fifo1",O_RDWR);
    prinf("Enter data: ");
    fgets(buff,100,stdin);    
    write(fd2,buff,100);
    close(fd2);

    // read data...

    fd1 = open("fifo2",O_RDWR);
    read(fd1,buff,100);
    printf("Readed data: %s",buff);
    close(fd1);
    return 0;
}