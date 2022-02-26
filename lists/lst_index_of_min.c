/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index_of_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:28:52 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/16 18:49:01 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	ft_lst_index_of_min(t_list *list)
{
	int	min;
	int	index;
	int	index_of_min;

	if (! list)
		return (-1);
	index = 0;
	index_of_min = 0;
	min = list->content;
	list = list->next;
	while (list)
	{
		index++;
		if (list->content < min)
		{
			min = list->content;
			index_of_min = index;
		}
		list = list->next;
	}
	return (index_of_min);
}
