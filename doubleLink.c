#include <stdio.h>
#include <stdlib.h>
#include "doubleLink.h"
#include "Thread.h"


 doublyLinkedList* waitingQueue;
 doublyLinkedList* readyQueue;




void enqueue(doublyLinkedList* queue,Thread* thread){
    // waitingQ 인지 readyQ인지 구분 없이 사용할 수 있도록 더블 포인터 사용
    if(queue->length==0){
        (*(queue->header))=thread;
        (*(queue->trailer))=thread;

    }else{
        (*(queue->trailer))->pPrev=thread;
        thread->pNext= (*(queue->trailer));
        (*(queue->trailer))=thread;
    }
    queue->length++;
}

void dequeue(doublyLinkedList* queue){
    pthread_mutex_lock(&QconMutex);

//    Thread * headerPointer= (*(queue->header));
    if(queue->length<=0){
        perror("trying to dequeue empty queue");
    }else if(queue->length==1){
        (*(queue->header))=NULL;
        (*(queue->trailer))=NULL;
    }
    else{
        (*(queue->header))=(*(queue->header))->pPrev;
        (*(queue->header))->pNext=NULL;
    }
    queue->length --;

    pthread_mutex_unlock(&QconMutex);

}
