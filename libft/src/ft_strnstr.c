/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:24:50 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 16:54:02 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] != '\0' && (i + j) < len
			&& big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char *s1 = "hi hello world";
	char *s2 = "hello";
	
	char *i1 = strnstr(s1, s2, 14);
	char *i2 = ft_strnstr(s1, s2, 14);

	printf("strnstr: %s\nft_strnstr: %s\n", i1, i2);
	return (0);
}*/
