/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:21:19 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 13:45:54 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *stack)
{
	t_list	*head_node;
	t_list	*last_node;

	if (ft_lstsize(*stack->a) < 2)
		return ;
	head_node = *stack->a;
	last_node = ft_lstlast(head_node);
	*stack->a = head_node->next;
	last_node->next = head_node;
	head_node->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	t_list	*head_node;
	t_list	*last_node;

	if (ft_lstsize(*stack->b) < 2)
		return ;
	head_node = *stack->b;
	last_node = ft_lstlast(head_node);
	*stack->b = head_node->next;
	last_node->next = head_node;
	head_node->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	t_list	*head_node;
	t_list	*last_node;

	if (ft_lstsize(*stack->a) < 2 || ft_lstsize(*stack->b) < 2)
		return ;
	head_node = *stack->a;
	last_node = ft_lstlast(head_node);
	*stack->a = head_node->next;
	last_node->next = head_node;
	head_node->next = NULL;

	head_node = *stack->b;
	last_node = ft_lstlast(head_node);
	*stack->b = head_node->next;
	last_node->next = head_node;
	head_node->next = NULL;
	write(1, "rr\n", 3);
}
