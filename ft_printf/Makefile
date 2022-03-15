NAME = libftprintf.a

LIST = 	ft_isalpha.c	ft_isdigit.c	ft_itoa.c		ft_putstr.c		ft_strdup.c\
		ft_strlen.c		ft_itoabase.c	ft_printf.c		print_pointer.c	print.c\
		specifier.c		print_int.c		ft_memset.c		ft_strncpy.c	ft_calloc.c\
		ft_bzero.c

OBJ = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re