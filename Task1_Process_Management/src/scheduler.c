#include <stdio.h>
#include <unistd.h>

#include "../include/scheduler.h"
#include "../include/thread_manager.h"

/*
 * Simple Round Robin Scheduler Simulation
 * This does NOT control real CPU scheduling.
 * It demonstrates the scheduling concept.
 */

void round_robin_scheduler()
{
    printf("\n=====================================\n");
    printf(" Round Robin Scheduler Simulation\n");
    printf("=====================================\n\n");

    const int time_quantum = 1;

    for (int round = 1; round <= 5; round++)
    {
        printf("----- Round %d -----\n", round);

        for (int process = 1; process <= NUM_THREADS; process++)
        {
            printf("CPU -> Thread %d (Time Quantum = %d second)\n",
                   process,
                   time_quantum);

            sleep(time_quantum);
        }

        printf("\n");
    }

    printf("All scheduling rounds completed.\n\n");
}
