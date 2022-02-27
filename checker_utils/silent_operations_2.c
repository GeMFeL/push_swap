/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:29:55 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 16:40:50 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_utils.h"

void	silent_ra(t_stack *stack)
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
}

void	silent_rb(t_stack *stack)
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
}

void	silent_rr(t_stack *stack)
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
}
