CC = cc
CFLAGS =  -Wall -Wextra -Werror
INCLUDES =	-I. -I./printf
			
NAME = push_swap

SRCS =	push_swap.c \
		push_swap_utils.c \
		parser.c \
		validate_args.c

OFILES = $(SRCS:.c=.o)

PRINTF = printf/printf.a 

all: $(PRINTF) $(NAME)

$(PRINTF):
	$(MAKE) -C ./printf

$(NAME): $(OFILES)
	$(CC) $(OFILES) printf/libftprintf.a -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
