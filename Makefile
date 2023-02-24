# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 12:38:33 by nel-baz           #+#    #+#              #
#    Updated: 2023/02/24 16:46:21 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = check_args.c\
get_duplist.c\
get_duplist_utils.c\
get_lis.c\
get_list.c\
push.c\
push_args_to_a.c\
push_swap.c\
push_to_b.c\
rev_rotate.c\
rotate.c\
swap.c\
position.c\
position_utils.c\
indexs.c\
best_move.c\
best_move_utils.c\
mid_value.c\
sort_small_num.c\
push_swap_utils.c 

OBJS = $(SRCS:.c=.o)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

libft/libft.a :
	make -C libft all bonus

$(NAME):	libft/libft.a  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:	
		rm -rf $(OBJS)
		make -C libft clean

fclean:	clean
		rm -rf $(NAME)
		make -C libft fclean
		
re : fclean all

.PHONY : all fclean clean re
