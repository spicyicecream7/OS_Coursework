CC = gcc
CFLAGS = -Wall -Wextra
TARGET = task2

SRC = src/main.c \
      src/memory_manager.c \
      src/page_replacement.c

all:
	gcc $(CFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
