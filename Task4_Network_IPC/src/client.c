#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>

#include "../include/socket_manager.h"

void start_client()
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    char username[50];
    char password[50];
    char message[BUFFER_SIZE];
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        printf("Socket creation failed.\n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sock,
                (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        printf("Connection failed.\n");
        close(sock);
        return;
    }

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    snprintf(message,
             BUFFER_SIZE,
             "%s:%s",
             username,
             password);

    send(sock,
         message,
         strlen(message),
         0);

    read(sock,
         buffer,
         BUFFER_SIZE);

    printf("\nServer Response: %s\n",
           buffer);

    close(sock);
}
