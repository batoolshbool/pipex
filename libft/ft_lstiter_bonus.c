/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:10:25 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 12:42:14 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
//
// static void print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }
//
// int main(void)
// {
// 	char *str1 = "10";
// 	char *str2 = "20";
// 	char *str3 = "30";
// 	t_list *n = ft_lstnew((void *)str1);
// 	n->next = ft_lstnew((void *)str2);
// 	n->next->next = ft_lstnew((void *)str3);
//
// 	ft_lstiter(n, print_content);
// }