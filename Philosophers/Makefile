NAME = philo
NAME_BONUS = philo_bonus

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIRECTORY)
INCLUDES_BONUS = -I$(HEADERS_DIRECTORY)

HEADERS_LIST = philo.h
HEADERS_DIRECTORY = ./includes/
HEADERS_DIRECTORY_BONUS = ./bonus/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))
HEADERS_BONUS = $(addprefix $(HEADERS_DIRECTORY_BONUS), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = philo.c utils.c initialization.c philo_talk.c ft_putnbr.c ft_itoa.c ft_strjoin.c times.c philo_check.c
SOURCES_DIRECTORY_BONUS = ./bonus/
SOURCES_LIST_BONUS = philo.c utils.c initialization.c times.c philo_check.c ft_itoa.c ft_strjoin.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_BONUS = $(addprefix $(SOURCES_DIRECTORY_BONUS), $(SOURCES_LIST_BONUS))

OBJECTS_DIRECTORY = objects/
OBJECTS_DIRECTORY_BONUS = objects_bonus/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_BONUS = $(patsubst %.c, %.o, $(SOURCES_LIST_BONUS))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_BONUS	= $(addprefix $(OBJECTS_DIRECTORY_BONUS), $(OBJECTS_LIST_BONUS))

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
	@rm -rf $(OBJECTS_DIRECTORY_BONUS)
	@echo "$(NAME_BONUS): $(RED)$(OBJECTS_DIRECTORY_BONUS) was deleted$(RESET)"
	@echo "$(NAME_BONUS): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@rm -f $(NAME_BONUS)
	@echo "$(NAME_BONUS): $(RED)$(NAME_BONUS) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_DIRECTORY_BONUS) $(OBJECTS_BONUS)
	@$(CC) $(FLAGS) $(INCLUDES_BONUS) $(OBJECTS_BONUS) -o $(NAME_BONUS)
	@echo "\n$(NAME_BONUS): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was created$(RESET)"

$(OBJECTS_DIRECTORY_BONUS):
	@mkdir -p $(OBJECTS_DIRECTORY_BONUS)
	@echo "$(NAME_BONUS): $(GREEN)$(OBJECTS_DIRECTORY_BONUS) was created$(RESET)"

$(OBJECTS_DIRECTORY_BONUS)%.o : $(SOURCES_DIRECTORY_BONUS)%.c $(HEADERS_BONUS)
	@$(CC) $(FLAGS) -c $(INCLUDES_BONUS) $< -o $@
	@echo "$(GREEN).$(RESET)\c"