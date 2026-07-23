#include <stdio.h>

#include "../include/thread_manager.h"
#include "../include/scheduler.h"

int main()
{
    printf("=====================================\n");
    printf(" Operating Systems Coursework\n");
    printf(" Task 1: Process Management\n");
    printf("=====================================\n\n");

    printf("Creating worker threads...\n\n");

    create_threads();

    printf("\nAll worker threads have finished.\n");

    printf("\nFinal Shared Counter = %d\n", shared_counter);

    printf("\nStarting Round Robin Scheduler Simulation...\n");

    round_robin_scheduler();

    printf("Program completed successfully.\n");

    return 0;
}
