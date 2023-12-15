#include "Thread.h"
#include "Init.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <stdlib.h>
#include <stdio.h>

Thread*     ReadyQHead = NULL;
Thread*     ReadyQTail = NULL;

Thread*     WaitQHead = NULL;
Thread*     WaitQTail = NULL;

int 	thread_create(thread_t *thread, thread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
    Thread*  TCB= (Thread *)malloc(sizeof (Thread));
    TCB->status= THREAD_STATUS_READY;
    TCB->pExitCode=NULL;
    TCB->readyCond= cond;
    TCB->readyMutex=mutex;
    TCB->bZombie=0;
    TCB->zombieMutex;
    TCB->parentTid;
    TCB->pPrev;
    TCB->pNext;

    if (pthread_create(thread, attr, start_routine, arg) > 0)
    {
        printf("thread create error:");
        exit(0);
    }
    pthread_join(*thread, NULL);

    enqueue(readyQueue,TCB);

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

}	
