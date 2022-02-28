# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 15:30:01 by jchakir           #+#    #+#              #
#    Updated: 2022/02/28 15:48:20 by jchakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
MANDA_NAME = push_swap
BONUS_NAME = checker 


FILES = source/check_is_sorted.c source/errors_and_free.c source/putendl_fd.c source/max.c \
		source/check_duplicated_args.c source/check_valid_args_and_atoi.c source/split.c 
FILES +=  lists/lst_find_min.c lists/lst_index_of.c \
			lists/lstadd_back.c lists/lstadd_front.c lists/lstlast.c \
			lists/lstnew.c lists/lstsize.c lists/lst_index_of_max.c \
			lists/lst_index_of_min.c 

MANDA_FILES = $(FILES)
MANDA_FILES += operations/operations_1.c operations/operations_2.c \
			operations/operations_3.c operations/put_to_top.c \
			operations/put_to_top_in_both.c operations/put_to_top_in_both_utils.c
MANDA_FILES += algorithms/small.c algorithms/algorithms.c algorithms/LIS.c \
				algorithms/LIS_utils.c algorithms/calc_min_instractions.c \
				algorithms/push_from_b_to_a.c 
MANDA_FILES += push_swap.c 

BONUS_FILES = $(FILES)
BONUS_FILES += checker_utils/get_next_line.c checker_utils/get_next_line_utils.c \
				checker_utils/silent_operations_1.c checker_utils/silent_operations_2.c \
				checker_utils/silent_operations_3.c checker_utils/strncmp.c
BONUS_FILES += checker.c 

MANDA_OBJ = $(MANDA_FILES:%.c=%.o)
BONUS_OBG = $(BONUS_FILES:%.c=%.o)

all: $(MANDA_NAME)

$(MANDA_NAME): $(MANDA_OBJ)
	$(CC) $(MANDA_OBJ) -o $(MANDA_NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBG)
	$(CC) $(BONUS_OBG) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(MANDA_OBJ) $(BONUS_OBG)

fclean: clean
	rm -rf $(MANDA_NAME) $(BONUS_NAME)

re: fclean all
