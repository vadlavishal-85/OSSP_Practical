#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE (100 * 1024 * 1024)

int main(void)
{
    char *memory = malloc(SIZE);

    if (memory == NULL)
    {
        perror("malloc");
        return 1;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        memory[i] = 1;
    }

    printf("Parent PID: %d\n", getpid());
    printf("Memory initialized: 100 MB\n");

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        free(memory);
        return 1;
    }

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());

        for (size_t i = 0; i < SIZE; i += 4096)
        {
            memory[i] = 2;
        }

        printf("Child modified memory.\n");
        sleep(30);

        free(memory);
        return 0;
    }

    printf("Parent waiting for child...\n");
    sleep(30);

    wait(NULL);

    free(memory);
    return 0;
}
