/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:28:18 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/28 13:47:14 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "../source/source.h"
# include "../lists/lists.h"
# include "../operations/operations.h"

void	ft_small_stack(t_stack *stack, int size);
void	ft_longest_increasing_subsequence(t_stack *stack);
int		ft_find_max_in_array(int *array, int size);
int		ft_set_numbers_and_lis(t_stack *stack, int **lis, int **numbers);
int		ft_calc_min_instractions(t_stack *stack, int content_a, int content_b);
void	reverse_rotate_temp(t_stack *stack);
void	rotate_temp(t_stack *stack);
void	ft_push_from_b_to_a(t_stack *stack);
void	ft_sort_algorithms(t_stack *stack);

#endif
