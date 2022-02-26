/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:48:01 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 14:08:14 by jchakir          ###   ########.fr       */
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
