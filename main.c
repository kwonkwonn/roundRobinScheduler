#include <stdio.h>
#include <stdlib.h>
#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include <unistd.h>
#include "TestCase1.h"
#include "TestCase2.h"
#include "TestCase3.h"

//void* MyTestCase(void* arg)
//{
//    pthread_t t1,t2,t3;
//    int arg1=12, arg2=1,arg3=2;
//
//    thread_create(&t1, NULL, &foo1, &arg1);
//    thread_create(&t2, NULL, &foo2, &arg2);
//    thread_create(&t3, NULL, &foo1, &arg3);
//
//
//    // let's implement your testing code
//    return NULL;
//}

 pthread_mutex_t mainThreadMu;
pthread_mutex_t mainThreadCon;


void main(int argc, char* argv[])

{
    pthread_mutex_init(&mainThreadMu,NULL);
    pthread_cond_init(&mainThreadCon,NULL);


    int TcNum;
    thread_t tid1,tid2, tid3;
    argc=2;
    if(argc != 2)
    {
        perror("Input TestCase Number!");
        exit(0);
    }

    Init();
    argv[1]="3";
    TcNum = atoi(argv[1]);

    switch(TcNum)
    {
        case 1:
            thread_create(&tid1, NULL, (void*)TestCase1, 0);
            break;
        case 2:
            thread_create(&tid2, NULL, (void*)TestCase2, 0);
            break;
        case 3:
            thread_create(&tid3, NULL, (void*)TestCase3, 0);
            break;
    }


    RunScheduler();

    pthread_mutex_destroy(&mainThreadMu);
    pthread_cond_destroy(&mainThreadCon);



    while(1){}
}