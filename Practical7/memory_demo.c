#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 10;
int global_uninit;

int main(void)
{
    static int static_var = 20;
    int stack_var = 30;

    int *heap_var = malloc(sizeof(int));

    if (heap_var == NULL)
    {
        perror("malloc");
        return 1;
    }

    *heap_var = 40;

    printf("===== Linux Process Address Space Demo =====\n");
    printf("PID            : %d\n", getpid());
    printf("Global address : %p\n", (void *)&global_var);
    printf("Static address : %p\n", (void *)&static_var);
    printf("BSS address    : %p\n", (void *)&global_uninit);
    printf("Heap address   : %p\n", (void *)heap_var);
    printf("Stack address  : %p\n", (void *)&stack_var);

    printf("\nProcess is running...\n");
    printf("Use another terminal to inspect /proc/%d/maps\n", getpid());

    while (1)
    {
        sleep(10);
    }

    free(heap_var);
    return 0;
}
