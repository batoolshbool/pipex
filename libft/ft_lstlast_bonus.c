/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:41:37 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 12:42:18 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>
int	main(void)
{
	t_list *n1 = ft_lstnew("a");
	t_list *n2 = ft_lstnew("b");
	t_list *n3 = ft_lstnew("c");
	
	n1->next = n2;
	n2->next = n3;
	
	t_list *last = ft_lstlast(n1);
	printf("%s\n", (char *)last->content);
}*/