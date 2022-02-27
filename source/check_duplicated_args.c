/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicated_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:09:36 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 18:06:28 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

void	ft_check_is_duplicated(t_list *list)
{
	t_list	*next_node;

	while (list)
	{
		next_node = list->next;
		while (next_node)
		{
			if (list->content == next_node->content)
				ft_put_error_then_exit(ERROR);
			next_node = next_node->next;
		}
		list = list->next;
	}
}
