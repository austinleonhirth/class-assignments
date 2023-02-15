/* 
 * race.c - demonstrates a race condition
 */
/* $begin race */
/* WARNING: This code is buggy! */
#include "csapp.h"
#define N 4

void *thread(void *vargp);

int main() 
{
    pthread_t tid[N];
    int* i = (int*)malloc(N * sizeof(int));
    int c;
    for (c = 0; c < N; c++)
        i[c]=c;
    for (c = 0; c < N; c++)                        //line:conc:race:incri
     	Pthread_create(&tid[c], NULL, thread, &i[c]); //line:conc:race:createthread
    for (c = 0; c < N; c++) 
    	Pthread_join(tid[c], NULL);

    free(i);
    exit(0);
}

/* Thread routine */
void *thread(void *vargp) 
{
    int myid = *((int *)vargp);  //line:conc:race:derefarg
    printf("Hello from thread %d\n", myid);
    return NULL;
}
/* $end race */
