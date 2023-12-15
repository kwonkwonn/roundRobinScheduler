#include <stdio.h>
#include <stdlib.h>
#include "Init.h"
#include "Thread.h"
#include "Scheduler.h"


void* MyTestCase(void* arg)
{
    // let's implement your testing code
    return NULL;
}


void main(int argc, char* argv[])
{
    int TcNum;
    thread_t tid1;

    if(argc != 2)
    {
        perror("Input TestCase Number!");
        exit(0);
    }

    Init();

    TcNum = atoi(argv[1]);

    switch(TcNum)
    {
        case 1:
            thread_create(&tid1, NULL, (void*)MyTestCase, 0);
            break;
/*
        case 2:
            thread_create(&tid2, NULL, (void*)TestCase2, 0);
            break;
        case 3:
            thread_create(&tid3, NULL, (void*)TestCase3, 0);
            break;
*/
    }

    RunScheduler();
    while(1){}
}