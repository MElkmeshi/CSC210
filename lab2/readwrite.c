#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(){
    int fd= open("h.txt",O_RDWR);
    if (fd <0)
        printf("file don't exist with error code: %d ",fd);
    else
    {
        char data[128];
        int size= read(fd ,data,128);
        printf("size of read %d \n",size);
        printf("%s" ,data);
        int sizeofread = write(fd, "hello world\n", strlen("hello world\n"));
        printf("size of write %d \n", sizeofread);
    }
    if(close(fd)<0)
    {
        perror("error");
    }
    return 0;
}