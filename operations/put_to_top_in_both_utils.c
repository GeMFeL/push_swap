/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_top_in_both_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:07:06 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 19:54:11 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ft_rotate_a_b(t_stack *stack, int index_a, int index_b)
{
	while (index_a && index_b)
	{
		rr(stack);
		index_a--;
		index_b--;
	}
	while (index_a--)
		ra(stack);
	while (index_b--)
		rb(stack);
}

void	ft_reverse_rotate_a_b(t_stack *stack, int index_a, int index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack->a);
	size_b = ft_lstsize(*stack->b);
	while (index_a != size_a && index_b != size_b)
	{
		rrr(stack);
		index_a++;
		index_b++;
	}
	while (index_a++ != size_a)
		rra(stack);
	while (index_b++ != size_b)
		rrb(stack);
}
