#include <stdio.h>

#include "../include/memory_manager.h"

/* Display current memory frames */
void display_frames(int frames[], int frame_count)
{
    printf("Frames: ");

    for (int i = 0; i < frame_count; i++)
    {
        if (frames[i] == -1)
            printf("[ ] ");
        else
            printf("[%d] ", frames[i]);
    }

    printf("\n");
}

/* Calculate hit ratio */
double calculate_hit_ratio(int hits, int total_references)
{
    return (double)hits / total_references;
}

/* Calculate miss ratio */
double calculate_miss_ratio(int faults, int total_references)
{
    return (double)faults / total_references;
}
