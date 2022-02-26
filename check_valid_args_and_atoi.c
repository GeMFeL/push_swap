/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_args_and_atoi.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:48:51 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/13 11:53:11 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_custom_atoi(const char *str)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	if (*str == '-' || *str  == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str) && res < 2147483648)
		res = res * 10 + *str++ - 48;
	if (res > 2147483647 && sign == 1)
		ft_put_error_then_exit(INVALID_INT_ARG);
	if (res > 2147483648 && sign == -1)
		ft_put_error_then_exit(INVALID_INT_ARG);
	return (sign * (int)res);
}

static int	ft_is_a_integer(const char *str)
{
	if (! *str)
		return (0);
	else if (ft_isdigit(*str))
		str++;
	else if ((*str == '-' || *str  == '+') && *(str + 1))
		str++;
	else
		return (0);
	while (*str)
	{
		if (! ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_check_valid_args(const char **argv)
{
	while (*argv)
	{
		if (! ft_is_a_integer(*argv))
			ft_put_error_then_exit(INVALID_INT_ARG);
		argv++;
	}
}
