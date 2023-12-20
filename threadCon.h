#ifndef SYSTEMSOFT_THREADCON_H
#define SYSTEMSOFT_THREADCON_H



#include <pthread.h>
#include "Thread.h"

extern pthread_mutex_t mainThreadMu;
extern pthread_cond_t mainThreadCon;


void __thread_to_ready(int signo);

void __thread_to_ready2(Thread * pTh);

Thread * __getThread(thread_t tid, doublyLinkedList* queue);

void __thread_to_run(Thread* pTh);

void * __wrapperFunction(void * arg);


#endif //SYSTEMSOFT_THREADCON_H
