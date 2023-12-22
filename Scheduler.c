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

    while(1){
        sleep(TIMESLICE);

        if(readyQueue->length==0) {
            continue;
}
//        else if(ReadyQHead->status==THREAD_STATUS_ZOMBIE){
//            dequeue(readyQueue);
//            continue;
//        }
        __ContextSwitch(threadCur, ReadyQHead);
    }
    return 0;
}

void  __ContextSwitch(Thread* pCurThread, Thread* pNewThread)
{
    pthread_mutex_lock(&mainThreadMu);

    if(pCurThread==NULL){
        __thread_to_run(pNewThread);
        threadCur=pNewThread;
        dequeue(readyQueue);
    }else{
        __thread_to_run(pNewThread);
        enqueue(readyQueue, pCurThread);
        threadCur=ReadyQHead;
        dequeue(readyQueue);

        pCurThread->bRunnable=false;
        pCurThread->status=THREAD_STATUS_READY;
        pthread_kill(pCurThread->tid,SIGUSR1);
    }
    pthread_mutex_unlock(&mainThreadMu);

}

