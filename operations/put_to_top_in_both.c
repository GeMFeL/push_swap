/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_top_in_both.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:45:27 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 19:48:55 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	ft_do_min_ins_proximity_a(t_stack *stack, int index_a, int index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack->a);
	size_b = ft_lstsize(*stack->b);
	if (ft_max(index_a, index_b) < index_a + (size_b - index_b))
	{
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a, \
												size_b - index_b))
			ft_rotate_a_b(stack, index_a, index_b);
		else
			ft_reverse_rotate_a_b(stack, index_a, index_b);
	}
	else if (ft_max(size_a - index_a, size_b - index_b) < \
								index_a + (size_b - index_b))
		ft_reverse_rotate_a_b(stack, index_a, index_b);
	else
	{
		ft_put_to_top_of_stack_a_by_index(stack, index_a);
		ft_put_to_top_of_stack_b_by_index(stack, index_b);
	}
}

static void	ft_do_min_ins_proximity_b(t_stack *stack, int index_a, int index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack->a);
	size_b = ft_lstsize(*stack->b);
	if (ft_max(index_a, index_b) < (size_a - index_a) + index_b)
	{
		if (ft_max(index_a, index_b) < ft_max(size_a - index_a, \
											size_b - index_b))
			ft_rotate_a_b(stack, index_a, index_b);
		else
			ft_reverse_rotate_a_b(stack, index_a, index_b);
	}
	else if (ft_max(size_a - index_a, size_b - index_b) < \
								(size_a - index_a) + index_b)
		ft_reverse_rotate_a_b(stack, index_a, index_b);
	else
	{
		ft_put_to_top_of_stack_a_by_index(stack, index_a);
		ft_put_to_top_of_stack_b_by_index(stack, index_b);
	}
}

static void	ft_do_minimum_instactions(t_stack *stack, int index_a, int index_b)
{
	int	proximity_a;
	int	proximity_b;

	proximity_a = ft_lstsize(*stack->a) / 2;
	proximity_b = ft_lstsize(*stack->b) / 2;
	if (index_a <= proximity_a && index_b <= proximity_b)
		ft_rotate_a_b(stack, index_a, index_b);
	else if (index_a > proximity_a && index_b > proximity_b)
		ft_reverse_rotate_a_b(stack, index_a, index_b);
	else if (index_a <= proximity_a)
		ft_do_min_ins_proximity_a(stack, index_a, index_b);
	else
		ft_do_min_ins_proximity_b(stack, index_a, index_b);
}

void	ft_put_to_top_of_stack_a_and_b(t_stack *stack, \
										int content_a, int content_b)
{
	int	index_a;
	int	index_b;

	index_a = ft_lst_index_of(*stack->a, content_a);
	index_b = ft_lst_index_of(*stack->b, content_b);
	if (index_a == -1 || index_b == -1)
		return ;
	ft_do_minimum_instactions(stack, index_a, index_b);
}
