#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#define MAX_PAGES 100
#define MAX_FRAMES 10

/* Display memory frames */
void display_frames(int frames[], int frame_count);

/* Calculate hit ratio */
double calculate_hit_ratio(int hits, int total_references);

/* Calculate miss ratio */
double calculate_miss_ratio(int faults, int total_references);

#endif
