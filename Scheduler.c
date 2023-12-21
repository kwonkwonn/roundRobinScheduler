#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <unistd.h>
#include <stdio.h>
#include "threadCon.h"
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>

int		RunScheduler( void )
{
    Thread* threadCur=NULL;

    while(1){
        sleep(TIMESLICE);
        if(readyQueue->length==0) {
            printf("empty Queue\n");
            continue;
        }
        else if(ReadyQHead->parentTid==pthread_self()){
            Thread * head=  ReadyQHead;
            dequeue(readyQueue);
            __thread_to_run(head);
            printf("실행중... \n5에서 10초 가량의 부팅 시간이 소요됩니다\n");
            continue;
        }else if(ReadyQHead->status==THREAD_STATUS_ZOMBIE){
            dequeue(readyQueue);
            continue;
        }
        if(threadCur!=NULL){
            pthread_mutex_lock(&mainThreadMu);

            __ContextSwitch(threadCur, ReadyQHead);
            Thread* threadToCycle=threadCur;

            threadCur=ReadyQHead;
            dequeue(readyQueue);
            enqueue(readyQueue, threadToCycle);
            pthread_mutex_unlock(&mainThreadMu);


        }else{
            pthread_mutex_lock(&mainThreadMu);

            __ContextSwitch(threadCur, ReadyQHead);
            threadCur=ReadyQHead;

            dequeue(readyQueue);
            pthread_mutex_unlock(&mainThreadMu);


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
        pCurThread->bRunnable=false;
        pCurThread->status=THREAD_STATUS_READY;
        pthread_kill(pCurThread->tid,SIGUSR1);
    }
}

