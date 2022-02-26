/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:16:42 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 13:52:13 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	ft_sort_algorithms(t_stack *stack, int size)
{
	if (size < 6)
	{
		ft_small_stack(stack, size);
		return ;
	}
	else
	{
		ft_longest_increasing_subsequence(stack);
		ft_push_from_b_to_a(stack);
		ft_put_to_top_of_stack_a_by_index(stack, ft_lst_index_of_min(*stack->a));
	}
}
