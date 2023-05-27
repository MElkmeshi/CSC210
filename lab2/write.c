#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("h.txt", O_RDWR, 0666);
    if (fd < 0)
    {
        printf("the return value %d \n \n", fd);
    }
    else
    {
        int size = write(fd, "hello world\n", strlen("hello world\n"));
        printf("returned value %d \n", size);
    }
    if (close(fd) < 0)
    {
        perror("error");
    }

    return 0;
}
