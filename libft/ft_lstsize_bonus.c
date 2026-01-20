/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:08:06 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 12:43:09 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	n1 = ft_lstnew("hi");
	n2 = ft_lstnew("hello");
	n3 = ft_lstnew("meow");
	
	if (n1 && n2 && n3)
	{
		n1->next = n2;
		n2->next = n3;
		n3->next = NULL;
		
		printf("size : %d\n", ft_lstsize(n1));
	}
	else
		printf("failed\n");
}*/