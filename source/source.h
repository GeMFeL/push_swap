/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:51:01 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 15:52:21 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


# define MALLOC_ERROR "malloc() Error"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	**a;
	t_list	**b;
}			t_stack;


void	ft_putendl_fd(const char *s, int fd);
void	ft_put_error_then_exit(const char *str);
void	ft_perror_then_exit(const char *str);
int		ft_check_is_sorted(t_list *list);
int		ft_max(int num1, int num2);


#endif
