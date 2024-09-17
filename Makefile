# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 09:37:36 by bschmid           #+#    #+#              #
#    Updated: 2024/09/17 10:05:48 by bschmid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Executable Name
NAME = fractol

# Compiler and CFlags
CC	=	gcc
CFlags	=	-Wall -Werror -Wextra
LIBS	=	-lXext -lX11 -lm
RM	=	rm -f

# Directories
LIB	=	./my_lib/my_lib.a
MLX	=	./minilibX/libmlx.a
INC	=	my_lib/ minilibX
SRC_DIR	=	src/
OBJ_DIR	=	obj/

# Source Files
SRC	=	compute.c \
		draw.c \
		events.c \
		inits.c \
		main.c \
		tools.c \

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

# Object files
OBJ	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules

all:	$(MLX) $(LIB) $(NAME)

$(NAME):	$(OBJ) $(MLX) $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIB) $(LIBS) -o $(NAME)

$(LIB):
	@make -sC ./my_lib

$(MLX):
	@make -sC ./minilibX

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./minilibX
	@make clean -C ./my_lib

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(MLX)
	@$(RM) $(LIB)

re:	fclean all

# Phony targets represent actions not files
.PHONY: 				all clean fclean re
