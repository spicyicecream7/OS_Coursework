CC = gcc

CFLAGS = -Wall -Wextra

TARGET = task4

SRC = src/main.c \
      src/server.c \
      src/client.c \
      src/socket_manager.c \
      src/ipc_manager.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
