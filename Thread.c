#include "Thread.h"
#include "Init.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include "threadCon.h"

Thread*     ReadyQHead = NULL;
Thread*     ReadyQTail = NULL;

Thread*     WaitQHead = NULL;
Thread*     WaitQTail = NULL;

pthread_mutex_t mutex;
pthread_cond_t readyCond;

pthread_mutex_t zombieMutex;
pthread_cond_t zombieCond;




int 	thread_create(thread_t *thread, thread_attr_t *attr, void * (*start_routine)(void *), void *arg)
{
    Thread* TCB= (Thread *)malloc(sizeof(Thread));
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&zombieMutex, NULL);
    pthread_cond_init(&readyCond,NULL);
    pthread_cond_init(&zombieCond,NULL);

    TCB->status=THREAD_STATUS_READY;
    TCB->pExitCode=NULL;
    TCB->tid;
    TCB->readyCond=readyCond;
    TCB->readyMutex=mutex;
    TCB->bRunnable=false;
    TCB->zombieCond= zombieCond;
    TCB->bZombie=true;
    TCB->zombieMutex= zombieMutex;
    TCB->parentTid=thread_self();
    TCB->pPrev;
    TCB->pNext;

    WrapperArg* wrapper= (WrapperArg*)malloc(sizeof(WrapperArg));
    wrapper->funcPtr=start_routine;
    wrapper->funcArg=arg;
    wrapper->pThread=TCB;

    signal(SIGUSR1,__thread_to_ready);

    if (pthread_create(thread, attr, &__wrapperFunction, wrapper) > 0)
    {
        perror("thread create error:");
        exit(0);
    }
//    pthread_mutex_lock(&mainThreadMu);

    enqueue(readyQueue,TCB);

//    pthread_mutex_unlock(&mainThreadMu);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&readyCond);
    pthread_mutex_destroy(&zombieMutex);
    pthread_cond_destroy(&zombieCond);
    // return 0;
}


int 	thread_join(thread_t thread, void **retval)
{
    sleep(1);
    pthread_mutex_lock(&mainThreadMu);
    Thread* threadParent = __getThread(pthread_self(), readyQueue);
    Thread* threadNow = __getThread(thread, readyQueue);

    threadParent->status=THREAD_STATUS_BLOCKED;
    //sleep
    pullOneNode(readyQueue,threadParent);
    enqueue(waitingQueue,threadParent);
    pthread_mutex_unlock(&mainThreadMu);
    __thread_to_join(threadNow, threadParent);
    enqueue(readyQueue,threadParent);

    pullOneNode(waitingQueue,threadParent);
    pullOneNode(readyQueue, threadNow);
    threadParent->status=THREAD_STATUS_READY;

    return (int)*retval;
}


int thread_suspend(thread_t tid)
{
    pthread_mutex_lock(&mainThreadMu);

    Thread * threadSuspended= __getThread(tid, readyQueue);

//    pullOneNode(readyQueue,*(readyQueue->header));
    pullOneNode(readyQueue,threadSuspended);
    enqueue(waitingQueue, threadSuspended);
    threadSuspended->status= THREAD_STATUS_BLOCKED;

    pthread_mutex_unlock(&mainThreadMu);


    return 0;
}


int	thread_resume(thread_t tid)
{
    pthread_mutex_lock(&mainThreadMu);

    Thread * threadToPull= __getThread(tid,waitingQueue);
    pullOneNode(waitingQueue,threadToPull);

    threadToPull->status=THREAD_STATUS_READY;

    enqueue(readyQueue, threadToPull);
    pthread_mutex_unlock(&mainThreadMu);

    return 0;
}

thread_t	thread_self()
{
//    thread_t  returnValue=__getThread(pthread_self())->tid;
return pthread_self();
}


int thread_exit(void* retval){
    Thread * threadToDie;
    threadToDie= __getThread(pthread_self(), readyQueue);
    __thread_to_zombie(threadToDie);

    return (int)retval;
}