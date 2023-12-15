#include <stdio.h>
#include <stdlib.h>
#include "doubleLink.h"
#include "Thread.h"

 doublyLinkedList* waitingQueue;
 doublyLinkedList* readyQueue;



doublyLinkedList* newQueue(){
    doublyLinkedList* instance= (doublyLinkedList*) malloc(sizeof(doublyLinkedList));
    instance->length=0;
    instance->header;
    instance->trailer;

    return instance;
}

void enqueue(doublyLinkedList* queue,Thread* thread){
    if(queue->length==0){
        queue->header= thread;
        queue->trailer= thread;

    }
    queue->trailer->pPrev=thread;
    queue->trailer=thread;
    queue->length++;
    printf("%p\n", queue->trailer);
    printf("%d\n",queue->length);

}

void dequeue(doublyLinkedList* queue){

    if(queue->length>0){
        Thread * nodeToDelete= queue->header;
        queue->header= queue-> header->pNext;

        queue->length--;
        printf("%p\n", queue->header);
        printf("%d",queue->length);
    }
    else{

    }

}


//node* addNode(node* preNode,node* postNode,int* data){
//    node* instance= (node*) malloc(sizeof (node));
//    instance->data=data;
//    instance->preN=preNode;
//    instance->nextN=postNode;
//    return instance;
//}
