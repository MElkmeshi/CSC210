#include <unistd.h>
#include <stdio.h>
int main()
{
    int p = fork();
    if (p > 0)  {
        printf("Hello World!\n");
        fork();
    }
    else
        printf("No\n");
    return 0;
}