#include <stdio.h>
#include <stdlib.h>
#include "doubleLink.h"
#include "Thread.h"
#include <threadCon.h>

 doublyLinkedList* waitingQueue;
 doublyLinkedList* readyQueue;

void enqueue(doublyLinkedList* queue,Thread* thread){
//    pthread_mutex_lock(&mainQMu);

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
//    pthread_mutex_unlock(&mainQMu);

}

void dequeue(doublyLinkedList* queue){
//    pthread_mutex_lock(&mainQMu);

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
//    pthread_mutex_unlock(&mainQMu);

}

Thread * pullOneNode(doublyLinkedList* queue, Thread* threadToPull){
    pthread_mutex_lock(&mainQMu);
    if(threadToPull==threadCur){
        threadCur=NULL;
    }else if(threadToPull->pPrev != NULL && threadToPull->pNext != NULL){
     // 큐 한 가운데 있는 노드를 제거할 때
        threadToPull->pPrev->pNext= threadToPull->pNext;
        threadToPull->pNext->pPrev= threadToPull->pPrev;
        threadToPull->pPrev=NULL;
        threadToPull->pNext=NULL;
        queue->length--;
    }else if(threadToPull->pNext == NULL ){
        // header에 있거나 길이가 1인 큐를 제거할 때
        dequeue(queue);

    }else if(threadToPull->pPrev == NULL){
        //trailer에 있는 노드를 제거할 때
        *(queue->trailer)=threadToPull->pNext;
        threadToPull->pNext->pPrev=NULL;
        threadToPull->pNext=NULL;
        queue->length --;
    }
    pthread_mutex_unlock(&mainQMu);
    return threadToPull;
}