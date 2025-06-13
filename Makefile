# **************************************************************************** #
#                                                                              #
#                               F R A C T O L                                  #
#                                                                              #
# **************************************************************************** #

### Paths ######################################################################
NAME        := fractol

SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include
LIBFT_DIR   := libft
PRINTF_DIR  := ft_printf
MLX_DIR     := minilibx-linux        # ← Linux 版なら minilibx-linux ではなくこの名前

### Compiler / Flags ###########################################################
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -O2
INCS    := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)


SRC     := $(wildcard $(SRC_DIR)/*.c)
OBJ     := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))


LIBFT_A     := $(LIBFT_DIR)/libft.a
PRINTF_A    := $(PRINTF_DIR)/libftprintf.a
MLX_A       := $(MLX_DIR)/libmlx.a           # Linux 版は libmlx.a が生成されます
MLX_LIBS    := -L$(MLX_DIR) -lmlx -lX11 -lXext -lm


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(PRINTF_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) $(MLX_LIBS) -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)


clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
