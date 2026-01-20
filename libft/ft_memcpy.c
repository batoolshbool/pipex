/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:00:26 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/01 10:01:08 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
    char str1[] = "";
    char str2[] = "";

    memcpy(str2, str1, sizeof(str1));

    printf("str2 memcpy: ");
    printf("%s\n",str2);

   ft_memcpy(str2, str1, sizeof(str1));

    printf("str2 ft_memcpy: ");
    printf("%s\n",str2);

    return (0);
}*/
