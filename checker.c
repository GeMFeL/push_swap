/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:04:41 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/27 17:14:48 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	ft_do_instraction(t_stack *stack, char *str)
{
	if (! ft_strncmp(str, "sa\n", 4))
		silent_sa(stack);
	else if (! ft_strncmp(str, "sb\n", 4))
		silent_sb(stack);
	else if (! ft_strncmp(str, "ss\n", 4))
		silent_ss(stack);
	else if (! ft_strncmp(str, "pa\n", 4))
		silent_pa(stack);
	else if (! ft_strncmp(str, "pb\n", 4))
		silent_pb(stack);
	else if (! ft_strncmp(str, "ra\n", 4))
		silent_ra(stack);
	else if (! ft_strncmp(str, "rb\n", 4))
		silent_rb(stack);
	else if (! ft_strncmp(str, "rr\n", 4))
		silent_rr(stack);
	else if (! ft_strncmp(str, "rra\n", 5))
		silent_rra(stack);
	else if (! ft_strncmp(str, "rrb\n", 5))
		silent_rrb(stack);
	else if (! ft_strncmp(str, "rrr\n", 5))
		silent_rrr(stack);
	else
		return (0);
	return (1);
}

static void	ft_follow_instactions(t_stack *stack)
{
	char	*instaction;

	while (1)
	{
		instaction = get_next_line(0);
		if (! instaction)
			return ;
		if (! ft_do_instraction(stack, instaction))
			ft_put_error_then_exit(ERROR);
		free(instaction);
	}
}

static t_stack *ft_split_numbers(char *str)
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

int main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
		ft_put_error_then_exit(ERROR);
	if (argc == 2)
		stack = ft_split_numbers(argv[1]);
	else
	{
		ft_check_valid_args(argv + 1);
		stack = ft_init_stacks(argv + 1);
	}
	if (ft_check_is_sorted(*stack->a))
		ft_put_error_then_exit(ERROR);
	ft_check_is_duplicated(*stack->a);
	ft_follow_instactions(stack);
	if (ft_check_is_sorted(*stack->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
