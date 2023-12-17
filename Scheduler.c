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


void __thread_to_run(Thread* pTh)
{
    pthread_mutex_lock(&(pTh->readyMutex));
    pTh->bRunnable=true;
    pthread_cond_signal(&(pTh->readyCond));
    pthread_mutex_unlock(&(pTh->readyMutex));
}



int		RunScheduler( void )
{
    int j=0;
    Thread* threadCur=NULL;
    while(1){
        j++;
        if(readyQueue->length==0) {
            printf("empty Queue");
        }else if(threadCur!=NULL){
            __ContextSwitch(threadCur, ReadyQHead);
            Thread* threadToCycle=threadCur;
            threadCur=ReadyQHead;
            dequeue(readyQueue);
            enqueue(readyQueue, threadToCycle);

        }else{
            __ContextSwitch(threadCur, ReadyQHead);
            threadCur=ReadyQHead;
            dequeue(readyQueue);


        }
        printf("cycling...%d번째 사이클 중.... pid %ld \n", j, threadCur->tid);
        fflush(stdout);
        sleep(TIMESLICE);
    }
    return 0;
}


void  __ContextSwitch(Thread* pCurThread, Thread* pNewThread)
{
    if(pCurThread==NULL){
        __thread_to_run(pNewThread);

    }else{
        pthread_kill(pCurThread->tid,SIGUSR1);
        __thread_to_run(pNewThread);
    }

    
}

