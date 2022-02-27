/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_operations_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:30:24 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 16:56:48 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_utils.h"

static t_list	*ft_lst_lastlast(t_list *list)
{
	t_list	*next_node;

	next_node = list->next;
	while (next_node->next)
	{
		list = list->next;
		next_node = list->next;
	}
	return (list);
}

void	silent_rra(t_stack *stack)
{
	t_list	*lastlast_node;
	t_list	*head_node;
	t_list	*last_node;

	if (ft_lstsize(*stack->a) < 2)
		return ;
	lastlast_node = ft_lst_lastlast(*stack->a);
	head_node = *stack->a;
	last_node = lastlast_node->next;
	lastlast_node->next = NULL;
	*stack->a = last_node;
	last_node->next = head_node;
}

void	silent_rrb(t_stack *stack)
{
	t_list	*head_node;
	t_list	*last_node;
	t_list	*lastlast_node;

	if (ft_lstsize(*stack->b) < 2)
		return ;
	lastlast_node = ft_lst_lastlast(*stack->b);
	head_node = *stack->b;
	last_node = lastlast_node->next;
	lastlast_node->next = NULL;
	*stack->b = last_node;
	last_node->next = head_node;
}

void	silent_rrr(t_stack *stack)
{
	t_list	*head_node;
	t_list	*last_node;
	t_list	*lastlast_node;

	if (ft_lstsize(*stack->a) < 2 || ft_lstsize(*stack->b) < 2)
		return ;
	lastlast_node = ft_lst_lastlast(*stack->a);
	head_node = *stack->a;
	last_node = lastlast_node->next;
	lastlast_node->next = NULL;
	*stack->a = last_node;
	last_node->next = head_node;
	lastlast_node = ft_lst_lastlast(*stack->b);
	head_node = *stack->b;
	last_node = lastlast_node->next;
	lastlast_node->next = NULL;
	*stack->b = last_node;
	last_node->next = head_node;
}
