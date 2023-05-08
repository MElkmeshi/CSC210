#include <unistd.h>
#include <stdio.h>
int main()
{
    int p = fork();
    if (p > 0)
    {
        fork();
        printf("Hello World!\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}