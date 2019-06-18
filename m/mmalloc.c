#include "mmalloc.h"

typedef struct MMallocReference {
    void *ptr;
    int references;
    struct MMallocReference *next;
} MMallocReference;

void *
mmalloc(int size)
{
    if (MMALLOC_HEAD == NULL) {
        MMALLOC_HEAD = malloc(sizeof(MMallocReference));
        MMALLOC_CURSOR = MMALLOC_HEAD;
    }
    void *new = malloc(size);
    MMallocReference *a = malloc(sizeof(MMallocReference));
    a->ptr = new;
    a->references += 1;
    a->next = NULL;
    MMALLOC_CURSOR->next = a;
    MMALLOC_CURSOR = a;
    return new;
}

void
mmalloc_free_all()
{
    if (MMALLOC_HEAD != NULL) {
        MMallocReference *previous;
        MMallocReference *current = MMALLOC_HEAD;
        while(current->next != NULL){
            previous = current;
            current = current->next;
            if (previous->ptr != NULL) {
                free(previous->ptr);
                previous->ptr = NULL;
            }
            free(previous);
            previous = NULL;
        }
        if (current->ptr != NULL) {
            free(current->ptr);
            current->ptr = NULL;
        }
        free(current);
        current = NULL;
    }
}

