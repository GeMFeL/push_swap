/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:13:23 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 19:29:10 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../source/source.h"
# include "../lists/lists.h"
# include <unistd.h>

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	ft_put_element_to_top_of_stack_a(t_stack *stack, int element);
void	ft_put_to_top_of_stack_a_by_index(t_stack *stack, int index);
void	ft_put_to_top_of_stack_b_by_index(t_stack *stack, int index);
void	ft_rotate_a_b(t_stack *stack, int index_a, int index_b);
void	ft_reverse_rotate_a_b(t_stack *stack, int index_a, int index_b);
void	ft_put_to_top_of_stack_a_and_b(t_stack *stack, \
										int content_a, int content_b);

#endif
