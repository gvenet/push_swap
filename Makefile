SRC_DIR	:= srcs/
SRC_DIR_PS := $(SRC_DIR)push_swap
SRC_DIR_CH := $(SRC_DIR)checker
SRC_DIR_CM := $(SRC_DIR)common

INC_DIR	:= inc/
INC_PS	:= $(INC_DIR)push_swap.h
INC_CH	:= $(INC_DIR)checker.h
INC_CM	:= $(INC_DIR)common.h

OBJ_DIR	:= obj/
OBJ_DIR_PS := $(OBJ_DIR)push_swap
OBJ_DIR_CH := $(OBJ_DIR)checker
OBJ_DIR_CM := $(OBJ_DIR)common

BIN_DIR	:= bin/
NAME_PS	:= $(BIN_DIR)push_swap
NAME_CH := $(BIN_DIR)checker

SRC_PS	:= $(wildcard $(SRC_DIR_PS)*.c) $(wildcard $(SRC_DIR_PS)*/*.c)
SRC_CH	:= $(wildcard $(SRC_DIR_CH)*.c) $(wildcard $(SRC_DIR_CH)*/*.c)
SRC_CM	:= $(wildcard $(SRC_DIR_CM)*.c) $(wildcard $(SRC_DIR_CM)*/*.c)

OBJ_PS	:= $(SRC_PS:$(SRC_DIR_PS)%.c=$(OBJ_DIR_PS)%.o)
OBJ_CH	:= $(SRC_CH:$(SRC_DIR_CH)%.c=$(OBJ_DIR_CH)%.o)
OBJ_CM	:= $(SRC_CM:$(SRC_DIR_CM)%.c=$(OBJ_DIR_CM)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iinc -Ilibft/inc/
LDFLAGS	:= -Llibft/bin -lft 


.PHONY: all clean fclean re
.SILENT:

all: lib $(NAME_PS) $(NAME_CH)
	echo "push_swap \033[32mrdy 2 use\033[0m"
	echo "--------------------------------------------"
	echo ""

lib:
	make -C libft


# -----------------------------------------------------
$(NAME_PS):  $(OBJ_PS) $(OBJ_CM) libft/bin/libft.a | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@
	echo "$@ (exec) \033[32mcreated\033[0m"
	echo "--------------------------------------------"

$(OBJ_DIR_PS)%.o: $(SRC_DIR_PS)%.c $(INC_PS) | $(OBJ_DIR_PS)
	mkdir -p $(dir $(OBJ_DIR))
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	echo "$@ \033[32mcreated\033[0m"

# -----------------------------------------------------
$(NAME_CH):  $(OBJ_CH) $(OBJ_CM) libft/bin/libft.a | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@
	echo "$@ (exec) \033[32mcreated\033[0m"
	echo "--------------------------------------------"

$(OBJ_DIR_CH)%.o: $(SRC_DIR_CH)%.c $(INC_CH)| $(OBJ_DIR_CH)
	mkdir -p $(dir $(OBJ_DIR))
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	echo "$@ \033[32mcreated\033[0m"

# -----------------------------------------------------
$(OBJ_DIR_CM)%.o: $(SRC_DIR_CM)%.c $(INC_CM)| $(OBJ_DIR_CM)
	mkdir -p $(dir $(OBJ_DIR))
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	echo "$@ \033[32mcreated\033[0m"

# -----------------------------------------------------
$(BIN_DIR) $(OBJ_DIR_CH) $(OBJ_DIR_PS) $(OBJ_DIR_CM):
	mkdir -p $@
	echo "$@ \033[32mdir created\033[0m"

clean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"
	$(RM) libmlx.dylib
	make -C libft clean

fclean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"
	$(RM) libmlx.dylib
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"
	make -C libft fclean

fclean_re:
	make -C libft re
	$(RM) -rf $(OBJ_DIR)/*
	echo "$(OBJ_DIR)*.o \033[31mdeleted\033[0m"
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"
	echo "--------------------------------------------"

re: fclean_re all
