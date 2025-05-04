NAME = push_swap
INC_DIR = includes
SRC_DIR = src
BON_DIR = bonus
BONUS = checker

SRC =  $(SRC_DIR)/butterfly.c  $(SRC_DIR)/butterfly1.c  $(SRC_DIR)/functions.c \
		$(SRC_DIR)/functions1.c  $(SRC_DIR)/main.c  $(SRC_DIR)/operations.c \
		$(SRC_DIR)/operations1.c  $(SRC_DIR)/sorting.c  $(SRC_DIR)/split.c \
		$(SRC_DIR)/validation.c

BSRC =  $(SRC_DIR)/get_next_line.c  $(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/butterfly.c  $(SRC_DIR)/butterfly1.c  $(SRC_DIR)/functions.c \
		$(SRC_DIR)/functions1.c  $(SRC_DIR)/main.c  $(SRC_DIR)/operations.c \
		$(SRC_DIR)/operations1.c  $(SRC_DIR)/sorting.c  $(SRC_DIR)/split.c \
		$(SRC_DIR)/validation.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)  -fsanitize=address -g3

RM = rm -f

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(BSRC) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(BSRC) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus