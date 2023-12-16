#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <unistd.h>
#include <stdio.h>


void __thread_to_run(Thread* pTh)
{
    pthread_mutex_lock(&(pTh->readyMutex));
    pTh->readyMutex = TRUE;
    pthread_cond_signal(&(pTh->readyCond));
    pthread_mutex_unlock(&(pTh->readyMutex));
}


void __thread_to_ready(int signo){
    Thread* pTh;

    pTh = __getThread(pthread_self());
    pthread_mutex_lock(&(pTh->readyMutex));
    while (pTh->bRunable == FALSE)
        pthread_cond_wait(&(pTh->readyCond), &(pTh->readyMutex));
    pthread_mutex_unlock(&(pTh->readyMutex));
}