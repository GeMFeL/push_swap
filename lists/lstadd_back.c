/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:48:22 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/12 10:10:49 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (! *lst)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	while (list->next)
		list = list->next;
	list->next = new;
}
