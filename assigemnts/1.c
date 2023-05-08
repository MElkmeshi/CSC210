#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("temp.txt", O_CREAT | O_RDWR, S_IRUSR|S_IWUSR|S_IXGRP);
    if (fd > 0)
    {
        char text[] = "Welcome to Ubunto!";
        int size = write(fd, text, strlen(text));
    }
    char A[18];
    int n = read(fd, A, 18);
    printf("%s \n", A);
    char txt[] = "\nThis is my first C program in Ubuntu";
    int size = write(fd, txt, strlen(txt));
    if (close(fd) < 0)
        perror("error");
    return 0;
}