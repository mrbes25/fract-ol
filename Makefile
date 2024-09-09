# Executable Names
FRACTOL_NAME = fractol

# Source Files
FRACTOL_SRC = $(wildcard srcs/*.c)

# Object Files
FRACTOL_OBJ = ${FRACTOL_SRC:.c=.o}

# Library Settings
LIBDIR = my_lib
LIBNAME = ft_ext
LIBA = lib${LIBNAME}.a
LIB_INC = -I${LIBDIR}

# MiniLibX Settings
MLX_DIR = minilibX
MLX_LIB = ${MLX_DIR}/libmlx.a
MLX_INC = -I${MLX_DIR}
MLX_FLAGS = -lm -lz -lGL -lX11

# Compiler + Flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror ${LIB_INC} ${MLX_INC}

# Default rule for .c to .o conversion
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# Default target
all: ${LIBDIR}/${LIBA} ${MLX_LIB} ${FRACTOL_NAME}

# Build the my_lib library
${LIBDIR}/${LIBA}:
	${MAKE} -C ${LIBDIR}

# Build the MiniLibX library
${MLX_LIB}:
	${MAKE} -C ${MLX_DIR}

# Build the fractol executable
${FRACTOL_NAME}: ${FRACTOL_OBJ} ${LIBDIR}/${LIBA} ${MLX_LIB}
	${CC} ${CFLAGS} -o ${FRACTOL_NAME} ${FRACTOL_OBJ} -L${LIBDIR} -l${LIBNAME} -L${MLX_DIR} -lmlx ${MLX_FLAGS}

# Clean the object files
clean:
	${RM} ${FRACTOL_OBJ}
	${MAKE} -C ${LIBDIR} clean
	${MAKE} -C ${MLX_DIR} clean

# Clean everything
fclean: clean
	${RM} ${FRACTOL_NAME}

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
