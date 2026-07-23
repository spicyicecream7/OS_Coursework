#include <stdio.h>

#include "../include/socket_manager.h"
#include "../include/ipc_manager.h"

int main()
{
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" Operating Systems Coursework\n");
        printf(" Task 4: Networking and IPC\n");
        printf("=====================================\n");

        printf("1. Start Server\n");
        printf("2. Start Client\n");
        printf("3. Pipe IPC Demonstration\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                start_server();
                break;

            case 2:
                start_client();
                break;

            case 3:
                pipe_demo();
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
