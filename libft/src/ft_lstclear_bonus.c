/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:32:36 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 12:41:15 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*var;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		var = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = var;
	}
}
//#include <stdio.h>

//int main(void)
//{
//	t_list *list = NULL;
//	list = ft_lstnew(ft_strdup("hi"));
//	list->next = ft_lstnew(ft_strdup("hello"));
//	list->next->next = ft_lstnew(ft_strdup("world"));

//	printf("%s\n", (char*)list->content);

//	ft_lstclear(&list, free);
//}