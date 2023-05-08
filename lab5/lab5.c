#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char writemessages[2][20] = {"Hello World", "My first Project"};
    char readmessage[20];            // initialize the string that store the message
    int pipefds[2];                  // initialize the pipe modes 1 write 0 read
    int returstatus = pipe(pipefds); // initialize the pipe
    if (returstatus == -1)           // handle error if pipe isn't initialized
    {
        printf("Unable to create pipe\n");
        return 1;
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("enter child\n");
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("child - Reading from pipe - Message 1 is %s\n", readmessage);
        exit(0);
    }
    else if (pid > 0)
    {
        printf("enter patent wait for child\n");
        wait(NULL);
        printf("patent - Writing to pipe - Message 1 is %s\n", writemessages[1]);
        write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
    }
    else
    {
        printf("error");
        return 1;
    }
}