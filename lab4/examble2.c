#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>

int is_prime(int num)
{
    if (num <= 1)
        return 0;
    if (num % 2 == 0 && num > 2)
        return 0;
    for (int i = 3; i < num / 2; i += 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
void *cal(int num)
{
    printf("the prime numbers are: ");
    for (int i = 1; i <= num; i++)
        if (is_prime(i))
            printf("%d ", i);
    printf("\n");
}
int main()
{
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    pthread_t t;
    pthread_create(&t,NULL,&cal,num);
    pthread_join(t,NULL);
    printf("child is done");
}