NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
LIBFT   =  ./libft/
LIBFT_A = $(LIBFT)libft.a
SRCS	= main.c main_utils.c get_integer.c
OBJS	= ${SRCS:.c=.o}

%.o: %.c 
	clang $(CFLAGS) $< -c -o $@ 

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	clang -o $(NAME) $(OBJS) $(LIBFT_A)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
