/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:54:06 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/20 13:07:25 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*hi;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		return (ft_strdup(""));
	}
	if (len > slen - start)
		len = slen - start;
	hi = (char *)malloc(sizeof(char) * (len + 1));
	if (!hi)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		hi[i] = s[start + i];
		i++;
	}
	hi[i] = '\0';
	return (hi);
}

/*#include <stdio.h>
int	main(void)
{
    char *a = ft_substr("ABCDEF", 2, 3);
    printf("%s\n", a);
}*/
