#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include <pthread.h>

/* Number of worker threads */
#define NUM_THREADS 3

/* Shared counter accessed by all threads */
extern int shared_counter;

/* Mutex to protect shared data */
extern pthread_mutex_t mutex;

/* Thread function */
void *thread_function(void *arg);

/* Create and execute all worker threads */
void create_threads();

#endif
