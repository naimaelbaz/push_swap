# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 12:38:33 by nel-baz           #+#    #+#              #
#    Updated: 2023/02/25 11:41:03 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	src/check_args.c\
		src/get_duplist.c\
		src/get_duplist_utils.c\
		src/get_lis.c\
		src/get_list.c\
		src/push.c\
		src/push_args_to_a.c\
		src/push_swap.c\
		src/push_to_b.c\
		src/rev_rotate.c\
		src/rotate.c\
		src/swap.c\
		src/position.c\
		src/position_utils.c\
		src/indexs.c\
		src/best_move.c\
		src/best_move_utils.c\
		src/mid_value.c\
		src/sort_small_num.c\
		src/push_swap_utils.c 

OBJS = $(SRCS:.c=.o)

src/%.o: src/%.c src/push_swap.h ../libft/libft.h
	$(CC) $(FLAGS) -c $< -o $@

all : libft $(NAME)

libft :
	make -C libft  all

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean:	
	rm -rf $(OBJS)
	make -C libft/ clean

fclean:	clean
	rm -rf $(NAME)
	make -C libft/ fclean
		
re : fclean all

.PHONY : all fclean clean re libft
