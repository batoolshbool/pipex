/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:27:15 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 12:41:21 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *hi = NULL;
// 	t_list *n1 = ft_lstnew("Hi");
// 	t_list *n2 = ft_lstnew("HELLOO");
// 	ft_lstadd_back(&hi, n1);
// 	ft_lstadd_back(&hi, n2);
// 	t_list *hello = hi;
// 	while (hello)
// 	{
// 		printf("%s", (char*)hello->content);
// 		hello = hello->next;
// 	}
// }