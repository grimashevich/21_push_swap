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
S_FLAGS := -fsanitize=address
				
SRC :=		main.c				functions_0.c		lst_manipulation.c	algov1.c		\
			rotate_count.c		rotate_count1.c		algov1_2.c			atoi_long.c		\
			lst_manipulation2.c	functions_1.c		functions_2.c		functions_3.c	\
			functions_4.c		functions_5.c		functions_6.c		functions_7.c

# SRC_B :=	bonus_main.c		functions_0.c		lst_manipulation.c	algov1.c		\
# 			rotate_count.c		rotate_count1.c		algov1_2.c			atoi_long.c		\
# 			lst_manipulation2.c	functions_1.c		functions_2.c		functions_3.c	\
# 			functions_4.c		functions_5.c		functions_6.c		functions_7.c

SRC_B :=	$(SRC:main.c=bonus_main.c)

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B := $(SRC_B:%.c=$(OBJ_DIR)/%.o)

DEP := $(OBJ:.o=.d)
DEP_B := $(OBJ_B:.o=.d)

.PHONY: all clean fclean re libft bonus

all:	libft $(NAME)
bonus:	libft $(NAME_B)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) $(S_FLAGS) -o $(NAME)

$(NAME_B): $(LIBFT_LIB) $(OBJ_B)
	$(CC) $(LDFLAGS) $(OBJ_B) $(LDLIBS) -fsanitize=address -o $(NAME_B)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(S_FLAGS) -c $< -o $@

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
