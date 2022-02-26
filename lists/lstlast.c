/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:55:03 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/12 10:10:49 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (! lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
