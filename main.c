#include <stdio.h>
#include <stdlib.h>
#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int number=0;


void * foo1(void * arg){

    for(int i=0; i<3; i++){
        pthread_mutex_lock(&mutex);
        number++;
    printf("%d \n",number);
    fflush(stdout);
    pthread_mutex_unlock(&mutex);
    sleep(1);

    }

}

void* MyTestCase(void* arg)
{
    pthread_t t1,t2,t3;
    int arg1=12, arg2=1,arg3=2;

    thread_create(&t1, NULL, &foo1, &arg1);
    thread_create(&t2, NULL, &foo1, &arg2);
    thread_create(&t3, NULL, &foo1, &arg3);

    // let's implement your testing code
    return NULL;
}


void main(int argc, char* argv[])
{

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond,NULL);

    int TcNum;
    thread_t tid1;
    printf("%d",12);
    argc=2;    if(argc != 2)
    {
        perror("Input TestCase Number!");
        exit(0);
    }

    Init();
    argv[1]="1";
    TcNum = atoi(argv[1]);

    switch(TcNum)
    {
        case 1:
            thread_create(&tid1, NULL, (void*)MyTestCase, 0);
            break;
/*
        case 2:
            thread_create(&tid2, NULL, (void*)TestCase2, 0);
            break;
        case 3:
            thread_create(&tid3, NULL, (void*)TestCase3, 0);
            break;
*/
    }

    RunScheduler();
    pthread_attr_destroy(&mutex);
    pthread_cond_destroy(&cond);
    while(1){}
}