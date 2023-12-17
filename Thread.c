#include "Thread.h"
#include "Init.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
Thread*     ReadyQHead = NULL;
Thread*     ReadyQTail = NULL;

Thread*     WaitQHead = NULL;
Thread*     WaitQTail = NULL;

pthread_mutex_t mutex;
pthread_cond_t readyCond;



Thread * __getThread(thread_t tid){
    Thread* threadIter= ReadyQHead;
    for(int i=0; i<readyQueue->length; i++){
        if(threadIter->tid==tid){
            printf("%lud", threadIter->tid);
            return threadIter;
        }else{
            threadIter=threadIter->pPrev;
        }
    }

}

void __thread_to_ready(int signo){
    Thread* pTh;

    pTh = __getThread(pthread_self());
    pthread_mutex_lock(&(pTh->readyMutex));
    while (pTh->bRunnable == false)
        pthread_cond_wait(&(pTh->readyCond), &(pTh->readyMutex));
    pthread_mutex_unlock(&(pTh->readyMutex));
}




int 	thread_create(thread_t *thread, thread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&readyCond,NULL);

    Thread* TCB= (Thread *)malloc(sizeof (Thread));
    TCB->status= THREAD_STATUS_READY;
    TCB->pExitCode=NULL;
    TCB->tid= (pthread_t)thread;
    TCB->readyCond=readyCond;
    TCB->readyMutex=mutex;
    TCB->bRunnable=false;
    TCB->bZombie=false;
    TCB->zombieCond;
    TCB->zombieMutex;
    TCB->parentTid=thread_self();
    TCB->pPrev;
    TCB->pNext;


    pthread_mutex_lock(&mutex);
//    __getThread(TCB->tid);

    if (pthread_create(thread, attr, start_routine, arg) > 0)
    {
        perror("thread create error:");
        exit(0);
    }
    enqueue(readyQueue,TCB);


    pthread_mutex_unlock(&mutex);

    pthread_join(*thread, NULL);


    pthread_attr_destroy(&mutex);
    pthread_cond_destroy(&readyCond);

    return 0;
}


int 	thread_join(thread_t thread, void **retval)
{
    return 0;

}


int 	thread_suspend(thread_t tid)
{
    return 0;

}


int	thread_resume(thread_t tid)
{
    return 0;

}




thread_t	thread_self()
{
    return pthread_self();
}	

