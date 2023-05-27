#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>

#define N 20
sem_t sem1, sem2;
char Buffer[N];

void *Writer()
{
    while (1)
    {
        sem_wait(&sem1);
        printf("write here: \n");
        fgets(Buffer, N , stdin);
        sem_post(&sem2);
    }
}
void *Reader()
{
    while (1)
    {
        sem_wait(&sem2);
        printf("Data Read: %s\n", Buffer);
        sem_post(&sem1);
    }
}

int main()
{
    pthread_t id1, id2;
    sem_init(&sem1, 0,1);
    sem_init(&sem2, 0, 0);
    pthread_create(&id1, NULL, Writer, NULL);
    pthread_create(&id2, NULL, Reader, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);
    pthread_exit(NULL);
    return 0;
}