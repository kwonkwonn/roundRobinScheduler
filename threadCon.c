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

Thread* threadCur=NULL;


void __thread_to_ready2(Thread * pTh){
    pTh->status=THREAD_STATUS_READY;

    pthread_mutex_lock(&(pTh->readyMutex));
    while (pTh->bRunnable == false || pTh->status==THREAD_STATUS_BLOCKED)
        pthread_cond_wait(&(pTh->readyCond), &(pTh->readyMutex));
    pthread_mutex_unlock(&(pTh->readyMutex));}


void __thread_to_ready(int sigNo){
    Thread* pTh;
    pTh = __getThread(pthread_self(),readyQueue);

    pthread_mutex_lock(&(pTh->readyMutex));
        while (pTh->bRunnable == false || pTh->status==THREAD_STATUS_BLOCKED)
            pthread_cond_wait(&(pTh->readyCond), &(pTh->readyMutex));
    pthread_mutex_unlock(&(pTh->readyMutex));
}

void __thread_to_join(Thread * threadNow, Thread* threadParent){
    pthread_mutex_lock(&(threadParent->zombieMutex));
    while(threadNow->bZombie== true)
        pthread_cond_wait(&(threadNow->zombieCond),&(threadParent->zombieMutex));
    pthread_mutex_unlock(&(threadParent->zombieMutex));
}

void __thread_to_zombie(Thread* threadToDie){

    pthread_mutex_lock(&(threadToDie->zombieMutex));
        threadToDie->bZombie=false;
        threadToDie->status=THREAD_STATUS_ZOMBIE;
        pthread_cond_signal(&(threadToDie->zombieCond));
    pthread_mutex_unlock(&(threadToDie->zombieMutex));
}




Thread * __getThread(thread_t tid,doublyLinkedList * queue) {
    Thread *threadIter = *(queue->header);
    if(threadCur!=NULL||threadCur->tid==tid){
        threadIter=threadCur;
    }
    for (int i = 0; i < queue->length; i++) {
        if (threadIter->tid == tid) {
            return threadIter;
        } else {
            threadIter = threadIter->pPrev;
        }

    }
    return threadIter;
}

void __thread_to_run(Thread* pTh)
{
    pthread_mutex_lock(&(pTh->readyMutex));
        pTh->status=THREAD_STATUS_RUN;
        pTh->bRunnable=true;
    pthread_cond_signal(&(pTh->readyCond));
    pthread_mutex_unlock(&(pTh->readyMutex));
}


void * __wrapperFunction(void * arg) {
    void *ret;
    WrapperArg *pArg = (WrapperArg *) arg;
    pArg->pThread->tid=pthread_self();
    Thread *pTh = pArg->pThread;
    __thread_to_ready2(pTh);
    ret = (pArg->funcPtr)(pArg->funcArg);
    return ret;
}