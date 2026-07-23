#include <stdio.h>

#include "../include/page_replacement.h"

int main()
{
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};

    int total_pages = sizeof(pages)/sizeof(pages[0]);

    int frame_count;

    printf("=====================================\n");
    printf(" Operating Systems Coursework\n");
    printf(" Task 2: Memory Management\n");
    printf("=====================================\n\n");

    printf("Enter number of page frames (3-10): ");
    scanf("%d",&frame_count);

    if(frame_count<3 || frame_count>10)
    {
        printf("Invalid frame count.\n");
        return 1;
    }

    fifo_page_replacement(
            pages,
            total_pages,
            frame_count);

    lru_page_replacement(
            pages,
            total_pages,
            frame_count);

    return 0;
}
