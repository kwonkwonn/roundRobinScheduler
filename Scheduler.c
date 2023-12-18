#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <unistd.h>
#include <stdio.h>
#include "threadCon.h"
#include <pthread.h>
#include <signal.h>


int		RunScheduler( void )
{
    Thread* threadCur=NULL;

    if(readyQueue->length==0) {
        printf("empty Queue\n");
    }else if(ReadyQHead->parentTid==pthread_self()){
        __thread_to_run(ReadyQHead);
        dequeue(readyQueue);
    }

    while(1){

        // 만약 레디큐의 쓰레드의 부모 쓰레드가 현재 같다면, 해당 쓰레드는 테스트 케이스를 만들기 위한 쓰레드
        //이기 때문에 사전에 지워준다. 그렇지 않다면 계속 돌면서 새끼쓰레드를 양산함.
        sleep(1);

        if(threadCur!=NULL){

            __ContextSwitch(threadCur, ReadyQHead);

            pthread_mutex_init(&QconMutex, NULL);

            Thread* threadToCycle=threadCur;
            threadCur=ReadyQHead;
            dequeue(readyQueue);
            enqueue(readyQueue, threadToCycle);
            pthread_mutex_lock(&QconMutex);

        }else{

            __ContextSwitch(threadCur, ReadyQHead);
            pthread_mutex_init(&QconMutex, NULL);

            threadCur=ReadyQHead;
            dequeue(readyQueue);
            pthread_mutex_lock(&QconMutex);

        }

    }
    return 0;
}


void  __ContextSwitch(Thread* pCurThread, Thread* pNewThread)
{
    if(pCurThread==NULL){
        __thread_to_run(pNewThread);
    }else{
        __thread_to_run(pNewThread);
        pthread_kill(pCurThread->tid,SIGUSR1);

    }
}

