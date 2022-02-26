/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:15:28 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 15:11:45 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_stack *stack)
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
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
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
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
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
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (! *stack->b)
		return ;
	head_node = *stack->b;
	next_node = head_node->next;
	*stack->b = next_node;
	ft_lstadd_front(stack->a, head_node);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_list	*head_node;
	t_list	*next_node;

	if (! *stack->a)
		return ;
	head_node = *stack->a;
	next_node = head_node->next;
	*stack->a = next_node;
	ft_lstadd_front(stack->b, head_node);
	write(1, "pb\n", 3);
}
