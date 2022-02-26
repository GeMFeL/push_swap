/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:25:32 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 12:59:06 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	ft_element_is_between_in_stack_a(t_list *list, int element)
{
	t_list *this_node;
	t_list *next_node;

	if (! list->next)
		return (list->content);
	if (element > list->content && element < list->next->content)
		return (list->next->content);
	this_node = list;
	while (this_node->next)
	{
		next_node = this_node->next;
		if (element > this_node->content && element < next_node->content)
			return (next_node->content);
		this_node = this_node->next;
	}
	if (element > this_node->content && element < list->content)
		return (list->content);
	return (ft_lst_find_min(list));
}

static void	ft_find_best_element(t_stack *stack, int *element_a, int *element_b)
{
	t_list *node_b;
	int		best_element_a;
	int		best_element_b;
	int		min_ins;
	int		total_ins;
	int		element_in_stack_a;

	min_ins = 2147483647;
	node_b = *stack->b;
	while (node_b)
	{
		element_in_stack_a = ft_element_is_between_in_stack_a(*stack->a, node_b->content);
		total_ins = ft_calc_min_instractions(stack, element_in_stack_a, node_b->content);
		if (total_ins < min_ins)
		{
			min_ins = total_ins;
			best_element_a = element_in_stack_a;
			best_element_b = node_b->content;
		}
		node_b = node_b->next;
	}
	*element_a = best_element_a;
	*element_b = best_element_b;
}

void	ft_push_from_b_to_a(t_stack *stack)
{
	int	element_a;
	int	element_b;

	element_a = 0;
	element_b = 0;
	while (*stack->b)
	{
		ft_find_best_element(stack, &element_a, &element_b);
		ft_put_to_top_of_stack_a_and_b(stack, element_a, element_b);
		pa(stack);
	}
}
