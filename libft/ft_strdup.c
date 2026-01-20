/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:37:53 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 13:07:04 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*hi;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	hi = (char *)malloc((len + 1) * sizeof(char));
	if (hi == NULL)
		return (0);
	j = 0;
	while (j <= len)
	{
		hi[j] = s[j];
		j++;
	}
	return (hi);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char src[] = "Hello :)";
	char *dup = ft_strdup(src);
	printf("%s\n", dup);
	char *dup2 = strdup(src);
	printf("%s\n", dup2);
}*/
