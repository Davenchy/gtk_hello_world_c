NAME = gtk_app
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJ = $(SRC:%.c=%.o)
LDFLAGS = $(shell pkg-config --libs gtk4)
INCLUDES = $(shell pkg-config --cflags gtk4)

.PHONY: all rebuild clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

rebuild: fclean all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
