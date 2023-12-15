#include "Init.h"
#include <stdio.h>
#include "doubleLink.h"

void Init(void){
    readyQueue=newQueue();
    waitingQueue=newQueue();
}
