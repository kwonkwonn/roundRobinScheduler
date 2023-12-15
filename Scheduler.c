#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"
#include "doubleLink.h"
#include <unistd.h>
#include <stdio.h>

int		RunScheduler( void )
{
    while(1){
        Thread* newthread = readyQueue->header;
        dequeue(waitingQueue);
        thread_create(newthread,NULL,);
        sleep(TIMESLICE);

    }

    return 0;
}


void            	__ContextSwitch(Thread* pCurThread, Thread* pNewThread)
{


    
}

