#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *malloc_ptr;
    int *calloc_ptr;
    int *temp_ptr;

    /* malloc: allocate memory for 5 integers */
    malloc_ptr = (int *)malloc(5 * sizeof(int));

    if (malloc_ptr == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        malloc_ptr[i] = (i + 1) * 10;
    }

    printf("Values using malloc:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", malloc_ptr[i]);
    }
    printf("\n");

    /* calloc: allocate memory for 5 integers */
    calloc_ptr = (int *)calloc(5, sizeof(int));

    if (calloc_ptr == NULL)
    {
        printf("calloc failed\n");
        free(malloc_ptr);
        return 1;
    }

    printf("Values using calloc:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", calloc_ptr[i]);
    }
    printf("\n");

    /* realloc: increase malloc block from 5 to 10 integers */
    temp_ptr = (int *)realloc(malloc_ptr, 10 * sizeof(int));

    if (temp_ptr == NULL)
    {
        printf("realloc failed\n");
        free(malloc_ptr);
        free(calloc_ptr);
        return 1;
    }

    malloc_ptr = temp_ptr;

    for (int i = 5; i < 10; i++)
    {
        malloc_ptr[i] = (i + 1) * 10;
    }

    printf("Values after realloc:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", malloc_ptr[i]);
    }
    printf("\n");

    /* free allocated memory */
    free(malloc_ptr);
    malloc_ptr = NULL;

    free(calloc_ptr);
    calloc_ptr = NULL;

    printf("Memory successfully allocated and freed.\n");

    return 0;
}
