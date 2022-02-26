/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:26 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 13:33:06 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stacks(char const **argv)
{
	t_stack	*stack;
	t_list	*new_node;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (! stack)
		ft_perror_then_exit(MALLOC_ERROR);
	stack->a = (t_list **)malloc(sizeof(t_list *) * 3);
	if (! stack->a)
		ft_perror_then_exit(MALLOC_ERROR);
	stack->b = stack->a + 1;
	stack->temp = stack->a + 2;
	*stack->a = NULL;
	*stack->b = NULL;
	*stack->temp = NULL;
	while (*argv)
	{
		new_node = ft_lstnew(ft_custom_atoi(*argv));
		if (! new_node)
			ft_put_error_then_exit(MALLOC_ERROR);
		ft_lstadd_back(stack->a, new_node);
		argv++;
	}
	return (stack);
}

void ft_print_num(int num)
{
	printf("%d ", num);
}

int main(int argc, char const *argv[])
{
	t_stack	*stack;

	if (argc < 3)
		ft_put_error_then_exit(INVALID_ARGS);
	ft_check_valid_args(argv + 1);
	stack = ft_init_stacks(argv + 1);
	ft_check_is_duplicated(*stack->a);
	if (ft_check_is_sorted(*stack->a))
		ft_put_error_then_exit(ARGS_IS_SORTED);

	ft_sort_algorithms(stack, argc - 1);

	// if (ft_check_is_sorted(*stack->a))
	// 	printf("is sorted\n");
	// else
	// 	printf("not sorted\n");


	// system("leaks push_swap");
	return 0;
}
