#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "../include/thread_manager.h"

/* Shared resource */
int shared_counter = 0;

/* Mutex initialization */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* Function executed by each thread */
void *thread_function(void *arg)
{
    int thread_id = *(int *)arg;

    for (int i = 0; i < 5; i++)
    {
        /* Lock before accessing shared resource */
        pthread_mutex_lock(&mutex);

        shared_counter++;

        printf("Thread %d | Counter = %d\n",
               thread_id,
               shared_counter);

        /* Unlock after critical section */
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

/* Create and manage all threads */
void create_threads()
{
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        ids[i] = i + 1;

        if (pthread_create(&threads[i],
                           NULL,
                           thread_function,
                           &ids[i]) != 0)
        {
            printf("Error creating thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    /* Wait for all threads to finish */

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
}
