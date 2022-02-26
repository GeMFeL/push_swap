/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:01:25 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/16 15:07:34 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	ft_lst_find_min(t_list *list)
{
	int	min;

	if (! list)
		return (-2147483648);
	min = list->content;
	list = list->next;
	while (list)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	return (min);
}
