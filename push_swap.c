/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 20:22:53 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_init_stacks(char **argv)
{
	t_stack	*stack;
	t_list	*new_node;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (! stack)
		ft_perror_then_exit(MALLOC_ERROR);
	stack->a = (t_list **)malloc(sizeof(t_list *) * 2);
	if (! stack->a)
		ft_perror_then_exit(MALLOC_ERROR);
	stack->b = stack->a + 1;
	*stack->a = NULL;
	*stack->b = NULL;
	while (*argv)
	{
		new_node = ft_lstnew(ft_custom_atoi(*argv));
		if (! new_node)
			ft_perror_then_exit(MALLOC_ERROR);
		ft_lstadd_back(stack->a, new_node);
		argv++;
	}
	return (stack);
}

static t_stack	*ft_split_numbers(char *str)
{
	char	**numbers;
	t_stack	*stack;

	numbers = ft_split(str, ' ');
	if (! numbers)
		ft_perror_then_exit(MALLOC_ERROR);
	if (! *numbers)
		ft_put_error_then_exit(ERROR);
	ft_check_valid_args(numbers);
	stack = ft_init_stacks(numbers);
	if (ft_lstsize(*stack->a) < 2)
		ft_put_error_then_exit(ERROR);
	ft_free_2d_pointer(numbers);
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	if (argc == 2)
		stack = ft_split_numbers(argv[1]);
	else
	{
		ft_check_valid_args(argv + 1);
		stack = ft_init_stacks(argv + 1);
	}
	ft_check_is_duplicated(*stack->a);
	if (! ft_check_is_sorted(*stack->a))
		ft_sort_algorithms(stack);
	return (0);
}
