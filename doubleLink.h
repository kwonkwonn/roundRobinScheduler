#ifndef ROUNDROBIN_DOUBLELINK_H
#define ROUNDROBIN_DOUBLELINK_H
#include "Thread.h"




typedef struct doublyLinked{
    int length;
    Thread ** header;
    Thread ** trailer;
}doublyLinkedList;



extern doublyLinkedList* waitingQueue;
extern doublyLinkedList* readyQueue;

void enqueue(doublyLinkedList* queue,Thread* thread);

void dequeue(doublyLinkedList* queue);
Thread * pullOneNode(doublyLinkedList* queue, Thread* threadToPull);




#endif //ROUNDROBIN_DOUBLELINK_H
