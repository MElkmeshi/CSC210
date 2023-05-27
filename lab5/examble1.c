#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>

int main()
{
    int pipefds[2];
    char writemessages[2][20] = {"Hello World", "My First Program"};
    char readmessage[20];
    int returnstatus = pipe(pipefds);
    if (returnstatus == -1)
    {
        printf("Unable to create pipe\n");
        return 1;
    }
    int pid = fork();
    if (pid == 0)
    { // Child process
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Child Process - Reading from pipe - Message 1 is %s\n", readmessage);
        read(pipefds[0], readmessage, sizeof(readmessage));
        printf("Child Process - Reading from pipe - Message 2 is %s\n", readmessage);
    }
    else if (pid > 0)
    { // Parent process
        printf("Parent Process - Writing to pipe - Message 1 is %s\n", writemessages[0]);
        write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
        printf("Parent Process - Writing to pipe - Message 2 is %s\n", writemessages[1]);
        write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
    }
    else
    {
        printf("Unable to create fork()\n");
    }
    return 0;
}