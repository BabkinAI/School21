NAME = test.a

LIST = 	test2.c

OBJ = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit libmlx.dylib -o $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -Imlx -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re