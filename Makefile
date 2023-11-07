CC = cc # compiler
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C ./libft bonus
	$(CC) $(OBJS) -L./libft -lft -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re