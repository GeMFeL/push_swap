/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:04:49 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 13:29:18 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	ft_set_numbers_and_lis(t_stack *stack, int **lis, int **numbers)
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

static int	ft_find_max_in_array(int *array, int size)
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

static void	ft_put_non_lis_numbers_to_satck_b(t_stack *stack, int *lis, \
											int *numbers, int size)
{
	int	lis_max_index;

	lis_max_index = ft_find_max_in_array(lis, size);
	while (size--)
	{
		if (lis[size] != lis_max_index)
		{
			ft_put_element_to_top_of_stack_a(stack, numbers[size]);
			pb(stack);
		}
		else
			lis_max_index--;
	}
}

void	ft_longest_increasing_subsequence(t_stack *stack)
{
	int	size;
	int	i;
	int	j;
	int	*numbers;
	int	*lis;

	size = ft_set_numbers_and_lis(stack, &lis, &numbers);
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (numbers[i] > numbers[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	ft_put_non_lis_numbers_to_satck_b(stack, lis, numbers, size);
	free(lis);
	free(numbers);
}
