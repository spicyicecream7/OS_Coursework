#include <stdio.h>

#include "../include/page_replacement.h"
#include "../include/memory_manager.h"

/* FIFO Page Replacement */
void fifo_page_replacement(int pages[], int total_pages, int frame_count)
{
    int frames[MAX_FRAMES];
    int pointer = 0;
    int faults = 0;
    int hits = 0;

    for(int i=0;i<frame_count;i++)
        frames[i]=-1;

    printf("\n========== FIFO Page Replacement ==========\n");

    for(int i=0;i<total_pages;i++)
    {
        int found=0;

        for(int j=0;j<frame_count;j++)
        {
            if(frames[j]==pages[i])
            {
                found=1;
                hits++;
                break;
            }
        }

        if(!found)
        {
            frames[pointer]=pages[i];
            pointer=(pointer+1)%frame_count;
            faults++;
        }

        printf("Page %d -> ",pages[i]);
        display_frames(frames,frame_count);
    }

    printf("\nFIFO Statistics\n");
    printf("--------------------------\n");
    printf("Total References : %d\n",total_pages);
    printf("Hits             : %d\n",hits);
    printf("Page Faults      : %d\n",faults);
    printf("Hit Ratio        : %.2f\n",
            calculate_hit_ratio(hits,total_pages));
    printf("Miss Ratio       : %.2f\n",
            calculate_miss_ratio(faults,total_pages));
}


/* LRU Page Replacement */
void lru_page_replacement(int pages[], int total_pages, int frame_count)
{
    int frames[MAX_FRAMES];
    int recent[MAX_FRAMES];

    int hits=0;
    int faults=0;

    for(int i=0;i<frame_count;i++)
    {
        frames[i]=-1;
        recent[i]=0;
    }

    printf("\n========== LRU Page Replacement ==========\n");

    for(int i=0;i<total_pages;i++)
    {
        int found=-1;

        for(int j=0;j<frame_count;j++)
        {
            if(frames[j]==pages[i])
            {
                found=j;
                hits++;
                break;
            }
        }

        if(found!=-1)
        {
            recent[found]=i;
        }
        else
        {
            int replace=0;

            for(int j=1;j<frame_count;j++)
            {
                if(frames[j]==-1)
                {
                    replace=j;
                    break;
                }

                if(recent[j]<recent[replace])
                    replace=j;
            }

            frames[replace]=pages[i];
            recent[replace]=i;
            faults++;
        }

        printf("Page %d -> ",pages[i]);
        display_frames(frames,frame_count);
    }

    printf("\nLRU Statistics\n");
    printf("--------------------------\n");
    printf("Total References : %d\n",total_pages);
    printf("Hits             : %d\n",hits);
    printf("Page Faults      : %d\n",faults);
    printf("Hit Ratio        : %.2f\n",
            calculate_hit_ratio(hits,total_pages));
    printf("Miss Ratio       : %.2f\n",
            calculate_miss_ratio(faults,total_pages));
}
