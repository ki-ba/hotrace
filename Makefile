NAME = hotrace
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g

SRC_DIR := src/
OBJ_DIR := .obj/
INC_DIR := inc/

SRC     := $(addprefix $(SRC_DIR), \
               main.c \
           )

OBJS    := $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADERS := -I $(INC_DIR)

SRCS = main.c hashmap.c alloc_utils.c print_utils.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
