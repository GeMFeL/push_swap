/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_index_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:13:49 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 19:00:00 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	ft_lst_index_of(t_list *list, int content)
{
	int	index;

	index = 0;
	while (list)
	{
		if (list->content == content)
			return (index);
		index++;
		list = list->next;
	}
	return (-1);
}
