NAME = push_swap
NAME_CHECKER = checker

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIRECTORY)

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_CHECKER_DIRECTORY = ./bonus/
SOURCES_LIST = case.c cases.c commands.c commands_2.c commands_3.c dor.c dor2.c index.c push_swap.c push_swaps.c utils.c str_input.c stack_create.c check.c error.c
SOURCES_CHECKER_LIST = commands.c commands_2.c commands_3.c check.c index.c stack_create.c str_input.c utils.c checker.c error.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_CHECKER_LIST = $(patsubst %.c, %.o, $(SOURCES_CHECKER_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_CHECKER	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_CHECKER_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@rm -f $(NAME_CHECKER)
	@echo "$(NAME_CHECKER): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

bonus: $(NAME) $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJECTS_DIRECTORY) $(OBJECTS_CHECKER)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS_CHECKER) -o $(NAME_CHECKER)
	@echo "\n$(NAME_CHECKER): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_CHECKER): $(GREEN)$(NAME_CHECKER) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_CHECKER_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"