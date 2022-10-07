NAME		= pushswap.a
APP			= push_swap
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC	= $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME) run

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

run:
	@$(CC) -o $(APP) $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME) $(APP)

re:	fclean all

.PHONY:	all clean fclean re run
