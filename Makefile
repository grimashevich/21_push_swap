NAME := push_swap
NAME_B := push_swap_bonus
CC := clang
OBJ_DIR := obj

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

CFLAGS := -Wall -Wextra -Werror -g
CPPFLAGS := -I$(LIBFT_DIR) -MMD
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft
				
SRC :=		main.c			functions_0.c

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
# OBJ_B := $(SRC_B:%.c=$(OBJ_DIR)/%.o)

DEP := $(OBJ:.o=.d)
DEP_B := $(OBJ_B:.o=.d)

.PHONY: all clean fclean re libft

all:	libft $(NAME)
# bonus:	libft $(NAME_B)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

# $(NAME_B): $(LIBFT_LIB) $(OBJ_B)
# 	$(CC) $(LDFLAGS) $(OBJ_B) $(LDLIBS) -fsanitize=address -o $(NAME_B)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS)  -c $< -o $@

$(LIBFT_LIB): libft

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

-include $(DEP) $(DEP_B)

clean:
	@rm -f $(OBJ) $(DEP) $(OBJ_B) $(DEP_B)
	make clean -C libft

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	make fclean -C libft

re: fclean all