CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = doubleLink.c \
       Init.c \
       main.c \
       Scheduler.c \
       Thread.c \
       threadCon.c \
       TestCase1.c \
       TestCase2.c

OBJS = $(SRCS:.c=.o)
HEADERS = doubleLink.h Init.h Scheduler.h Thread.h threadCon.h

TARGET = systemSoft

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
