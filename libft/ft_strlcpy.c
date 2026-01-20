/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:10:51 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 13:07:42 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

/*#include <bsd/string.h>
#include <stdio.h>

int main (void)
{
	char s[] = "Hello World!";
	char d[] = "meow";
	char d2[] = "meow";
	int r = ft_strlcpy(d, s, 20);
	int r2 = strlcpy(d2, s, 20);
	printf("%d\n%d", r, r2);
}*/
