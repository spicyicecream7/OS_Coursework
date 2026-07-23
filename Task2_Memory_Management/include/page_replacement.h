#ifndef PAGE_REPLACEMENT_H
#define PAGE_REPLACEMENT_H

/* FIFO Page Replacement */
void fifo_page_replacement(
    int pages[],
    int total_pages,
    int frame_count);

/* LRU Page Replacement */
void lru_page_replacement(
    int pages[],
    int total_pages,
    int frame_count);

#endif
