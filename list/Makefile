# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Daniel Onwuka>

CC = gcc
CFLAGS = -Wall -g -std=c99
TARGET = list

$(TARGET): list.c main.c list.h
	$(CC) $(CFLAGS) list.c main.c -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run