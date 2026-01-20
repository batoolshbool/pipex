/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:52:34 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 13:08:06 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size <= d)
		return (size + s);
	i = d;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (d + s);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int size = 16;
    char buffer[size];
    char buffer2[size];

    strcpy(buffer,first);
    strcpy(buffer2,first);

    int r = strlcat(buffer,last,size);
    int r2 = ft_strlcat(buffer2,last,size);
    printf("strlcat: %d\n\nft_strlcat: %d\n",r, r2);

    return(0);
}*/
