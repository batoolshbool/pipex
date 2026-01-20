/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:10:02 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/07 09:03:35 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*cont;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		cont = f(lst->content);
		temp = ft_lstnew(cont);
		if (!temp)
		{
			del(cont);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

// void del(void *cont)
// {
// 	free(cont);
// }
// void *function(void *cont)
// {
// 	return (ft_strdup((char *)cont));
// }
// #include <stdio.h>
// int main(void)
// {
// 	t_list *hi = ft_lstnew(ft_strdup("hiii"));
// 	t_list *helo = ft_lstmap(hi,&function,&del);
// 	printf("%s\n",(char *)helo->content);
// }
