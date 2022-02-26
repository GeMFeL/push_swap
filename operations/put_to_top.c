/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:39:22 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 13:58:26 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "operations.h"

void	ft_put_element_to_top_of_stack_a(t_stack *stack, int element)
{
	int	size;
	int	index;

	index = ft_lst_index_of(*stack->a, element);
	if (index == -1)
		return ;
	size = ft_lstsize(*stack->a);
	if (index <= size / 2)
		while (index--)
			ra(stack);
	else
		while (index++ != size)
			rra(stack);
}

void	ft_put_to_top_of_stack_a_by_index(t_stack *stack, int index)
{
	int	size;

	size = ft_lstsize(*stack->a);
	if (index >= size)
		return ;
	if (index <= size / 2)
		while (index--)
			ra(stack);
	else
		while (index++ != size)
			rra(stack);
}

void	ft_put_to_top_of_stack_b_by_index(t_stack *stack, int index)
{
	int	size;

	size = ft_lstsize(*stack->b);
	if (index >= size)
		return ;
	if (index <= size / 2)
		while (index--)
			rb(stack);
	else
		while (index++ != size)
			rrb(stack);
}
