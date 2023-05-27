#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork();
    if (pid < 0)    
        printf("Fork Failed");
    else if(pid == 0){
        execlp("ls","ls","-l",NULL);
        printf("asssssssssssasasa\n");
    }
    else{
        wait(NULL);
        printf("Child Compelete\n");
    }

}