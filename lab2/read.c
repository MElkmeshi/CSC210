#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    int fd= open("h.txt",O_RDONLY);
    if (fd <0)
        printf(" the return value %d \n",fd);
    else
    {
        char data[128];
        int size= read(fd ,data,128);
        printf("returned value %d \n",size);
        printf("%s" ,data);
    }
    if(close(fd)<0)
    {
        perror("error");
    }
    return 0;
}
