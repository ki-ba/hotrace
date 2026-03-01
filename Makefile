NAME = hotrace
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

OBJ_DIR := .obj/

SRCS = main.c hashmap.c hashmap_utils.c alloc_utils.c print_utils.c str_utils.c node.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
