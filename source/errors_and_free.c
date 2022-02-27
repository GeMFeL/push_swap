/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:48:01 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 15:35:12 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

void	ft_put_error_then_exit(const char *str)
{
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	ft_perror_then_exit(const char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void	ft_free_2d_pointer(char *ptr_2D[])
{
	int	i;

	i = 0;
	if (ptr_2D)
	{
		while (ptr_2D[i])
			free(ptr_2D[i++]);
		free(ptr_2D);
	}
}
