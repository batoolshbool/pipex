/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:05:27 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/06 13:24:35 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
//     char str[50] = "hello";
//     printf("\nBefore memset(): %s\n", str); 
//     memset(str, 'A', 8*sizeof(char));
//     printf("After memset():  %s\n", str); 
//     ft_memset(str, 'A', 8*sizeof(char));
//     printf("After ft_memset():  %s\n", str);
//     return (0);
// }
