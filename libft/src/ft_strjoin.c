/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:16:10 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/20 13:07:46 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*hi;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	hi = (char *)malloc((len + 1) * sizeof(char));
	if (!hi)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		hi[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		hi[i++] = s2[j++];
	hi[i] = '\0';
	return (hi);
}
/*#include <stdio.h>
int	main(void) {
	const char *s1 = "Hello ";
	const char *s2 = "World";

	char *joined = ft_strjoin(s1, s2);

	if (joined != NULL) {
		printf("%s \n", joined);
		free(joined);
	}
	return (0);
}*/
