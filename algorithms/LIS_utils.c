/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:52:50 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/28 13:47:29 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	ft_set_numbers_and_lis(t_stack *stack, int **lis, int **numbers)
{
	t_list	*list;
	int		i;
	int		*_numbers;
	int		*_lis;
	int		size;

	size = ft_lstsize(*stack->a);
	_numbers = (int *)malloc(size * sizeof(int));
	_lis = (int *)malloc(size * sizeof(int));
	if (! _numbers || ! _lis)
		ft_perror_then_exit(MALLOC_ERROR);
	i = 0;
	list = *stack->a;
	while (i < size)
	{
		_numbers[i] = list->content;
		_lis[i] = 1;
		list = list->next;
		i++;
	}
	*numbers = _numbers;
	*lis = _lis;
	return (size);
}

int	ft_find_max_in_array(int *array, int size)
{
	int	max;
	int	i;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (max < array[i])
			max = array[i];
		i++;
	}
	return (max);
}
