# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 12:38:33 by nel-baz           #+#    #+#              #
#    Updated: 2023/03/15 07:41:36 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = 	src/check_args.c\
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
		src/sort_small_num.c\
		src/push_swap_utils.c

SRCS_BONUS =	bonus/bonus_utils.c\
				bonus/get_list.c\
				bonus/main.c\
				bonus/push.c\
				bonus/push_args_to_a.c\
				bonus/rev_rotate.c\
				bonus/rotate.c\
				bonus/swap.c\
				bonus/check_args.c\
				bonus/bonus_utils2.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

src/%.o: src/%.c src/push_swap.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/push_swap_bonus.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

all : libft $(NAME)

libft :
	make -C libft  all	

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(NAME_B):  $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) ./libft/libft.a -o $(NAME_B)
	
bonus : all $(NAME_B)

clean:	
	rm -rf $(OBJS) $(OBJS_BONUS)
	make -C libft/ clean

fclean:	clean
	rm -rf $(NAME) $(NAME_B)
	make -C libft/ fclean

re : fclean all

.PHONY : all fclean clean re libft
