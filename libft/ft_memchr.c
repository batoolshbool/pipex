/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:25:19 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 12:50:44 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char hi[] = { 'a', 'b', 'c', 'd', 'e'};
	char *res = memchr (hi, 'c', 5);
	char *res2 = ft_memchr (hi, 'c', 5);

	if (res != NULL)
		printf ("found 'c'\n");
	else
		printf("'c' not found\n");
        if (res2 != NULL)
                printf ("found 'c'\n");
        else
                printf("'c' not found\n");
}*/
