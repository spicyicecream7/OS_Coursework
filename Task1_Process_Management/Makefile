CC = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = task1

SRC = src/main.c \
      src/thread_manager.c \
      src/scheduler.c

all:
	gcc $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
