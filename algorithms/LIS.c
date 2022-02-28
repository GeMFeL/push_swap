/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:04:49 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/28 15:23:36 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	*ft_set_just_lis_numbers(int *lis, int *numbers, \
										int size, int lis_max_index)
{
	int	*just_lis_numbers;

	just_lis_numbers = (int *)malloc(sizeof(int) * lis_max_index);
	if (! just_lis_numbers)
		ft_perror_then_exit(MALLOC_ERROR);
	while (size--)
	{
		if (lis[size] == lis_max_index)
		{
			lis_max_index--;
			just_lis_numbers[lis_max_index] = numbers[size];
		}
	}
	return (just_lis_numbers);
}

static int	ft_is_number_in_array(int array[], int size, int number)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_put_non_lis_numbers_to_satck_b(t_stack *stack, int *lis, \
											int *numbers, int size)
{
	t_list	*head_node;
	int		lis_size;
	int		*just_lis_numbers;

	lis_size = ft_find_max_in_array(lis, size);
	just_lis_numbers = ft_set_just_lis_numbers(lis, numbers, size, lis_size);
	while (size--)
	{
		head_node = *stack->a;
		if (ft_is_number_in_array(just_lis_numbers, \
									lis_size, head_node->content))
			ra(stack);
		else
			pb(stack);
	}
	free(just_lis_numbers);
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
