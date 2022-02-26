/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:08:59 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/15 18:15:51 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

int	ft_check_is_sorted(t_list *list)
{
	t_list *next;

	if (! list)
		return (0);
	next = list->next;
	while (next)
	{
		if (list->content > next->content)
			return (0);
		list = next;
		next = list->next;
	}
	return (1);
}
