#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("u.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd < 0)
        return 0;
    pid_t pid = fork();

    if (pid == 0)
    {
        char text[] = "Hello World!";
        int size = write(fd, text, strlen(text));
    }
    else    {
        if (close(fd) < 0)
            perror("error");
        return 0;
    }
}