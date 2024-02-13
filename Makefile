NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
LIBFT   =  ./libft/
LIBFT_A = $(LIBFT)libft.a
SRCS	= main.c lst.c get_integer.c p_swap.c sort.c sort_utils.c p_swap_utils.c lst_utils.c
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
