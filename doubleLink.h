#ifndef ROUNDROBIN_DOUBLELINK_H
#define ROUNDROBIN_DOUBLELINK_H
#include "Thread.h"


//
//typedef struct Node{
//    int* data;
//    Thread nextN;
//    Thread preN;
//}node;

typedef struct doublyLinked{
    int length;
    Thread* header;
    Thread* trailer;
}doublyLinkedList;


void queueInit();


doublyLinkedList* newQueue();


extern doublyLinkedList* waitingQueue;
extern doublyLinkedList* readyQueue;

void enqueue(doublyLinkedList* queue,Thread* thread);

void dequeue(doublyLinkedList* queue);



#endif //ROUNDROBIN_DOUBLELINK_H
