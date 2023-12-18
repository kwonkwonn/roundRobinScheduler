
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



void __thread_to_ready2(Thread * pTh){
    pthread_mutex_lock(&(pTh->readyMutex));
    while (pTh->bRunnable == false)
        pthread_cond_wait(&(pTh->readyCond), &(pTh->readyMutex));
    pthread_mutex_unlock(&(pTh->readyMutex));}




void __thread_to_ready(int sigNo){
    Thread* pTh;
    pTh = __getThread(pthread_self());
    printf("%ld\n",pthread_self());
    pthread_mutex_lock(&(pTh->readyMutex));
        pTh->bRunnable = false;
        while (pTh->bRunnable == false)
            pthread_cond_wait(&(pTh->readyCond), &(pTh->readyMutex));
    pthread_mutex_unlock(&(pTh->readyMutex));
}


Thread * __getThread(thread_t tid){
    Thread* threadIter= ReadyQHead;
    for(int i=0; i<readyQueue->length; i++){
        if(threadIter->tid==tid){
            return threadIter;
        }else{
            threadIter=threadIter->pPrev;
        }
    }

    return threadIter;
}

void __thread_to_run(Thread* pTh)
{
    pthread_mutex_lock(&(pTh->readyMutex));
        pTh->bRunnable=true;
    pthread_cond_signal(&(pTh->readyCond));
    pthread_mutex_unlock(&(pTh->readyMutex));
}

void * __wrapperFunction(void * arg) {
    void *ret;
    WrapperArg *pArg = (WrapperArg *) arg;
//    printf("%p\n", pArg->funcPtr);
    pArg->pThread->tid=pthread_self();
    Thread *pTh = pArg->pThread;
    __thread_to_ready2(pTh);
    ret = (pArg->funcPtr)(pArg->funcArg);
    return ret;
}