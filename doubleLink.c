#include <stdio.h>
#include <stdlib.h>
#include "doubleLink.h"
#include "Thread.h"

 doublyLinkedList* waitingQueue;
 doublyLinkedList* readyQueue;





void enqueue(doublyLinkedList* queue,Thread* thread){
    Thread * trailerPointer= (*(queue->trailer));
    // waitingQ 인지 readyQ인지 구분 없이 사용할 수 있도록 더블 포인터 사용
    if(queue->length==0){
        (*(queue->header))=thread;
        (*(queue->trailer))=thread;

    }else{
        trailerPointer->pPrev=thread;
        thread->pNext= trailerPointer;
        trailerPointer=thread;
    }
    queue->length++;
    printf("%p\n", queue->trailer);
    printf("%d\n",queue->length);

}

void dequeue(doublyLinkedList* queue){
    Thread * headerPointer= (*(queue->header));
    if(queue->length<=0){
        perror("trying to dequeue empty queue");
    }else if(queue->length==1){
        (*(queue->header))=NULL;
        (*(queue->trailer))=NULL;
    }
    else{
        headerPointer=headerPointer->pPrev;
        headerPointer->pNext=NULL;
    }
    queue->length --;
    printf("%p\n", queue->header);
    printf("%d",queue->length);

}


//node* addNode(node* preNode,node* postNode,int* data){
//    node* instance= (node*) malloc(sizeof (node));
//    instance->data=data;
//    instance->preN=preNode;
//    instance->nextN=postNode;
//    return instance;
//}
