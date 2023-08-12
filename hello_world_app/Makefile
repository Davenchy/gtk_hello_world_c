CC = gcc
LIBS = $(shell pkg-config --libs gtk4)
CFLAGS = $(shell pkg-config --cflags gtk4) -Wall -Wextra -Werror

NAME = hello_world_app
SRC = main.c

OBJS = $(SRC:%.c=%.o)

.PHONY: all clean

all: $(NAME)

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

$(NAME): $(OBJS)
	$(CC) -o $(@F) $(LIBS) $^

clean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
