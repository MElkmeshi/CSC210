#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
    pid_t pid = fork();
    if (pid==0) {
        printf("child process and PID is %d\n",getpid());
        exit(0);
    }
    if (pid >0)    
        printf("parent process PID is %d\n",getpid());
    else
        printf("error");
    return(0);
}