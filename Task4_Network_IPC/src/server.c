#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>

#include "../include/socket_manager.h"

void start_server()
{
    int server_fd;
    int client_socket;

    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char buffer[BUFFER_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        printf("Error creating socket.\n");
        return;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd,
             (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        printf("Bind failed.\n");
        close(server_fd);
        return;
    }

    if (listen(server_fd, 3) < 0)
    {
        printf("Listen failed.\n");
        close(server_fd);
        return;
    }

    printf("\n=====================================\n");
    printf(" Server started on port %d\n", PORT);
    printf(" Waiting for client...\n");
    printf("=====================================\n");

    client_socket = accept(server_fd,
                           (struct sockaddr *)&address,
                           (socklen_t *)&addrlen);

    if (client_socket < 0)
    {
        printf("Client connection failed.\n");
        close(server_fd);
        return;
    }

    read(client_socket,
         buffer,
         BUFFER_SIZE);

    printf("\nClient says: %s\n", buffer);

    /* Authentication */

    char username[50];
    char password[50];
    char reply[BUFFER_SIZE];

    sscanf(buffer,
           "%49[^:]:%49s",
           username,
           password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "password123") == 0)
    {
        strcpy(reply, "Authentication Successful");
    }
    else
    {
        strcpy(reply, "Authentication Failed");
    }

    send(client_socket,
         reply,
         strlen(reply),
         0);

    close(client_socket);
    close(server_fd);
}
