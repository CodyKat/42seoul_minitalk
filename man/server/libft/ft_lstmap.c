/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:59:30 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/14 19:37:44 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_node;
	t_list	*cur_node;
	t_list	*new_node;

	start_node = ft_lstnew(f(lst->content));
	if (start_node == 0)
		return (0);
	cur_node = start_node;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == 0)
		{
			ft_lstclear(&start_node, del);
			return (0);
		}
		cur_node->next = new_node;
		cur_node = cur_node->next;
		lst = lst->next;
	}
	return (start_node);
}
