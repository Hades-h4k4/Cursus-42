/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:36:21 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/20 17:34:16 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_loop(t_list *lst, void *(*f)(void *), void (*del)(void *),
		t_list **new_lst)
{
	t_list	*new_node;
	void	*new_content;

	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(new_lst, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(new_lst, new_node);
		lst = lst->next;
	}
	return (*new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	return (ft_lstmap_loop(lst, f, del, &new_lst));
}
