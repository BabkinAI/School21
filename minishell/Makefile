NAME = minishell

CC = gcc
FLAGS = -Wall -Werror -Wextra
READLINE_FLAGS = -lreadline -L $(READLINE_DIRECTORY)
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(READLINE_HEADERS_DIRECTORY)

HEADERS_LIST = minishell.h
HEADERS_DIRECTORY = ./includes/
READLINE_HEADERS_DIRECTORY = ~/.brew/opt/readline/include
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
READLINE_DIRECTORY = ~/.brew/opt/readline/lib
SOURCES_LIST = 	minishell.c ft_strlen.c space_delete.c dollar_transformation.c dollar_transformation_2.c quotes.c quotes2.c commands_cut.c commands_cut_help.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c parse_redirects.c back_redirect.c dd_redirects.c default_redirect.c double_back.c redirect_check.c redirect_copy.c ft_strlen2.c redirects.c ft_strjoin.c\
				ft_strncmp.c echo.c cd.c pwd.c env.c export.c unset.c cd_comands.c ft_strnstr.c ft_split.c ft_substr.c ft_strdup.c ft_strlcpy.c ft_putstr_fd.c ft_putchar_fd.c \
			    ft_putendl_fd.c signals.c pipe.c mish_utils.c ft_numstr.c mish_dups.c  invalid_exp.c ft_itoa.c dollar_transformation_3.c commands.c say_my_name.c cd_comands2.c \
				mish_utils2.c export2.c ft_isdigit.c exit.c ft_atoi.c save_string.c ft_isspace.c cd_comands3.c cd_invalid_comands.c parser.c dublicate_exit.c export3.c export4.c

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

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(READLINE_FLAGS)
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

re:
	@$(MAKE) fclean
	@$(MAKE) all