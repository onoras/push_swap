CC = cc
CFLAGS =  -Wall -Wextra -Werror
INCLUDES =	-I. -I./libft
			
NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_converter.c

OFILES = $(SRCS:.c=.o)

LIBFT = /libft/libft.a 

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OFILES)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OFILES)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
