/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:32:40 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/16 15:58:08 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "source/source.h"
# include "lists/lists.h"
# include "operations/operations.h"
# include "algorithms/algorithms.h"


# define INVALID_INT_ARG "Error: Invalid Integer Argument"
# define INVALID_ARGS "Error: Invalid Arguments"
# define ARGS_IS_SORTED "Error: Numbers is already sorted"
# define DUPLICATED_NUMBER "Error: Found Duplicated Number"


int		ft_custom_atoi(const char *str);
void	ft_check_valid_args(const char **argv);
void	ft_check_is_duplicated(t_list *list);


#endif
