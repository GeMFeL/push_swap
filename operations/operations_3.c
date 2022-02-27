/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:25:03 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 19:31:46 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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

void	rra(t_stack *stack)
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
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
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
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
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
	write(1, "rrr\n", 4);
}
