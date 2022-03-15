NAME = fractol

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lmlx\
	-L$(MINILIBX_DIRECTORY)\
	-framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(MINILIBX_HEADERS)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.dylib
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fractol.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = fractol.c	init.c	mandelbrot.c	draw.c	hooks.c	julia.c	fractals_transformations.c	shift_color.c	ft_math.c	colors.c	swap_color.c	utils.c	burning_ship.c	celtic_mandelbar.c	\
		celtic_mandelbrot.c	celtic_perpendicular.c	perpendicular_buffalo.c	perpendicular_burning_ship.c	perpendicular_mandelbrot.c	choice_fractals.c	ft_itoa.c	draw_informations.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
