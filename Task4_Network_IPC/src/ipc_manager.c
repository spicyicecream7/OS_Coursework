#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/ipc_manager.h"

void pipe_demo()
{
    int fd[2];
    pid_t pid;

    char message[] = "Hello from Child Process!";
    char buffer[100];

    if (pipe(fd) == -1)
    {
        printf("Pipe creation failed.\n");
        return;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed.\n");
        return;
    }

    if (pid == 0)
    {
        /* Child Process */

        close(fd[0]);

        write(fd[1],
              message,
              strlen(message) + 1);

        close(fd[1]);

        exit(0);
    }
    else
    {
        /* Parent Process */

        close(fd[1]);

        read(fd[0],
             buffer,
             sizeof(buffer));

        printf("\nMessage received through pipe:\n");
        printf("%s\n", buffer);

        close(fd[0]);
    }
}

