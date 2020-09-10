#ifndef __MMALLOC_H
#define __MMALLOC_H

#include <stdlib.h>

struct MMallocReference;

void *mmalloc(int size);
void mmalloc_free_all();

struct MMallocReference *MMALLOC_HEAD;
struct MMallocReference *MMALLOC_CURSOR;

#endif /* ifndef __MMALLOC_H */
