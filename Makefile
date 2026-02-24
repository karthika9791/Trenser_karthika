CC = gcc
CFLAGS = -Wall -g -IstringManipulation
TARGET = string_operation
SRCS = main.c stringManipulation/stringManipulation.c
DEPS = stringManipulation/stringManipulation.h
OBJS = $(SRCS: .c=.o)
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

