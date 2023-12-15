CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f

SRC_DIR = src
OBJ_DIR = objs

SRCS = $(addprefix $(SRC_DIR)/,\
main.c \
solve.c \
utils_oper.c \
utils_parsing.c \
utils_sort.c \
utils_stack.c \
utils_stack_management.c)

B_SRCS = $(addprefix $(SRC_DIR)/,\
checker_bonus.c \
utils_oper.c \
utils_parsing.c \
utils_stack_management.c)

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
B_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(B_SRCS))

NAME = push_swap
B_NAME = checker

$(NAME): $(OBJ_DIR) $(OBJS)
	make -C ./libft all
	$(CC) $(OBJS) -L./libft -lft -o $(NAME)

$(B_NAME): $(OBJ_DIR) $(B_OBJS)
	make -C ./libft all
	$(CC) $(B_OBJS) -L./libft -lft -o $(B_NAME)

all: $(OBJ_DIR) $(NAME) $(B_NAME)

bonus: $(B_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re bonus