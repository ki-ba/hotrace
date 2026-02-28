NAME    := hotrace
CC      := cc
CFLAGS  := 

SRC_DIR := src/
OBJ_DIR := .obj/
INC_DIR := include/

SRC     := $(addprefix $(SRC_DIR), \
               main.c \
           )

OBJS    := $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADERS := -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
