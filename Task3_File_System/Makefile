CC = gcc
CFLAGS = -Wall -Wextra
TARGET = task3

SRC = src/main.c \
      src/file_manager.c \
      src/permissions.c

all:
	gcc $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
