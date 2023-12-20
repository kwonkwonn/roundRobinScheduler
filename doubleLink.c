#include <stdio.h>
#include <stdlib.h>
#include "doubleLink.h"
#include "Thread.h"
#include <threadCon.h>

 doublyLinkedList* waitingQueue;
 doublyLinkedList* readyQueue;

void enqueue(doublyLinkedList* queue,Thread* thread){
    // waitingQ 인지 readyQ인지 구분 없이 사용할 수 있도록 더블 포인터 사용
    pthread_mutex_lock(&mainThreadMu);
    if(queue->length==0){
        (*(queue->header))=thread;
        (*(queue->trailer))=thread;

    }else{
        (*(queue->trailer))->pPrev=thread;
        thread->pNext= (*(queue->trailer));
        (*(queue->trailer))=thread;
    }
    queue->length++;
    pthread_mutex_unlock(&mainThreadMu);

}

void dequeue(doublyLinkedList* queue){
    pthread_mutex_lock(&mainThreadMu);

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
    pthread_mutex_unlock(&mainThreadMu);

}

Thread * pullOneNode(doublyLinkedList* queue, thread_t tid){
    Thread * threatToPull= __getThread(tid,queue);
    pthread_mutex_lock(&mainThreadMu);
    if(threatToPull->pPrev!= NULL && threatToPull->pNext!= NULL){
     // 큐 한 가운데 있는 노드를 제거할 때
        threatToPull->pPrev->pNext= threatToPull->pNext;
        threatToPull->pNext->pPrev= threatToPull->pPrev;
        threatToPull->pPrev=NULL;
        threatToPull->pNext=NULL;
        queue->length--;
    }else if(threatToPull->pNext=NULL ){
        // header에 있거나 길이가 1인 큐를 제거할 때
        dequeue(queue);
    }else if(threatToPull->pPrev=NULL){
        //trailer에 있는 노드를 제거할 때
        threatToPull->pNext->pPrev=NULL;
        threatToPull->pNext=NULL;
        queue->length --;
    }
    return threatToPull;

    pthread_mutex_unlock(&mainThreadMu);
}