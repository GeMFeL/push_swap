# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 15:30:01 by jchakir           #+#    #+#              #
#    Updated: 2022/02/26 14:03:32 by jchakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

FILES = source/check_is_sorted.c source/errors.c source/putendl_fd.c source/max.c 

FILES += operations/operations_1.c operations/operations_2.c \
			operations/operations_3.c operations/put_to_top.c \
			operations/put_to_top_in_both.c operations/put_to_top_in_both_utils.c

FILES +=  lists/lst_find_min.c lists/lst_index_of.c \
			lists/lstadd_back.c lists/lstadd_front.c lists/lstlast.c \
			lists/lstnew.c lists/lstsize.c lists/lst_index_of_max.c \
			lists/lst_index_of_min.c 


FILES += algorithms/small.c algorithms/algorithms.c algorithms/LIS.c \
			algorithms/calc_min_instractions.c algorithms/push_b_to_a.c 

FILES += check_duplicated_args.c check_valid_args_and_atoi.c push_swap.c 


OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
