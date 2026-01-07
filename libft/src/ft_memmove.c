/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:31:59 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/01 10:01:14 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dest;
	if (d > s)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
    char str1[] = "HELLO!!!!!";
    char str2[] = "hihihihi";
    char str3[] = "hihihihi";

    memmove(str2, str1, 3);

    printf("memmove: ");
    printf("%s\n",str2);

   ft_memmove(str3, str1, 3);

    printf("ft_memmove: ");
    printf("%s\n",str2);

    return (0);
}*/
