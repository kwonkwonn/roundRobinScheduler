#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <unistd.h>
#include <stdio.h>




int		RunScheduler( void )
{
    Thread* threadCur=NULL;
    while(1){
        if(readyQueue->length==0) {
            printf("empty Queue");
        }else{
            __ContextSwitch(threadCur, ReadyQHead);
            threadCur=ReadyQHead;
            dequeue(readyQueue);
        }
        sleep(TIMESLICE);
    }

    return 0;
}


void            	__ContextSwitch(Thread* pCurThread, Thread* pNewThread)
{
    if(pCurThread==NULL){

    }else{
        enqueue(readyQueue,pCurThread);


    }

    
}

