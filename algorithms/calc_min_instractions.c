/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_min_instractions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:55:38 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 14:19:31 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	ft_calc_min_ins_proximity_a(int index_a, int index_b, int size_a, int size_b)
{
	if (ft_max(index_a, index_b) < index_a + (size_b - index_b))
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a, size_b - index_b))
			return ft_max(index_a, index_b);
		else
			return ft_max(size_a - index_a, size_b - index_b);
	else if (ft_max(size_a - index_a, size_b - index_b) < index_a + (size_b - index_b))
			return ft_max(size_a - index_a, size_b - index_b);
	return (index_a + (size_b - index_b));
}

static int	ft_calc_min_ins_proximity_b(int index_a, int index_b, int size_a, int size_b)
{
	if (ft_max(index_a, index_b) < index_b + (size_a - index_a))
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a, size_b - index_b))
			return ft_max(index_a, index_b);
		else
			return ft_max(size_a - index_a, size_b - index_b);
	else if (ft_max(size_a - index_a, size_b - index_b) < index_b + (size_a - index_a))
			return ft_max(size_a - index_a, size_b - index_b);
	return (index_b + (size_a - index_a));
}

static int	ft_calc_minimum_instactions(int index_a, int index_b, int size_a, int size_b)
{
	int	proximity_a;
	int	proximity_b;

	proximity_a = size_a / 2;
	proximity_b = size_b / 2;
	if (index_a <= proximity_a && index_b <= proximity_b)
			return ft_max(index_a, index_b);
	else if (index_a > proximity_a && index_b > proximity_b)
			return ft_max(size_a - index_a, size_b - index_b);
	else if (index_a <= proximity_a)
		return ft_calc_min_ins_proximity_a(index_a, index_b, size_a, size_b);
	return ft_calc_min_ins_proximity_b(index_a, index_b, size_a, size_b);
}

int	ft_calc_min_instractions(t_stack *stack, int content_a, int content_b)
{
	int	size_a;
	int	size_b;
	int	index_a;
	int	index_b;

	index_a = ft_lst_index_of(*stack->a, content_a);
	index_b = ft_lst_index_of(*stack->b, content_b);
	if (index_a == -1 || index_b == -1)
		return (2147483647);
	size_a = ft_lstsize(*stack->a);
	size_b = ft_lstsize(*stack->b);
	return ft_calc_minimum_instactions(index_a, index_b, size_a, size_b);
}
