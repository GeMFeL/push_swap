/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index_of_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:41:01 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/16 18:50:10 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	ft_lst_index_of_max(t_list *list)
{
	int	max;
	int	index;
	int	index_of_max;

	if (! list)
		return (-1);
	index = 0;
	index_of_max = 0;
	max = list->content;
	list = list->next;
	while (list)
	{
		index++;
		if (list->content > max)
		{
			max = list->content;
			index_of_max = index;
		}
		list = list->next;
	}
	return (index_of_max);
}
