NAME = fractol

LIB_FOLDER = libft
LIB = $(LIB_FOLDER)/libft.a

LIBX_FOLDER = minilibx_macos
LIBX = $(LIBX_FOLDER)/libmlx.a

FLAGS = -Wall -Wextra -Werror
XFLAGS = -framework OpenGL -framework AppKit
OFLAGS = -O3
CC = gcc

SRCS_FOLDER = srcs
SRCS = $(SRCS_FOLDER)/main.c						\
		$(SRCS_FOLDER)/error.c						\
		$(SRCS_FOLDER)/struct.c						\
		$(SRCS_FOLDER)/graphic.c					\
		$(SRCS_FOLDER)/string.c						\
		$(SRCS_FOLDER)/events.c						\
		$(SRCS_FOLDER)/color.c						\
		$(SRCS_FOLDER)/mandelbrot.c					\
		$(SRCS_FOLDER)/julia.c						\
		$(SRCS_FOLDER)/ftoa.c

OBJS_FOLDER = objs
OBJS = $(SRCS:$(SRCS_FOLDER)/%.c=$(OBJS_FOLDER)/%.o)

INC_FOLDER = includes
INCLUDES = $(INC_FOLDER)/fractol.h

all: $(NAME)

$(NAME): $(LIBX) $(LIB) $(OBJS)
	@ $(CC) $(FLAGS) -I $(INCLUDES) $(OFLAGS) -o $@ $^ $(LIB) $(LIBX) $(XFLAGS)
	#@ $(CC) $(FLAGS) -I $(INCLUDES) -o $@ $^ $(LIB) $(LIBX) $(XFLAGS)
	@ echo "Compilation $(NAME) ..."\
	".................................................. \033[32m[OK]\033[0m"
	@ echo "Compilation $(LIBX_FOLDER) ..."\
	"........................................... \033[32m[OK]\033[0m"

$(LIB):
	@ make -C $(LIB_FOLDER)

$(LIBX):
	@ make -C $(LIBX_FOLDER)

$(OBJS_FOLDER):
	@ mkdir $(OBJS_FOLDER)

$(OBJS_FOLDER)/%.o: $(SRCS_FOLDER)/%.c $(INCLUDES) | $(OBJS_FOLDER) $(INCLUDES)
	@ $(CC) $(FLAGS) -I $(INCLUDES) $(OFLAGS) -o $@ -c $<
	#@ $(CC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@ rm -f $(OBJS)
	@ rm -rf $(OBJS_FOLDER)
	@ make -C $(LIB_FOLDER) clean
	@ make -C $(LIBX_FOLDER) clean
	@ echo "Delete *.o ($(NAME)) ..."\
	"................................................. \033[32m[OK]\033[0m"

fclean: clean
	@ rm -f $(NAME) $(LIB) $(LIBX)
	@ echo "Delete $(LIB) ...."\
	"................................................ \033[32m[OK]\033[0m"
	@ echo "Delete $(NAME) ......."\
	"................................................... \033[32m[OK]\033[0m"

re: fclean all
