#include <stdio.h>
#include <stdlib.h>


typedef struct MMallocReference {
    void *ptr;
    int references;
    struct MMallocReference *next;
} MMallocReference;


void *
mmalloc(int size)
{
    void *new = malloc(size);
    MMallocReference *a = malloc(sizeof(MMallocReference));
    a->ptr = new;
    a->references += 1;
    a->next = NULL;
    return malloc(size);
}

int
main(int argc, char *argv[])
{
    MMallocReference *HEAD = malloc(sizeof(MMallocReference));
    MMallocReference *a = mmalloc(sizeof(MMallocReference));
    free(a);
    free(HEAD);
    return 0;
}
