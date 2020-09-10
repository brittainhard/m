#include "m.h"

int
main(int argc, char *argv[])
{
    int *p = mmalloc(sizeof(int));
    char *name = mmalloc(sizeof(char) * 1024);
    mmalloc_free_all();
    return 0;
}
