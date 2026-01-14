/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:45:49 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 12:41:29 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*#include <stdio.h>
int	main(void)
{
	t_list *n1 = ft_lstnew("Hi");
	t_list *n2 = ft_lstnew("HELLOO");
	
	ft_lstadd_front(&n1, n2);
	printf("%s %s\n", (char *)n2->content, (char *)n2->next->content);
}*/