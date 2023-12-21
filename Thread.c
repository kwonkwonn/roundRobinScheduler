#include "Thread.h"
#include "Init.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include "threadCon.h"

Thread*     ReadyQHead = NULL;
Thread*     ReadyQTail = NULL;

Thread*     WaitQHead = NULL;
Thread*     WaitQTail = NULL;

pthread_mutex_t mutex;
pthread_cond_t readyCond;




int 	thread_create(thread_t *thread, thread_attr_t *attr, void * (*start_routine)(void *), void *arg)
{
    Thread* TCB= (Thread *)malloc(sizeof(Thread));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&readyCond,NULL);

    TCB->status=THREAD_STATUS_READY;
    TCB->pExitCode=NULL;
    TCB->tid;
    TCB->readyCond=readyCond;
    TCB->readyMutex=mutex;
    TCB->bRunnable=false;
    TCB->bZombie=false;
    TCB->zombieCond;
    TCB->zombieMutex;
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
    enqueue(readyQueue,TCB);

    pthread_attr_destroy(&mutex);
    pthread_cond_destroy(&readyCond);
    // return 0;
}


int 	thread_join(thread_t thread, void **retval)
{
    Thread* threadNow = __getThread(thread, readyQueue);

    pthread_mutex_lock(&mainThreadMu);
    while(threadNow->status!= THREAD_STATUS_ZOMBIE)
        pthread_cond_wait(&mainThreadCon,&mainThreadMu);
    pthread_mutex_unlock(&mainThreadMu);
    return (int)*retval;
}


int thread_suspend(thread_t tid)
{

    Thread * threadSuspended= __getThread(tid, readyQueue);
    pthread_mutex_lock(&mainThreadMu);

    pullOneNode(readyQueue,threadSuspended);
    threadSuspended->status= THREAD_STATUS_BLOCKED;
    threadSuspended->bRunnable=false;
    enqueue(waitingQueue, threadSuspended);


    pthread_mutex_unlock(&mainThreadMu);


    return 0;
}


int	thread_resume(thread_t tid)
{
    Thread * threadToResume= pullOneNode(waitingQueue,tid);
    threadToResume->status=THREAD_STATUS_READY;
    threadToResume->bRunnable=true;
    enqueue(readyQueue, threadToResume);

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

    threadToDie->bRunnable=false;
    threadToDie->status=THREAD_STATUS_ZOMBIE;
    pthread_cond_signal(&mainThreadCon);
    return 0;
}