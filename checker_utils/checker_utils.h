/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:32:12 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 18:40:34 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_UTILS_H
# define CHECKER_UTILS_H

# include "../source/source.h"
#include "../lists/lists.h"
# include "get_next_line.h"


void	silent_sa(t_stack *stack);
void	silent_sb(t_stack *stack);
void	silent_ss(t_stack *stack);
void	silent_pa(t_stack *stack);
void	silent_pb(t_stack *stack);
void	silent_ra(t_stack *stack);
void	silent_rb(t_stack *stack);
void	silent_rr(t_stack *stack);
void	silent_rra(t_stack *stack);
void	silent_rrb(t_stack *stack);
void	silent_rrr(t_stack *stack);



int	ft_strncmp(const char *s1, const char *s2, size_t n);



#endif
