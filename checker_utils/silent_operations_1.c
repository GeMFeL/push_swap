/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:29:24 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 16:39:28 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_utils.h"

void	silent_sa(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (ft_lstsize(*stack->a) < 2)
		return ;
	head_node = *stack->a;
	next_node = head_node->next;
	*stack->a = next_node;
	head_node->next = next_node->next;
	next_node->next = head_node;
}

void	silent_sb(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (ft_lstsize(*stack->b) < 2)
		return ;
	head_node = *stack->b;
	next_node = head_node->next;
	*stack->b = next_node;
	head_node->next = next_node->next;
	next_node->next = head_node;
}

void	silent_ss(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (ft_lstsize(*stack->a) < 2 || ft_lstsize(*stack->b) < 2)
		return ;
	head_node = *stack->a;
	next_node = head_node->next;
	*stack->a = next_node;
	head_node->next = next_node->next;
	next_node->next = head_node;
	head_node = *stack->b;
	next_node = head_node->next;
	*stack->b = next_node;
	head_node->next = next_node->next;
	next_node->next = head_node;
}

void	silent_pa(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (! *stack->b)
		return ;
	head_node = *stack->b;
	next_node = head_node->next;
	*stack->b = next_node;
	ft_lstadd_front(stack->a, head_node);
}

void	silent_pb(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (! *stack->a)
		return ;
	head_node = *stack->a;
	next_node = head_node->next;
	*stack->a = next_node;
	ft_lstadd_front(stack->b, head_node);
}
