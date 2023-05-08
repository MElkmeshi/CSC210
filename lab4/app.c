#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int arr1[5];
void *AVG(int avg)
{
    avg = 0;
    for (int i = 0; i < 5; i++)
        avg += arr1[i];
    avg /= 5;
}
void *MIN(int min)
{
    min = arr1[0];
    for (int i = 1; i < 5; i++)
        min = min < arr1[i] ? min : arr1[i];
}
void *MAX(int max)
{
    max = arr1[0];
    for (int i = 1; i < 5; i++)
        max = max > arr1[i] ? max : arr1[i];
}

int main()
{
    int avg;
    int max;
    int min;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr1[i]);
    }

    pthread_t tid1;
    pthread_create(&tid1, NULL, AVG, &avg);
    pthread_join(tid1, NULL);
    printf("avgerge = %d\n", avg);
    pthread_t tid2;
    pthread_create(&tid2, NULL, MAX, &max);
    pthread_join(tid2, NULL);
    printf("max = %d\n", max);
    pthread_t tid3;
    pthread_create(&tid3, NULL, MIN, &min);
    pthread_join(tid3, NULL);
    printf("min = %d\n", min);

    pthread_exit(NULL);
    return 0;
}