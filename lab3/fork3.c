#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>

int main()
{

    printf("The current process has a Process Id = %d\n\n", getpid());
    int pid = fork();
    int var;
    printf("fork returned %d\n", pid);
    if (pid < 0)
    {
        perror("Fork failed");
    }
    else if (pid == 0)
    {
        printf("I am the child\n");
        printf("Child's pid: %d\n", getpid());
        printf("In child, enter any number:\n");
        scanf("%n\n", &var);
    }
    else
    {
        pid_t cpid = wait(NULL);
        printf("Child pid = %d\n", cpid);
        printf("I am the Parent\n");
        printf("Child with pid: %d\n", pid);
        printf("Parent with pid: %d\n", getpid());
        printf("In parent, enter any number:\n");
        scanf("%n\n", &var);
    }
    return 0;
}
