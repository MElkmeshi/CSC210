#include<stdio.h>
#include<unistd.h>

int main()
{
    execlp("cal", "03 2022", NULL);
}