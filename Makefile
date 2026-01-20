NAME        = pipex

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

GNL_DIR     = get_next_line
GNL_SRC     = $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

SRC_DIR     = src
INC_DIR     = includes

SRC         = $(SRC_DIR)/pipex.c \
              $(SRC_DIR)/utils.c

BONUS_SRC   = $(SRC_DIR)/pipex_bonus.c \
              $(SRC_DIR)/utils_bonus.c \
              $(GNL_SRC)

OBJ         = $(SRC:.c=.o)
BONUS_OBJ   = $(BONUS_SRC:.c=.o)

INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
