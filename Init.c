#include "Init.h"
#include <stdio.h>
#include "doubleLink.h"
#include <stdlib.h>


void Init(void){

    readyQueue=(doublyLinkedList*) malloc(sizeof(doublyLinkedList));
    readyQueue->length=0;
    readyQueue->header= &ReadyQHead;
    readyQueue->trailer=&ReadyQTail;


    waitingQueue=(doublyLinkedList*) malloc(sizeof(doublyLinkedList));
    waitingQueue->length=0;
    waitingQueue->header= &WaitQHead;
    waitingQueue->trailer=&WaitQTail;

}
