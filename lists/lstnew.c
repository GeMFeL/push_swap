/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:59:31 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/12 18:44:05 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (! list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
