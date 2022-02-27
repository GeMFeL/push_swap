/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:25:59 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 18:55:13 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	ft_two_nums(t_stack *stack)
{
	if (! ft_check_is_sorted(*stack->a))
		sa(stack);
}

static void	ft_tree_nums(t_stack *stack)
{
	int		index_of_max;

	index_of_max = ft_lst_index_of_max(*stack->a);
	if (index_of_max == 2)
		if (! ft_check_is_sorted(*stack->a))
			sa(stack);
	if (index_of_max == 1)
	{
		rra(stack);
		if (! ft_check_is_sorted(*stack->a))
			sa(stack);
	}
	if (index_of_max == 0)
	{
		ra(stack);
		if (! ft_check_is_sorted(*stack->a))
			sa(stack);
	}
}

static void	ft_four_nums(t_stack *stack)
{
	int	index_of_min;

	index_of_min = ft_lst_index_of_min(*stack->a);
	ft_put_to_top_of_stack_a_by_index(stack, index_of_min);
	pb(stack);
	ft_tree_nums(stack);
	pa(stack);
}

static void	ft_five_nums(t_stack *stack)
{
	int	index_of_min;

	index_of_min = ft_lst_index_of_min(*stack->a);
	ft_put_to_top_of_stack_a_by_index(stack, index_of_min);
	pb(stack);
	ft_four_nums(stack);
	pa(stack);
}

void	ft_small_stack(t_stack *stack, int size)
{
	if (size == 2)
		ft_two_nums(stack);
	if (size == 3)
		ft_tree_nums(stack);
	if (size == 4)
		ft_four_nums(stack);
	if (size == 5)
		ft_five_nums(stack);
}
