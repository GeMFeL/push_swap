/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:04:49 by jchakir           #+#    #+#             */
/*   Updated: 2022/02/26 14:07:15 by jchakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include "../source/source.h"
# include <stdlib.h>



int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lst_find_min(t_list *list);
int		ft_lst_index_of(t_list *list, int content);
int		ft_lst_index_of_min(t_list *list);
int		ft_lst_index_of_max(t_list *list);


#endif
